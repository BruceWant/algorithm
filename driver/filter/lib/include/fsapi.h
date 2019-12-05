#ifndef FSAPI_H
#define FSAPI_H

#include <ntifs.h>
#include <ntdddisk.h>
#include <wdmsec.h>


PDRIVER_OBJECT CFsDriverObject;

PDEVICE_OBJECT CFsDeviceObject;

ULONG gCFsOsMajorVersion;
ULONG gCFsOsMinorVersion;

#define SFLT_POOL_TAG 'tlFs'


#define FS_DEVICE_SHORT_NAME L"Fsfilter"
#define CFS_DEVICE_NAME (L"\\Device\\" FS_DEVICE_SHORT_NAME) 
#define CFS_POOL_TAG	'tlFS'


#define MAX_DEVNAME_LENGTH 64

typedef struct _SFILTER_DEVICE_EXTENSION {
	ULONG TypeFlag;

	PDEVICE_OBJECT AttachedToDeviceObject;

	PDEVICE_OBJECT StorageStackDeviceObject;

	UNICODE_STRING DeviceName;

	WCHAR DeviceNameBuffer[MAX_DEVNAME_LENGTH];

	UCHAR UserExtension[1];
} SFILTER_DEVICE_EXTENSION, * PSFILTER_DEVICE_EXTENSION;



#ifndef ClearFlag
#define ClearFlag(_F,_SF)	((_F) &= ~(_SF))
#endif


#define IS_MY_DEVICE_OBJECT(_devObj) \
	(((_devObj) != NULL) && \
	 ((_devObj)->DriverObject == CFsDriverObject) && \
	 ((_devObj)->DeviceExtension != NULL) && \
	 ((*(ULONG *)(_devObj)->DeviceExtension) == SFLT_POOL_TAG))

#define IS_MY_CONTROL_DEVICE_OBJECT(_devObj) \
	(((_devObj) == CFsDeviceObject) ? \
	 	(ASSERT(((_devObj)->DriverObject == CFsDriverObject) && \
			((_devObj)->DeviceExtension == NULL)), TRUE) : \
		FALSE)

#define VALID_FAST_IO_DISPATCH_HANDLER(_FastIoDispatchPtr, _FieldName) \
	(((_FastIoDispatchPtr) != NULL) && \
	 (((_FastIoDispatchPtr)->SizeOfFastIoDispatch) >= \
	 	(FIELD_OFFSET(FAST_IO_DISPATCH, _FieldName) + \
		 sizeof(void *))) && \
		 ((_FastIoDispatchPtr)->_FieldName != NULL))

#define IS_DESIRED_DEVICE_TYPE(_type) \
	(((_type) == FILE_DEVICE_DISK_FILE_SYSTEM) || \
	 ((_type) == FILE_DEVICE_CD_ROM_FILE_SYSTEM) || \
	 ((_type) == FILE_DEVICE_NETWORK_FILE_SYSTEM))


VOID CFsLoadDynamicFunctions(VOID);
VOID CFsGetCurrentVersion(VOID);
VOID CFsReadDriverParameters(
	_In_ PUNICODE_STRING RegistryPath
);

BOOLEAN SfFastIoCheckIfPossible(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ BOOLEAN Wait,
	_In_ ULONG LockKey,
	_In_ BOOLEAN CheckForReadOperation,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoRead(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ BOOLEAN Wait,
	_In_ ULONG LockKey,
	_Out_ PVOID Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoWrite(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ BOOLEAN Wait,
	_In_ ULONG LockKey,
	_In_ PVOID Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoQueryBasicInfo(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_Out_ PFILE_BASIC_INFORMATION Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoQueryStandardInfo(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_Out_ PFILE_STANDARD_INFORMATION Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoLock(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PLARGE_INTEGER Length,
	PEPROCESS ProcessId,
	ULONG Key,
	BOOLEAN FailImmediately,
	BOOLEAN ExclusiveLock,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoUnlockSingle(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PLARGE_INTEGER Length,
	PEPROCESS ProcessId,
	ULONG Key,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoUnlockAll(
	_In_ PFILE_OBJECT FileObject,
	PEPROCESS ProcessId,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoUnlockAllByKey(
	_In_ PFILE_OBJECT FileObject,
	PVOID ProcessId,
	ULONG Key,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoDeviceControl(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_In_ PVOID InputBuffer OPTIONAL,
	_In_ ULONG InputBufferLength,
	_Out_ PVOID OutputBuffer OPTIONAL,
	_In_ ULONG OutputBufferLength,
	_In_ ULONG IoControlCode,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


VOID SfFastIoDetachDevice(
	_In_ PDEVICE_OBJECT SourceDevice,
	_In_ PDEVICE_OBJECT TargetDevice
);


BOOLEAN SfFastIoQueryNetworkOpenInfo(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_Out_ PFILE_NETWORK_OPEN_INFORMATION Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoMdlRead(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_Out_ PMDL* MdlChain,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoMdlReadComplete(
	_In_ PFILE_OBJECT FileObject,
	_In_ PMDL MdlChain,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoPrepareMdlWrite(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_Out_ PMDL* MdlChain,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoMdlWriteComplete(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PMDL MdlChain,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoReadCompressed(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_Out_ PVOID Buffer,
	_Out_ PMDL* MdlChain,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_Out_ struct _COMPRESSED_DATA_INFO* CompressedDataInfo,
	_In_ ULONG CompressedDataInfoLength,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoWriteCompressed(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_In_ PVOID Buffer,
	_Out_ PMDL* MdlChain,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ struct _COMPRESSED_DATA_INFO* CompressedDataInfo,
	_In_ ULONG CompressedDataInfoLength,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoMdlReadCompleteCompressed(
	_In_ PFILE_OBJECT FileObject,
	_In_ PMDL MdlChain,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoMdlWriteCompleteCompressed(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PMDL MdlChain,
	_In_ PDEVICE_OBJECT DeviceObject
);


BOOLEAN SfFastIoQueryOpen(
	_In_ PIRP Irp,
	_Out_ PFILE_NETWORK_OPEN_INFORMATION NetworkInformation,
	_In_ PDEVICE_OBJECT DeviceObject
);



/* callback routines. */

#if WINVER >= 0X0501
NTSTATUS CFsPreFsFilterPassThrough(
	_In_ PFS_FILTER_CALLBACK_DATA Data,
	_Out_ PVOID* CompletionContext
);

VOID CFsPostFsFilterPassThrough(
	_In_ PFS_FILTER_CALLBACK_DATA Data,
	_In_ NTSTATUS OperationStatus,
	_In_ PVOID CompletionContext
);

#endif



VOID SfCleanupMountedDevice(
	_In_ PDEVICE_OBJECT DeviceObject
);


#endif
