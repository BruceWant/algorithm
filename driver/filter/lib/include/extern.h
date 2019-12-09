#ifndef EXTERN_H
#define EXTERN_H

#include <ntifs.h>
#include <ntdddisk.h>
#include <wdmsec.h>

extern BOOLEAN OnSfilterAttachPre(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PUNICODE_STRING DeviceName,
	_In_ PVOID extension
);

extern VOID OnSfilterAttachPost(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PDEVICE_OBJECT theDeviceToAttached,
	_In_ PVOID extension,
	_In_ NTSTATUS status
);
#endif