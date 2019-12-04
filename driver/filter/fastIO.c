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

	PAGED_CODE();

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
					Wait,
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


BOOLEAN SfFastIoUnlockSingle(
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
				FastIoDispatch;

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


BOOLEAN SfFastIoUnlockAllByKey (
		_In_ PFILE_OBJECT FileObject,
		PVOID ProcessId,
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

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
						AttachedToDeviceObject;

		fastIoDispatch = nextDeviceObject->DriverObject->
							FastIoDispatch;
		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
						   FastIoUnlockAllByKey)){
			return (fastIoDispatch->FastIoUnlockAllByKey)(
					FileObject,
					ProcessId,
					Key,
					IoStatus,
					nextDeviceObject);
		}
	}
	return FALSE;
}


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
		)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	PAGED_CODE();

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
						   FastIoDeviceControl)) {
			return (fastIoDispatch->FastIoDeviceControl)(
					FileObject,
					Wait,
					InputBuffer,
					InputBufferLength,
					OutputBuffer,
					OutputBufferLength,
					IoControlCode,
					IoStatus,
					nextDeviceObject
					);
		}
	}
	return FALSE;
}


VOID SfFastIoDetachDevice(
		_In_ PDEVICE_OBJECT SourceDevice,
		_In_ PDEVICE_OBJECT TargetDevice
		)
{
	PSFILTER_DEVICE_EXTENSION devExt;

	PAGED_CODE();

	ASSERT(IS_MY_DEVICE_OBJECT(SourceDevice));

	devExt = SourceDevice->DeviceExtension;

	SfCleanupMountedDevice(SourceDevice);
	IoDetachDevice(TargetDevice);
	IoDeleteDevice(SourceDevice);
}


BOOLEAN SfFastIoQueryNetworkOpenInfo(
		_In_ PFILE_OBJECT FileObject,
		_In_ BOOLEAN Wait,
		_Out_ PFILE_NETWORK_OPEN_INFORMATION Buffer,
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
					FastIoQueryNetworkOpenInfo)) {
			return (fastIoDispatch->FastIoQueryNetworkOpenInfo)(
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


BOOLEAN SfFastIoMdlRead(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_Out_ PMDL* MdlChain,
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
		MdlRead)) {
		return (fastIoDispatch->MdlRead)(
			FileObject,
			FileOffset,
			Length,
			LockKey,
			MdlChain,
			IoStatus,
			nextDeviceObject
			);
	}
}
return FALSE;
}


