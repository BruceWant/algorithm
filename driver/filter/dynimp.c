

/* This routine thries to load the function pointers
 * for the routines that are not supported on all
 * versions of the Windows OS. These function pointers
 * are then stored in the global structure CFsDynamicFunctions.
 *
 * This support allows for one driver to be built that 
 * will run on all versions of the OS Windows XP and greater.
 */
#if WINVER >= 0X0501
VOID CFsLoadDynamicFunctions(
		VOID
		)
{
	UNICODE_STRING functionName;

	RtlZeroMemory(&CFsDynamicFunctions, sizeof(CFsDynamicFuntions));

	RtlInitUnicodeString(&functionName,
			     L"FsRtlRegisterFileSystemFilterCallbacks");
	CFsDynamicFuntions.RegisterFileSystemFilterCallbacks =
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
			     L"IoAttachDeviceToDeviceStackSafe");
	CFsDynamicFunctions.AttachDeviceToDeviceStackSafe =
		MmGetSystemRoutineAddress(&functionName);
	
	RtlInitUnicodeString(&functionName,
			     L"IoGetLowerDeviceObject");
	CFsDynamicFunctions.GetLowerDeviceObject =
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
			     L"IoGetDeviceAttachmentBaseRef");
	CFsDynamicFunctions.GetDeviceAttachmentBaseRef = 
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
			     L"IoGetDiskDeviceObject");
	CFsDynamicFunctions.GetDiskDeviceObject =
		MmGetSystemRoutineAddres(&functionName);

	RtlInitUnicodeString(&functionName,
			     L"IoGetAttachedDeviceReference");
	CFsDynamicFunctions.GetAttachedDeviceReference =
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
			     L"RtlGetVersion");
	CFsDynamicFunctions.Getversion =
		MmGetSystemRoutineAddress(&functionName);
}
