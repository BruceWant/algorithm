#include "include\\fsapi.h"
#include "include\\dynimp.h"


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
	//_Inout_ PCFS_DYNAMIC_FUNCTION_POINTERS CFsDynamicFunctions
	VOID
)
{
	UNICODE_STRING functionName;

	RtlZeroMemory(&CFsDynamicFunctions, sizeof(CFsDynamicFunctions));

	RtlInitUnicodeString(&functionName,
		L"FsRtlRegisterFileSystemFilterCallbacks");
	CFsDynamicFunctions.RegisterFileSystemFilterCallbacks =
		(PCFS_REGISTER_FILE_SYSTEM_FILTER_CALLBACKS)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoAttachDeviceToDeviceStackSafe");
	CFsDynamicFunctions.AttachDeviceToDeviceStackSafe =
		(PCFS_ATTACH_DEVICE_TO_DEVICE_STACK_SAFE)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoEnumerateDeviceObjectList");
	CFsDynamicFunctions.EnumerateDeviceObjectList =
		(PCFS_ENUMERATE_DEVICE_OBJECT_LIST)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoGetLowerDeviceObject");
	CFsDynamicFunctions.GetLowerDeviceObject =
		(PCFS_GET_LOWER_DEVICE_OBJECT)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoGetDeviceAttachmentBaseRef");
	CFsDynamicFunctions.GetDeviceAttachmentBaseRef =
		(PCFS_GET_DEVICE_ATTACHMENT_BASE_REF)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoGetDiskDeviceObject");
	CFsDynamicFunctions.GetDiskDeviceObject =
		(PCFS_GET_DISK_DEVICE_OBJECT)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"IoGetAttachedDeviceReference");
	CFsDynamicFunctions.GetAttachedDeviceReference =
		(PCFS_GET_ATTACHED_DEVICE_REFERENCE)
		MmGetSystemRoutineAddress(&functionName);

	RtlInitUnicodeString(&functionName,
		L"RtlGetVersion");
	CFsDynamicFunctions.GetVersion =
		(PCFS_GET_VERSION)
		MmGetSystemRoutineAddress(&functionName);
}


/* This routine reads the current OS version using
 * the correct routine based on what routine is availabe.
 */
VOID CFsGetCurrentVersion(
	VOID
)
{
	if (NULL != CFsDynamicFunctions.GetVersion) {
		RTL_OSVERSIONINFOW versionInfo;
		NTSTATUS status = STATUS_SUCCESS;

		versionInfo.dwOSVersionInfoSize =
			sizeof(RTL_OSVERSIONINFOW);

		status = (CFsDynamicFunctions.GetVersion)(&versionInfo);
		
		gCFsOsMajorVersion = versionInfo.dwMajorVersion;
		gCFsOsMinorVersion = versionInfo.dwMinorVersion;
	}
	else {
		PsGetVersion(&gCFsOsMajorVersion,
			&gCFsOsMinorVersion,
			NULL,
			NULL);
	}
}


#endif