BOOLEAN SfFastIoMdlReadComplete(
	_In_ PFILE_OBJECT FileObject,
	_In_ PMDL MdlChain,
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

	return FALSE;

	if (DeviceObject->DeviceExtension) {
		ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));

		nextDeviceObject = ((PSFILTER_DEVICE_EXTENSION)
			DeviceObject->DeviceExtension)->AttachedToDeviceObject;
		ASSERT(nextDeviceObject);

		fastIoDispatch = nextDeviceObject->DriverObject->
			FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
			MdlReadComplete)) {
			return (fastIoDispatch->MdlReadComplete)(
				FileObject,
				MdlChain,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoPrepareMdlWrite(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ ULONG Length,
	_In_ ULONG LockKey,
	_Out_ PMDL* MdlChain,
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

		fastIoDispatch = nextDeviceObject->DriverObject->
			FastIoDispatch;

		if (VALID_FAST_IO_DISPATCH_HANDLER(fastIoDispatch,
			PrepareMdlWrite)) {
			return (fastIoDispatch->PrepareMdlWrite)(
				FileObject,
				FileOffset,
				Length,
				LockKey,
				MdlChain,
				IoStatus,
				nextDeviceObject);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoMdlWriteComplete(
	_In_ PFILE_OBJECT FileObject,
	_In_ PLARGE_INTEGER FileOffset,
	_In_ PMDL MdlChain,
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
			MdlWriteComplete)) {
			return (fastIoDispatch->MdlWriteComplete)(
				FileObject,
				FileOffset,
				MdlChain,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


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
			FastIoReadCompressed)) {
			return (fastIoDispatch->FastIoReadCompressed)(
				FileObject,
				FileOffset,
				Length,
				LockKey,
				Buffer,
				MdlChain,
				IoStatus,
				CompressedDataInfo,
				CompressedDataInfoLength,
				nextDeviceObject
				);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoWriteCompressed(
		_In_ PFILE_OBJECT FileObject,
		_In_ PLARGE_INTEGER FileOffset,
		_In_ ULONG Length,
		_In_ ULONG LockKey,
		_In_ PVOID Buffer,
		_Out_ PMDL *MdlChain,
		_Out_ PIO_STATUS_BLOCK IoStatus,
		_In_ struct _COMPRESSED_DATA_INFO *CompressedDataInfo,
		_In_ ULONG CompressedDataInfoLength,
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
						FastIoWriteCompressed)) {
			return (fastIoDispatch->FastIoWriteCompressed)(
					FileObject,
					FileOffset,
					Length,
					LockKey,
					Buffer,
					MdlChain,
					IoStatus,
					CompressedDataInfo,
					CompressedDataInfoLength,
					nextDeviceObject
					);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoMdlReadCompleteCompressed(
		_In_ PFILE_OBJECT FileObject,
		_In_ PMDL MdlChain,
		_In_ PDEVICE_OBJECT DeviceObject
		)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

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
					MdlReadCompleteCompressed)) {
			return (fastIoDispatch->MdlReadCompleteCompressed) (
					FileObject,
					MdlChain,
					nextDeviceObject
					);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoMdlWriteCompleteCompressed (
		_In_ PFILE_OBJECT FileObject,
		_In_ PLARGE_INTEGER FileOffset,
		_In_ PMDL MdlChain,
		_In_ PDEVICE_OBJECT DeviceObject
		)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;

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
					MdlWriteCompleteCompressed)) {
			return (fastIoDispatch->MdlWriteCompleteCompressed)(
					FileObject,
					FileOffset,
					MdlChain,
					nextDeviceObject
					);
		}
	}
	return FALSE;
}


BOOLEAN SfFastIoQueryOpen(
		_In_ PIRP Irp,
		_Out_ PFILE_NETWORK_OPEN_INFORMATION NetworkInformation,
		_In_ PDEVICE_OBJECT DeviceObject
		)
{
	PDEVICE_OBJECT nextDeviceObject;
	PFAST_IO_DISPATCH fastIoDispatch;
	BOOLEAN result;

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
						   FastIoQueryOpen)) {
			PIO_STACK_LOCATION irpSp =
					IoGetCurrentIrpStackLocation(Irp);

			irpSp->DeviceObject = nextDeviceObject;

			result = (fastIoDispatch->FastIoQueryOpen)(
					Irp,
					NetworkInformation,
					nextDeviceObject
					);

			irpSp->DeviceObject = DeviceObject;
			return result;
		}
	}
	return FALSE;
}




/* callback routines. */

#if WINVER >= 0x0501

NTSTATUS CFsPreFsFilterPassThrough(
	_In_ PFS_FILTER_CALLBACK_DATA  Data,
	_Out_ PVOID* CompletionContext
)
{
	UNREFERENCED_PARAMETER(Data);
	UNREFERENCED_PARAMETER(CompletionContext);

	ASSERT(IS_MY_DEVICE_OBJECT(Data->DeviceObject));

	return STATUS_SUCCESS;
}

VOID CFsPostFsFilterPassThrough(
	_In_ PFS_FILTER_CALLBACK_DATA Data,
	_In_ NTSTATUS OperationStatus,
	_In_ PVOID CompletionContext
)
{
	UNREFERENCED_PARAMETER(Data);
	UNREFERENCED_PARAMETER(OperationStatus);
	UNREFERENCED_PARAMETER(CompletionContext);

	ASSERT(IS_MY_DEVICE_OBJECT(Data->DeviceObject));
}


VOID SfCleanupMountedDevice(
	_In_ PDEVICE_OBJECT DeviceObject
)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	ASSERT(IS_MY_DEVICE_OBJECT(DeviceObject));
}
#endif