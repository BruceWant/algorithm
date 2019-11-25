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

#endif
