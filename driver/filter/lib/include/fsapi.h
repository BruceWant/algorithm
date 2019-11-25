#ifndef FSAPI_H
#define FSAPI_H

#include <ntifs.h>
#include <ntdddisk.h>
#include <wdmsec.h>





#define FS_DEVICE_SHORT_NAME L"Fsfilter"
#define CFS_DEVICE_NAME (L"\\Device\\" FS_DEVICE_SHORT_NAME) 
#define CFS_POOL_TAG	'tlFS'




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

#endif
