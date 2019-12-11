#ifndef EXTERN_H
#define EXTERN_H

#include <ntifs.h>
#include <ntdddisk.h>
#include <wdmsec.h>

typedef enum {
	SF_IRP_GO_ON = 0,
	SF_IRP_COMPLETED = 1,
	SF_IRP_PASS = 2
}SF_RET;


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

extern SF_RET OnSfilterIrpPre(
	_In_ PDEVICE_OBJECT dev,
	_In_ PDEVICE_OBJECT next_dev,
	_In_ PVOID extension,
	_In_ PIRP irp,
	_Out_ NTSTATUS* status,
	PVOID* context
);

extern VOID OnSfilterIrpPost(
	_In_ PDEVICE_OBJECT dev,
	_In_ PDEVICE_OBJECT next_dev,
	_In_ PVOID extension,
	_In_ PIRP irp,
	_In_ NTSTATUS status,
	PVOID context
);

#endif