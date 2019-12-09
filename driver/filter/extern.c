#include "include\\fsapi.h"

BOOLEAN OnSfilterAttachPre(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PUNICODE_STRING DeviceName,
	_In_ PVOID extension
)
{
	UNREFERENCED_PARAMETER(ourDevice);
	UNREFERENCED_PARAMETER(theDeviceToAttach);
	UNREFERENCED_PARAMETER(DeviceName);
	UNREFERENCED_PARAMETER(extension);

	return TRUE;
}



VOID OnSfilterAttachPost(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PDEVICE_OBJECT theDeviceToAttached,
	_In_ PVOID extension,
	_In_ NTSTATUS status
)
{
	UNREFERENCED_PARAMETER(ourDevice);
	UNREFERENCED_PARAMETER(theDeviceToAttach);
	UNREFERENCED_PARAMETER(theDeviceToAttached);
	UNREFERENCED_PARAMETER(extension);
	UNREFERENCED_PARAMETER(status);
}