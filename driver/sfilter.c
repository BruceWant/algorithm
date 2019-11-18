

PDEVICE_OBJECT gSFilterControlDeviceObject;

NTSTATUS
DriverEntry (
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
	PFAST_IO_DISPATH fastIoDispatch; 
	NTSTATUS status = STATUS_SUCCESS;
	UNICODE_STRING nameString;
	RtlInitUnicodeString( &nameString,
			L"\\FileSystem\\Filters\\SFilter");

	status = IoCreateDevice( DriverObject,
				 0,
				 &nameString,
				 FILE_DEVICE_DISK_FILE_SYSTEM,
				 FILE_DEVICE_SECURE_OPEN,
				 FALSE,
				 &gSFilterControlDeviceObject);
	if ( !NT_SUCCESS(status))
	{
		KdPrint(("SFilter DriverEntry: Error creating "
			 "control device object \"%wZ\", "
			 "status=%08x\n", &nameString, status));
	}

	fastIoDispatch = ExAllocatePoolWithTag(
			NonPagedPool,
			sizeof( FAST_IO_DISPATH),
			SFLT_POOL_TAG);
	if (!fastIoDispatch)
	{
		IoDeleteDevice(gSFilterControlDeviceObject);
		return STATUS_INSUFFICIENT_RESOURCES;
	}

	RtlZeroMemory(fastIoDispatch, sizeof(FAST_IO_DISPATCH));
	fastIoDispatch->SizeOfFastIoDispath = sizeof(FAST_IO_DISPATCH);


	fastIoDispatch->FastIoCheckIfPossible = SfFastIoCheckIfPossible;
	fastIoDispatch->FastIoRead = SfFastIoRead;
	fastIoDispatch->FastIoWrite = SfFastIoWrite;
	fastIoDispatch->FastIoQueryBasicInfo = SfFastIoQueryBasicInfo;
	fastIoDispatch->


	return status;
}



NTSTATUS
SfPassThrough (
	_In_ PDEVICE_OBJECT DeviceObject,
	_In_ PIRP Irp
	)
{
	IoSkipCurrentIrpStackLocation(Irp);
	return IoCallDriver(some_AttachedToDeviceObject,
			     Irp);
}
