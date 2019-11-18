#include <ntifs.h>
#include <ntdddisk.h>
#include <wdmsec.h>
//#include <wdm.h>

#define SFLT_POOL_TAG "tlFS"
PDRIVER_OBJECT gSFilterDriverObject;
PDEVICE_OBJECT gSFilterControlDeviceObject;

NTSTATUS
DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
	PFAST_IO_DISPATCH fastIoDispatch;
	NTSTATUS status = STATUS_SUCCESS;
	UNICODE_STRING symblicName;
	RtlInitUnicodeString(&symblicName,
		L"\\DosDevices");
	UNICODE_STRING nameString;
	RtlInitUnicodeString(&nameString,
		L"\\FileSystem\\Filters\\SFilter");

	gSFilterDriverObject = DriverObject;

	gSFilterDriverObject->DriverUnload = DriverUnload;

	status = IoCreateDevice(DriverObject,
		0,
		&nameString,
		FILE_DEVICE_DISK_FILE_SYSTEM,
		FILE_DEVICE_SECURE_OPEN,
		FALSE,
		&gSFilterControlDeviceObject);
	if (!NT_SUCCESS(status))
	{
		KdPrint(("SFilter DriverEntry: Error creating "
			"control device object \"%wZ\", "
			"status=%08x\n", &nameString, status));
	}

	status = IoCreateSymbolicLink(&symblicName, &nameString);
	if (!NT_SUCCESS(status))
	{
		KdPrint(("SFilter DriverEntry: Error creating syblnk object"
			" \"%wZ\", status=%08x\n", &))
	}

	fastIoDispatch = ExAllocatePoolWithTag(
		NonPagedPool,
		sizeof(FAST_IO_DISPATCH),
		SFLT_POOL_TAG);
	if (!fastIoDispatch)
	{
		IoDeleteDevice(gSFilterControlDeviceObject);
		return STATUS_INSUFFICIENT_RESOURCES;
	}

	RtlZeroMemory(fastIoDispatch, sizeof(FAST_IO_DISPATCH));
	fastIoDispatch->SizeOfFastIoDispatch = sizeof(FAST_IO_DISPATCH);


	fastIoDispatch->FastIoCheckIfPossible = SfFastIoCheckIfPossible;
	fastIoDispatch->FastIoRead = SfFastIoRead;
	fastIoDispatch->FastIoWrite = SfFastIoWrite;
	fastIoDispatch->FastIoQueryBasicInfo = SfFastIoQueryBasicInfo;
	fastIoDispatch->FastIoQueryStandardInfo = SfFastIoQueryStandardInfo;
	fastIoDispatch->FastIoLock = SfFastIolock;
	fastIoDispatch->FastIoUnlockSingle = SfFastIoUnlockSingle;
	fastIoDispatch->FastIoUnlockAll = SfFastIoUnlockAll;
	fastIoDispatch->FastIoUnlockAllByKey = SfFastIoUnlockAllByKey;
	fastIoDispatch->FastIoDeviceControl = SfFastIoDeviceControl;
	fastIoDispatch->FastIoDetachDevice = SfFastIoDetachDevice;
	fastIoDispatch->FastIoQueryNetworkOpenInfo = SfFastIoQueryNetworkOpenInfo;
	fastIoDispatch->MdlRead = SfFastIoMdlRead;
	fastIoDispatch->MdlReadComplete = SfFastIoMdlReadComplete;
	fastIoDispatch->PrepareMdlWrite = SfFastIoPrepareMdlWrite;
	fastIoDispatch->MdlWriteComplete = SfFastIoMdlWriteComplete;
	fastIoDispatch->FastIoReadCompressed = SfFastIoReadCompressed;
	fastIoDispatch->FastIoWriteCompressed = SfFAstIoWriteCompressed;
	fastIoDispatch->MdlReadCompleteCompressed = SfFAstIoMdlReadCompleteCompressed;
	fastIoDispatch->MdlWriteCompleteCompressed = SfFastIoMdlWriteCompleteCompressed;
	fastIoDispatch->FastIoQueryOpen = SfFastIoQuerOpen;

	DriverObject->FastIoDispatch = fastIoDispatch;


	return status;
}



NTSTATUS
SfPassThrough(
	_In_ PDEVICE_OBJECT DeviceObject,
	_In_ PIRP Irp
)
{
	IoSkipCurrentIrpStackLocation(Irp);
	return IoCallDriver(some_AttachedToDeviceObject,
		Irp);
}
