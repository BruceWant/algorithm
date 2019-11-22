#include "./lib/include/fsapi.h"
#include "./lib/include/dyndat.h"

DRIVER_INITIALIZE DriverEntry;
DRIVER_UNLOAD DriverUnload;
_Dispatch_type_(IRP_MJ_CREATE) DRIVER_DISPATCH CFsDispatchCreate;
_Dispatch_type_(IRP_MJ_CLOSE) DRIVER_DISPATCH CFsDispatchClose;

#ifdef ALLOC_PRAGMA
#pragma alloc_text(PAGE, DriverEntry)
#pragma alloc_text(PAGE, DriverUnload)
#endif


NTSTATUS DriverEntry(
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
	)
{
	NTSTATUS status;
	UNICODE_STRING deviceName;
	PDEVICE_OBJECT deviceObject;
	
	FsDriverObject = DriverObject;

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

	FsDeviceObject = deviceObject;

	// Set up I/O.
	DriverObject->MajorFunction[IRP_MJ_CREATE] = CFsDispatchCreate;
	DriverObject->MajorFunction[IRP_MJ_CLOSE] = CFsDispatchClose;
	DriverObject->MajorFunction[IRP_MJ_DEVICE_CONSTROL] =
		CFsDispatchDeviceControl;
	DriverObject->DriverUnload = DriverUnload;

	deviceObject->Flags &= ~DO_DEVICE_INITIALIZING;

	KdPrint(("Driver loaded\n");

	return status;
}

VOID DriverUnload(
	_In_ PDRIVER_OBJECT DriverObject
	)
{
	PAGED_CODE();

	IoDeleteDevice(FsDeviceObject);

	KdPrint(("Driver unloaded\n"));
}

NTSTATUS CFsDispatchCreate(
	_In_ PDEVICE_OBJECT DeviceObject,
	_Inout_ PIRP Irp
	)
{
	NTSTATUS status = STATUS_SUCCESS;
	PIO_STACK_LOCATION stackLocation;
	PFILE_OBJECT fileObject;
	PIO_SECURITY_CONTEXT securityContext;
	PKPH_CLIENT client;
	
	stackLocation = IoGetCurrentIrpStackLocation(Irp);
	fileObject = stackLocation->FileObject;
	securityContext = stackLocation->Parameters.Create.SecurityContext;

}
