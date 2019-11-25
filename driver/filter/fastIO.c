#include "fsapi.h"




BOOLEAN SfFastIoCheckIfPossible(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ BOOLEAN Wait,
	_In_ ULONG LockKey,
	_In_ BOOLEAN CheckForReadOperation,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGE_CODE();

	//if
}