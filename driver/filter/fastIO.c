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

	if (IS_MY_CONTROL_DEVICE_OBJECT(DeviceObject))
		return FALSE;
	if (!IS_MY_DEVICE_OBJECT(DeviceObject))
		return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
						AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
							FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
						   FastIoCheckIfPossible)){
			return (fastIoDispatch->FastIoCheckIfPossible)(
					FileObject,
					FileOffset,
					Length,
					Wait,
					LockKey;
					CheckForReadOperation;
					IoStatus;
					nextDeviceObject);
		}
	}
	return FALSE; 
}


BOOLEAN SfFastIoRead(
		_In_ PFILE_OBJECT FileObject,
		_In_ PLARGE_INTEGER FileOffset,
		_In_ ULONG Length,
		_In_ BOOLEAN Wait,
		_In_ ULONG LockKey,
		_Out_ PVOID Buffer,
		_Out_ PIO_STATUS_BLOCK IoStatus,
		_In_ PDEVICE_OBJECT DeviceObject)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
						AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
							FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
						   FastIoRead)) {
			return (fastIoDispatch->FastIoRead)(
					FileObject,
					FileOffset,
					Length,
					Wait,
					LockKey,
					Buffer,
					IoStatus,
					nextDeviceObject);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoWrite(
		_In_ PFILE_OBJECT FileObject,
		_In_ PLARGE_INTEGER FileOffset,
		_In_ ULONG Length,
		_In_ BOOLEAN Wait,
		_In_ ULONG LockKey,
		_In_ PVOID Buffer,
		_Out_ PIO_STATUS_BLOCK IoStatus,
		_In_ PDEVICE_OBJECT DeviceObject)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
						AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
							FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
						   FastIoWrite)) {
			return (fastIoDispatch->FastIoWrite)(
					FileObject,
					FileOffset,
					Length,
					wait,
					LockKey,
					Buffer,
					IoStatus,
					nextDeviceObject);
		}
	}
	return FALSE;
}
