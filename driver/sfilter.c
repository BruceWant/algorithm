



NTSTATUS
DriverEntry (
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PUNICODE_STRING RegistryPath
)
{
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


	return status;
}
