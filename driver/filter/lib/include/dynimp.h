#ifndef DYNIMP_H
#define DYNIMP_H

#include "fsapi.h"

//extern gCFsOsMajorVersion;
//extern gCFsOsMinorVersion;

typedef NTSTATUS(*PCFS_REGISTER_FILE_SYSTEM_FILTER_CALLBACKS) (
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PFS_FILTER_CALLBACKS Callbacks
	);

typedef NTSTATUS(*PCFS_ATTACH_DEVICE_TO_DEVICE_STACK_SAFE) (
	_In_ PDEVICE_OBJECT SourceDevice,
	_In_ PDEVICE_OBJECT TargetDevice,
	_Out_ PDEVICE_OBJECT* AttachedToDeviceObject
	);

typedef NTSTATUS(*PCFS_ENUMERATE_DEVICE_OBJECT_LIST) (
	_In_ PDRIVER_OBJECT DriverObject,
	_In_ PDEVICE_OBJECT* DeviceObjectList,
	_In_ ULONG DeviceObjectListSize,
	_Out_ PULONG ActualNumberDeviceObjects
	);

typedef PDEVICE_OBJECT(*PCFS_GET_LOWER_DEVICE_OBJECT) (
	_In_ PDEVICE_OBJECT DeviceObject
	);

typedef PDEVICE_OBJECT(*PCFS_GET_DEVICE_ATTACHMENT_BASE_REF) (
	_In_ PDEVICE_OBJECT DeviceObject
	);

typedef NTSTATUS(*PCFS_GET_DISK_DEVICE_OBJECT) (
	_In_ PDEVICE_OBJECT FileSystemDeviceObject,
	_Out_ PDEVICE_OBJECT* DiskDeviceObject
	);

typedef PDEVICE_OBJECT(*PCFS_GET_ATTACHED_DEVICE_REFERENCE) (
	_In_ PDEVICE_OBJECT DeviceObject
	);

typedef NTSTATUS(*PCFS_GET_VERSION) (
	_Inout_ PRTL_OSVERSIONINFOW VersionInformation
	);

typedef struct _CFS_DYNAMIC_FUNCTION_POINTERS {
	/* The following routines should all be
	 * available on Windows XP (5.1) and later.
	 */
	PCFS_REGISTER_FILE_SYSTEM_FILTER_CALLBACKS
		RegisterFileSystemFilterCallbacks;
	PCFS_ATTACH_DEVICE_TO_DEVICE_STACK_SAFE
		AttachDeviceToDeviceStackSafe;
	PCFS_ENUMERATE_DEVICE_OBJECT_LIST EnumerateDeviceObjectList;
	PCFS_GET_LOWER_DEVICE_OBJECT GetLowerDeviceObject;
	PCFS_GET_DEVICE_ATTACHMENT_BASE_REF GetDeviceAttachmentBaseRef;
	PCFS_GET_DISK_DEVICE_OBJECT GetDiskDeviceObject;
	PCFS_GET_ATTACHED_DEVICE_REFERENCE GetAttachedDeviceReference;
	PCFS_GET_VERSION GetVersion;
} CFS_DYNAMIC_FUNCTION_POINTERS, * PCFS_DYNAMIC_FUNCTION_POINTERS;

CFS_DYNAMIC_FUNCTION_POINTERS CFsDynamicFunctions;
#endif
