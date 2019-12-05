#include "./include/fsapi.h"
#include "./include/dyndata.h"






FAST_MUTEX CFsFilterAttachLock;

ULONG SfDebug = 0;



DRIVER_INITIALIZE DriverEntry;
DRIVER_UNLOAD DriverUnload;
_Dispatch_type_(IRP_MJ_CREATE) DRIVER_DISPATCH CFsDispatchCreate;
_Dispatch_type_(IRP_MJ_CLOSE) DRIVER_DISPATCH CFsDispatchClose;
_Dispatch_type_(IRP_MJ_DEVICE_CONTROL) DRIVER_DISPATCH
										CFsDispatchDeviceControl;
_Dispatch_type_(IRP_MJ_CLEANUP)
_Dispatch_type_(IRP_MJ_FILE_SYSTEM_CONTROL)
_Dispatch_type_(IRP_MJ_FLUSH_BUFFERS)
_Dispatch_type_(IRP_MJ_INTERNAL_DEVICE_CONTROL)
_Dispatch_type_(IRP_MJ_PNP)
_Dispatch_type_(IRP_MJ_POWER)
_Dispatch_type_(IRP_MJ_QUERY_INFORMATION)
_Dispatch_type_(IRP_MJ_READ)
_Dispatch_type_(IRP_MJ_SET_INFORMATION)
_Dispatch_type_(IRP_MJ_SHUTDOWN)
_Dispatch_type_(IRP_MJ_SYSTEM_CONTROL)
_Dispatch_type_(IRP_MJ_WRITE)
DRIVER_DISPATCH CFsPassThrough;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, DriverEntry)
#pragma alloc_text(PAGE, DriverUnload)
#endif


NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
	_Unreferenced_parameter_(RegistryPath);
	NTSTATUS status;
	UNICODE_STRING deviceName;
	UNICODE_STRING symbolicName;
	PDEVICE_OBJECT deviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;
	ULONG i;

#if WINVER >= 0X0501

	CFsLoadDynamicFunctions();

	CFsGetCurrentVersion();
#endif

	CFsReadDriverParameters(RegistryPath);

	CFsDriverObject = DriverObject;

	ExInitializeFastMutex(&CFsFilterAttachLock);

	RtlInitUnicodeString(&deviceName, CFS_DEVICE_NAME);

	status = IoCreateDevice(
		DriverObject,
		0,
		&deviceName,
		FILE_DEVICE_UNKNOWN,
		FILE_DEVICE_SECURE_OPEN,
		FALSE,
		&deviceObject
	);

	if (!NT_SUCCESS(status))
		return status;

	CFsDeviceObject = deviceObject;

	RtlInitUnicodeString(&symbolicName, L"\\??\\cryptofilter");
	status = IoCreateSymbolicLink(&symbolicName, &deviceName);

	if (!NT_SUCCESS(status)) {
		KdPrint(("create symblock failed %wZ, %08x\n",
			symbolicName, status));
		IoDeleteDevice(DriverObject->DeviceObject);
		return status;
	}

	for (i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++) {
		DriverObject->MajorFunction[i] = CFsPassThrough;
	}

	// Set up I/O.
	DriverObject->MajorFunction[IRP_MJ_CREATE] = CFsDispatchCreate;
	//DriverObject->MajorFunction[IRP_MJ_CLOSE] = CFsDispatchClose;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] =
		CFsDispatchDeviceControl;
	DriverObject->DriverUnload = DriverUnload;

	fastIoDispatch = ExAllocatePoolWithTag(
				NonPagedPool,
				sizeof(FAST_IO_DISPATCH),
				CFS_POOL_TAG);
	if (!fastIoDispatch) {
		IoDeleteDevice(CFsDeviceObject);
		return STATUS_INSUFFICIENT_RESOURCES;
	}

	RtlZeroMemory(fastIoDispatch, sizeof(FAST_IO_DISPATCH));

	fastIoDispatch->SizeOfFastIoDispatch = sizeof(FAST_IO_DISPATCH);
	fastIoDispatch->FastIoCheckIfPossible = SfFastIoCheckIfPossible;
	fastIoDispatch->FastIoRead = SfFastIoRead;
	fastIoDispatch->FastIoWrite = SfFastIoWrite;
	fastIoDispatch->FastIoQueryBasicInfo = SfFastIoQueryBasicInfo;
	fastIoDispatch->FastIoQueryStandardInfo =
		SfFastIoQueryStandardInfo;
	fastIoDispatch->FastIoLock = SfFastIoLock;
	fastIoDispatch->FastIoUnlockSingle = SfFastIoUnlockSingle;
	fastIoDispatch->FastIoUnlockAll = SfFastIoUnlockAll;
	fastIoDispatch->FastIoUnlockAllByKey = SfFastIoUnlockAllByKey;
	fastIoDispatch->FastIoDeviceControl = SfFastIoDeviceControl;
	fastIoDispatch->FastIoDetachDevice = SfFastIoDetachDevice;
	fastIoDispatch->FastIoQueryNetworkOpenInfo =
		SfFastIoQueryNetworkOpenInfo;
	fastIoDispatch->MdlRead = SfFastIoMdlRead;
	fastIoDispatch->MdlReadComplete = SfFastIoMdlReadComplete;
	fastIoDispatch->PrepareMdlWrite = SfFastIoPrepareMdlWrite;
	fastIoDispatch->MdlWriteComplete = SfFastIoMdlWriteComplete;
	fastIoDispatch->FastIoReadCompressed = SfFastIoReadCompressed;
	fastIoDispatch->FastIoWriteCompressed = SfFastIoWriteCompressed;
	fastIoDispatch->MdlReadCompleteCompressed = 
		SfFastIoMdlReadCompleteCompressed;
	fastIoDispatch->MdlWriteCompleteCompressed =
		SfFastIoMdlWriteCompleteCompressed;
	fastIoDispatch->FastIoQueryOpen = SfFastIoQueryOpen;
	
	DriverObject->FastIoDispatch = fastIoDispatch;

