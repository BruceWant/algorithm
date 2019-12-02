#include "include/fsapi.h"




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
					LockKey,
					CheckForReadOperation,
					IoStatus,
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


BOOLEAN SfFastIoQueryBasicInfo(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_Out_ PFILE_BASIC_INFORMATION Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
)
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
			FastIoQueryBasicInfo)) {
			return (fastIoDispatch->FastIoQueryBasicInfo)(
				FileObject,
				Wait,
				Buffer,
				IoStatus,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoQueryStandardInfo(
	_In_ PFILE_OBJECT FileObject,
	_In_ BOOLEAN Wait,
	_Out_ PFILE_STANDARD_INFORMATION Buffer,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
			DeviceObject->DeviceExtension)->AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
			FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
			FastIoQueryStandardInfo)) {

			return (fastIoDispatch->FastIoQueryStandardInfo)(
				FileObject,
				Wait,
				Buffer,
				IoStatus,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


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
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)DeviceObject->
			DeviceExtension)->AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
			FastIoDispatch;
		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
			FastIoLock))
		{
			return (fastIoDispatch->FastIoLock) (
				FileObject,
				FileOffset,
				Length,
				ProcessId,
				Key,
				FailImmediately,
				ExclusiveLock,
				IoStatus,
				nextDeviceObject
				);	
		}
	}
	return FALSE;
}


BOOLEAN SfAastIoUnlockSingle(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PLARGE_INTEGER Length,
	PEPROCESS ProcessId,
	ULONG Key,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));


		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)DeviceObject->
			DeviceExtension)->AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
			FastIoDispatch;
		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
			FastIoUnlockSingle)) {
			return (fastIoDispatch->FastIoUnlockSingle)(
				FileObject,
				FileOffset,
				Length,
				ProcessId,
				Key,
				IoStatus,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoUnlockAll(
	_In_ PFILE_OBJECT FileObject,
	PEPROCESS ProcessId,
	_Out_ PIO_STATUS_BLOCK IoStatus,
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)DeviceObject->
			DeviceExtension)->AttachedToDeviceObject;

		if (nextDeviceObject) {
			fastIoDispatch = nextDeviceObject->DriverObject->
				FastIoDispatch

				if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
					FastIoUnlockAll)) {
					return (fastIoDispatch->FastIoUnlockAll)(
						FileObject,
						ProcessId,
						IoStatus,
						nextDeviceObject
						);
				}
		}
	}
	return FALSE;
}