#if WINVER >= 0x0501
	FS_FILTER_CALLBACKS CFsFilterCallbacks;

	if (NULL != CFsDynamicFunctions.RegisterFileSystemFilterCallbacks) {
		CFsFilterCallbacks.SizeOfFsFilterCallbacks =
			sizeof(FS_FILTER_CALLBACKS);
		CFsFilterCallbacks.PreAcquireForSectionSynchronization =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostAcquireForSectionSynchronization =
			CFsPostFsFilterPassThrough;
		CFsFilterCallbacks.PreReleaseForSectionSynchronization =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostReleaseForSectionSynchronization =
			CFsPostFsFilterPassThrough;
		CFsFilterCallbacks.PreAcquireForCcFlush =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostAcquireForCcFlush =
			CFsPostFsFilterPassThrough;
		CFsFilterCallbacks.PreReleaseForCcFlush =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostReleaseForCcFlush =
			CFsPostFsFilterPassThrough;
		CFsFilterCallbacks.PreAcquireForModifiedPageWriter =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostAcquireForModifiedPageWriter =
			CFsPostFsFilterPassThrough;
		CFsFilterCallbacks.PreReleaseForModifiedPageWriter =
			CFsPreFsFilterPassThrough;
		CFsFilterCallbacks.PostReleaseForModifiedPageWriter =
			CFsPostFsFilterPassThrough;

		status = (CFsDynamicFunctions.
					RegisterFileSystemFilterCallbacks)
			(DriverObject,
			&CFsFilterCallbacks);
		if (!NT_SUCCESS(status)) {
			DriverObject->FastIoDispatch = NULL;
			ExFreePool(fastIoDispatch);
			IoDeleteDevice(CFsDeviceObject);
			return status;
		}
	}
#endif
	status = IoRegisterFsRegistrationChange(DriverObject,
						SfFsNotification
						);
	if (!NT_SUCCESS(status)) {
		KdPrint(("SFilter!DriverEntry: Error registering FS"
					" change notification, status="
					"%08x\n", status));
		DriverObject->FastIoDispatch = NULL;
		ExFreePool(fastIoDispatch);
		IoDeleteDevice(CFsDeviceObject);
		return status;
	}

	PDEVICE_OBJECT rawDeviceObject;
	PFILE_OBJECT fileObject;
	UNICODE_STRING rawNameString;

	RtlInitUnicodeString(&rawNameString,
			     L"\\Device\\RawDisk");

	status = IoGetDeviceObjectPointer(
			&rawNameString,
			FILE_READ_ATTRIBUTES,
			&fileObject,
			&rawDeviceObject
			);
	if (NT_SUCCESS(status)) {
		SfFsNotification(rawDeviceObject, TRUE);
		ObDereferenceObject(fileObject);
	}

	RtlInitUnicodeString(&rawNameString,
			     L"\\Device\\RawCdRom");

	status = IoGetDeviceObjectPointer(
			&rawNameString,
			FILE_READ_ATTRIBUTES,
			&fileObject,
			&rawDeviceObject
			);

	if (NT_SUCCESS(status)) {
		SfFsNotification(rawDeviceObject, TRUE);
		ObDereferenceObject(fileObject);
	}

	//deviceObject->Flags &= ~DO_DEVICE_INITIALIZING;
	ClearFlag(deviceObject->Flags, DO_DEVICE_INITIALIZING);

	KdPrint(("Driver loaded\n"));

	return status;
}

VOID DriverUnload(
	_In_ PDRIVER_OBJECT DriverObject
)
{
	_Unreferenced_parameter_(DriverObject);
	PAGED_CODE();

	IoDeleteDevice(CFsDeviceObject);

	KdPrint(("Driver unloaded\n"));
}

NTSTATUS CFsDispatchCreate(
	_In_ PDEVICE_OBJECT DeviceObject,
	_Inout_ PIRP Irp
)
{
	_Unreferenced_parameter_(DeviceObject);
	NTSTATUS status = STATUS_SUCCESS;
	PIO_STACK_LOCATION stackLocation;
	PFILE_OBJECT fileObject;
	PIO_SECURITY_CONTEXT securityContext;
	//PKPH_CLIENT client;

	stackLocation = IoGetCurrentIrpStackLocation(Irp);
	fileObject = stackLocation->FileObject;
	securityContext = stackLocation->Parameters.Create.SecurityContext;

	return status;
}
