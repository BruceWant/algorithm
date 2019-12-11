#include "include/fsapi.h"


ULONG gUserExtensionSize = 0;


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


VOID SfFsNotification(
		_In_ PDEVICE_OBJECT DeviceObject,
		_In_ BOOLEAN FsActive
		)
{
	UNICODE_STRING name;
	WCHAR nameBuffer[MAX_DEVNAME_LENGTH];

	PAGED_CODE();

	RtlInitEmptyUnicodeString(&name,
				  nameBuffer,
				  sizeof(nameBuffer)
				  );
	SfGetObjectName(DeviceObject, &name);


	if (FsActive) {
		SfAttachToFileSystemDevice(DeviceObject, &name);
	} else {
		SfDetachFromFileSystemDevice(DeviceObject);
	}
}


NTSTATUS SfAttachToFileSystemDevice(
		_In_ PDEVICE_OBJECT DeviceObject,
		_In_ PUNICODE_STRING DeviceName
		)
{
	PDEVICE_OBJECT newDeviceObject;
	PSFILTER_DEVICE_EXTENSION devExt;
	UNICODE_STRING fsrecName;
	NTSTATUS status;
	UNICODE_STRING fsName;
	WCHAR tempNameBuffer[MAX_DEVNAME_LENGTH];

	PAGED_CODE();

	if (!IS_DESIRED_DEVICE_TYPE(DeviceObject->DeviceType)) {
		return STATUS_SUCCESS;
	}

	RtlInitEmptyUnicodeString(&fsName,
				  tempNameBuffer,
				  sizeof(tempNameBuffer)
				  );

	RtlInitUnicodeString(&fsrecName, L"\\FileSystem\\Fs_Rec");
	SfGetObjectName(DeviceObject->DriverObject, &fsName);

	if (!FlagOn(SfDebug, SFDEBUG_ATTACH_TO_FSRECOGNIZER)) {
		if (RtlCompareUnicodeString(&fsName,
					&fsrecName,
					TRUE) == 0 ) {
			return STATUS_SUCCESS;
		}
	}

	status = IoCreateDevice(CFsDriverObject,
		     sizeof(SFILTER_DEVICE_EXTENSION) + gUserExtensionSize,
		     NULL,
		     DeviceObject->DeviceType,
		     0,
		     FALSE,
		     &newDeviceObject
		     );
	
	if (!NT_SUCCESS(status)) {
		return status;
	}
	
	if (!OnSfilterAttachPre(newDeviceObject,
				DeviceObject,
				&fsName,
				(PVOID)(((PSFILTER_DEVICE_EXTENSION)
						DeviceObject->
						    DeviceExtension)->
							UserExtension))) {
		return STATUS_UNSUCCESSFUL;
	}

	if (FlagOn(DeviceObject->Flags, DO_BUFFERED_IO)) {
		SetFlag(newDeviceObject->Flags, DO_BUFFERED_IO);
	}

	if (FlagOn(DeviceObject->Flags, DO_DIRECT_IO)) {
		SetFlag(newDeviceObject->Flags, DO_DIRECT_IO);
	}

	if (FlagOn(DeviceObject->Characteristics,
				FILE_DEVICE_SECURE_OPEN)) {
		SetFlag(newDeviceObject->Characteristics,
				FILE_DEVICE_SECURE_OPEN);
	}

	devExt = newDeviceObject->DeviceExtension;
	status = SfAttachDeviceToDeviceStack(newDeviceObject,
			DeviceObject,
			&devExt->AttachedToDeviceObject
			);

	if (!NT_SUCCESS(status)) {
		goto ErrorCleanupDevice;
	}

	devExt->TypeFlag = SFLT_POOL_TAG;
	RtlInitEmptyUnicodeString(&devExt->DeviceName,
				  devExt->DeviceNameBuffer,
				  sizeof(devExt->DeviceNameBuffer)
				  );
	RtlCopyUnicodeString(&devExt->DeviceName, DeviceName);

	ClearFlag(newDeviceObject->Flags, DO_DEVICE_INITIALIZING);


#if WINVER >= 0x0501
	if (IS_WINDOWSXP_OR_LATER()) {
		ASSERT(NULL != CFsDynamicFunctions.EnumerateDeviceObjectList
		       && NULL != CFsDynamicFunctions.GetDiskDeviceObject
		       && NULL != CFsDynamicFunctions.GetDeviceAttachmentBaseRef
		       && NULL != CFsDynamicFunctions.GetLowerDeviceObject);
		status = SfEnumerateFileSystemVolumes(DeviceObject,
						      &fsName);

		if (!NT_SUCCESS(status)) {
			IoDetachDevice(devExt->AttachedToDeviceObject);
			goto ErrorCleanupDevice;
		}
	}
#endif
	OnSfilterAttachPost(newDeviceObject,
			DeviceObject,
			devExt->AttachedToDeviceObject,
			(PVOID)(((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
						UserExtension),
			STATUS_SUCCESS);
	return STATUS_SUCCESS;

	ErrorCleanupDevice:
		SfCleanupMountedDevice(newDeviceObject);
		IoDeleteDevice(newDeviceObject);
		OnSfilterAttachPost(newDeviceObject,
				DeviceObject,
				NULL,
				(PVOID)(((PSFILTER_DEVICE_EXTENSION)
					DeviceObject->DeviceExtension)->
					UserExtension),
				status);
	return status;
}

VOID SfDetachFromFileSystemDevice(
		_In_ PDEVICE_OBJECT DeviceObject
		)
{
	PDEVICE_OBJECT ourAttachedDevice;
	PSFILTER_DEVICE_EXTENSION devExt;

	PAGED_CODE();

	ourAttachedDevice = DeviceObject->AttachedDevice;

	while (NULL != ourAttachedDevice) {
		if (IS_MY_DEVICE_OBJECT(ourAttachedDevice)) {
			devExt = ourAttachedDevice->DeviceExtension;

			SfCleanupMountedDevice(ourAttachedDevice);
			IoDetachDevice(DeviceObject);
			IoDeleteDevice(ourAttachedDevice);

			return;
		}

		DeviceObject = ourAttachedDevice;
		ourAttachedDevice = ourAttachedDevice->AttachedDevice;
	}
}


#if WINVER >= 0x0501
NTSTATUS SfEnumerateFileSystemVolumes(
		_In_ PDEVICE_OBJECT FSDeviceObject,
		_In_ PUNICODE_STRING Name
		)
{
	PDEVICE_OBJECT newDeviceObject;
	PSFILTER_DEVICE_EXTENSION newDevExt;
	PDEVICE_OBJECT *devList;
	PDEVICE_OBJECT storageStackDeviceObject;
	NTSTATUS status;
	ULONG numDevices;
	ULONG i;
	BOOLEAN isShadowCopyVolume;

	PAGED_CODE();

	status = (CFsDynamicFunctions.EnumerateDeviceObjectList)(
			FSDeviceObject->DriverObject,
			NULL,
			0,
			&numDevices
			);

	if (!NT_SUCCESS(status)) {
		ASSERT(STATUS_BUFFER_TOO_SMALL == status);

		numDevices += 8;

		devList = ExAllocatePoolWithTag(NonPagedPool,
				(numDevices * sizeof(PDEVICE_OBJECT)),
				SFLT_POOL_TAG);
		if (NULL == devList) {
			return STATUS_INSUFFICIENT_RESOURCES;
		}
		
		ASSERT(NULL != CFsDynamicFunctions.EnumerateDeviceObjectList);
		status = (CFsDynamicFunctions.EnumerateDeviceObjectList)(
				FSDeviceObject->DriverObject,
				devList,
				(numDevices * sizeof(PDEVICE_OBJECT)),
				&numDevices
				);

		if (!NT_SUCCESS(status)) {
			ExFreePool(devList);
			return status;
		}

		for (i = 0; i < numDevices; i++) {
			storageStackDeviceObject = NULL;

			try {
				if ((devList[i] = FSDeviceObject) ||
					(devList[i]->DeviceType !=
					    FSDeviceObject->DeviceType) ||
					SfIsAttachedToDevice(devList[i],
							     NULL)) {
					leave;
				}

				SfGetBaseDeviceObjectName(devList[i],
							  Name);
				if (Name->Length > 0) {
					leave;
				}
				ASSERT(NULL != CFsDynamicFunctions.
						GetDiskDeviceObject);
				status = (CFsDynamicFunctions.
						GetDiskDeviceObject)(
							devList[i],
							&storageStackDeviceObject);
				if (!NT_SUCCESS(status)) {
					leave;
				}

				status = SfIsShadowCopyVolume(
					storageStackDeviceObject,
						&isShadowCopyVolume);

				if (NT_SUCCESS(status) &&
				    isShadowCopyVolume &&
				    !FlagOn(SfDebug, SFDEBUG_ATTACH_TO_SHADOW_COPIES)) {
					UNICODE_STRING shadowDeviceName;
					WCHAR shadowNameBuffer[MAX_DEVNAME_LENGTH];

					RtlInitEmptyUnicodeString(
							&shadowDeviceName,
							shadowNameBuffer,
							sizeof(shadowNameBuffer));
					SfGetObjectName(
						storageStackDeviceObject,
						&shadowDeviceName);

					leave;
				}

				status = IoCreateDevice(
						CFsDriverObject,
						sizeof(SFILTER_DEVICE_EXTENSION) + gUserExtensionSize,
						NULL,
						devList[i]->DeviceType,
						0,
						FALSE,
						&newDeviceObject);

				if (!NT_SUCCESS(status)) {
					leave;
				}

				newDevExt = newDeviceObject->DeviceExtension;
				newDevExt->TypeFlag = SFLT_POOL_TAG;
				newDevExt->StorageStackDeviceObject =
					storageStackDeviceObject;


				RtlInitEmptyUnicodeString(
						&newDevExt->DeviceName,
						newDevExt->DeviceNameBuffer,
						sizeof(newDevExt->DeviceNameBuffer));

				SfGetObjectName(storageStackDeviceObject,
						&newDevExt->DeviceName);

				ExAcquireFastMutex(&gSfilterAttachLock);

				if (!SfIsAttachedToDevice(devList[i],
							NULL)) {
					status = SfAttachToMountedDevice(
							devList[i],
							newDeviceObject);
					if (!NT_SUCCESS(status)) {
						SfCleanupMountedDevice(
								newDeviceObject);
						IoDeleteDevice(newDeviceObject);
					} else {
						SfCleanupMountedDevice(
							newDeviceObject);
						IoDeleteDevice(
							newDeviceObject);
					}

					ExReleaseFastMutex(&gSfilterAttachLock);
				}
			} finally {
				if (storageStackDeviceObject != NULL ) {
					ObDereferenceObject(
						storageStackDeviceObject);
				}
				ObDereferenceObject(devList[i]);
			}
		}
		status = STATUS_SUCCESS;

		ExFreePool(devList);
	}
	return status;
}


VOID SfFsNotivication(
	_In_ PDEVICE_OBJECT DeviceObject,
	_In_ BOOLEAN FsActive
)
{
	UNICODE_STRING name;
	WCHAR nameBuffer[MAX_DEVNAME_LENGTH];

	PAGED_CODE();

	RtlInitEmptyUnicodeString(&name, nameBuffer, sizeof(nameBuffer));

	SfGetObjectName(DeviceObject, &name);

	if (FsActive) {
		SfAttachToFileSystemDevice(DeviceObject, &name);
	}
	else {
		SfDetachFromFileSystemDevice(DeviceObject);
	}

}


VOID SfGetObjectName(
	_In_ PVOID Object,
	_Inout_ PUNICODE_STRING Name
)
{
	NTSTATUS status;
	CHAR nibuf[512];

	POBJECT_NAME_INFORMATION nameInfo = (POBJECT_NAME_INFORMATION)nibuf;
	ULONG retLength;

	status = ObQueryNameString(Object,
		nameInfo,
		sizeof(nibuf),
		&retLength);

	Name->Length = 0;
	if (NT_SUCCESS(status)) {
		RtlCopyUnicodeString(Name,
			&nameInfo->Name);
	}
}


NTSTATUS SfAttachDeviceToDeviceStack(
	_In_ PDEVICE_OBJECT SourceDevice,
	_In_ PDEVICE_OBJECT TargetDevice,
	_Inout_ PDEVICE_OBJECT* AttachedToDeviceObject
)
{
	PAGED_CODE();

#if WINVER >= 0x0501
	if (IS_WINDOWSXP_OR_LATER()) {
		ASSERT(NULL != CFsDynamicFunctions.AttachDeviceToDeviceStackSafe);

		return (CFsDynamicFunctions.AttachDeviceToDeviceStackSafe)(
			SourceDevice,
			TargetDevice,
			AttachedToDeviceObject
			);
	}
	else {
#endif
		*AttachedToDeviceObject = TargetDevice;
		*AttachedToDeviceObject = IoAttachDeviceToDeviceStack(
			SourceDevice,
			TargetDevice
		);

		if (*AttachedToDeviceObject == NULL) {
			return STATUS_NO_SUCH_DEVICE;
		}

		return STATUS_SUCCESS;
#if WINVER >= 0x0501
	}
#endif
}


BOOLEAN SfIsAttachedToDevice(
	PDEVICE_OBJECT DeviceObject,
	PDEVICE_OBJECT* AttachedDeviceObject OPTIONAL
)
{
	PAGED_CODE();

#if WINVER >= 0x0501
	if (IS_WINDOWSXP_OR_LATER()) {
		ASSERT(NULL != CFsDynamicFunctions.GetLowerDeviceObject &&
			NULL != CFsDynamicFunctions.GetDeviceAttachmentBaseRef);

		return SfIsAttachedToDeviceWXPAndLater(DeviceObject,
			AttachedDeviceObject);
	}
	else {
#endif
		return SfIsAttachedToDeviceW2K(DeviceObject,
			AttachedDeviceObject);
#if WINVER >= 0x0501
	}
#endif
}

#if WINVER >= 0x0501
VOID SfGetBaseDeviceObjectName(
	_In_ PDEVICE_OBJECT DeviceObject,
	_Inout_ PUNICODE_STRING Name
)
{
	ASSERT(NULL != CFsDynamicFunctions.GetDeviceAttachmentBaseRef);
	DeviceObject = (CFsDynamicFunctions.GetDeviceAttachmentBaseRef)(
		DeviceObject);

	SfGetObjectName(DeviceObject, Name);

	ObDereferenceObject(DeviceObject);
}
#endif


NTSTATUS SfIsShadowCopyVolume(
	_In_ PDEVICE_OBJECT StorageStackDeviceObject,
	_Out_ PBOOLEAN IsShadowCopy
)
{
	PAGED_CODE();

	*IsShadowCopy = FALSE;

#if WINVER >= 0x0501
	if (IS_WINDOWS2000()) {
#endif
		UNREFERENCED_PARAMETER(StorageStackDeviceObject);
		return STATUS_SUCCESS;
#if WINVER >= 0x0501
	}

	if (IS_WINDOWSXP()) {
		UNICODE_STRING volSnapDriverName;
		WCHAR buffer[MAX_DEVNAME_LENGTH];
		PUNICODE_STRING storageDriverName;
		ULONG returnedLength;
		NTSTATUS status;

		if (FILE_DEVICE_DISK != StorageStackDeviceObject->
			DeviceType)
		{
			return STATUS_SUCCESS;
		}

		storageDriverName = (PUNICODE_STRING)buffer;
		RtlInitEmptyUnicodeString(storageDriverName,
			Add2Ptr(storageDriverName,
				sizeof(UNICODE_STRING)),
			sizeof(buffer) - sizeof(UNICODE_STRING));

		status = ObQueryNameString(StorageStackDeviceObject,
			(POBJECT_NAME_INFORMATION)storageDriverName,
			storageDriverName->MaximumLength,
			&returnedLength);

		if (!NT_SUCCESS(status)) {
			return status;
		}

		RtlInitUnicodeString(&volSnapDriverName,
			L"\\Driver\\VolSnap");

		if (RtlEqualUnicodeString(storageDriverName,
			&volSnapDriverName,
			TRUE)) {
			*IsShadowCopy = TRUE;
		}
		else {
			NOTHING;
		}

		return STATUS_SUCCESS;
	}
	else {
		PIRP irp;
		KEVENT event;
		IO_STATUS_BLOCK iosb;
		NTSTATUS status;

		if (FILE_DEVICE_VIRTUAL_DISK != StorageStackDeviceObject->
			DeviceType) {
			return STATUS_SUCCESS;
		}

		KeInitializeEvent(&event,
			NotificationEvent,
			FALSE);

		irp = IoBuildDeviceIoControlRequest(
			IOCTL_DISK_IS_WRITABLE,
			StorageStackDeviceObject,
			NULL,
			0,
			NULL,
			0,
			FALSE,
			&event,
			&iosb);

		if (irp == NULL) {
			return STATUS_INSUFFICIENT_RESOURCES;
		}

		status = IoCallDriver(StorageStackDeviceObject, irp);

		if (status == STATUS_PENDING) {
			(VOID)KeWaitForSingleObject(&event,
				Executive,
				KernelMode,
				FALSE,
				NULL);
			status = iosb.Status;
		}

		if (STATUS_MEDIA_WRITE_PROTECTED == status) {
			*IsShadowCopy = TRUE;
			status = STATUS_SUCCESS;
		}

		return status;
	}
#endif
}


NTSTATUS SfAttachToMountedDevice(
	_In_ PDEVICE_OBJECT DeviceObject,
	_In_ PDEVICE_OBJECT SFilterDeviceObject
)
{
	PSFILTER_DEVICE_EXTENSION newDevExt =
		SFilterDeviceObject->DeviceExtension;
	NTSTATUS status;
	ULONG i;

	PAGED_CODE();
	ASSERT(IS_MY_DEVICE_OBJECT(SFilterDeviceObject));
#if WINVER >= 0x0501
	ASSERT(!SfIsAttachedToDevice(DeviceObject, NULL));
#endif
	if (!OnSfilterAttachPre(SFilterDeviceObject,
		DeviceObject,
		NULL,
		(PVOID)(((PSFILTER_DEVICE_EXTENSION)DeviceObject->
			DeviceExtension)->UserExtension))) {
		return STATUS_UNSUCCESSFUL;
	}

	if (FlagOn(DeviceObject->Flags, DO_BUFFERED_IO)) {
		SetFlag(SFilterDeviceObject->Flags, DO_BUFFERED_IO);
	}

	if (FlagOn(DeviceObject->Flags, DO_DIRECT_IO)) {
		SetFlag(SFilterDeviceObject->Flags, DO_DIRECT_IO);
	}

	for (i = 0; i < 8; i++) {
		LARGE_INTEGER interval;

		status = SfAttachDeviceToDeviceStack(SFilterDeviceObject,
			DeviceObject,
			&newDevExt->AttachedToDeviceObject);
		if (NT_SUCCESS(status)) {
			OnSfilterAttachPost(
				SFilterDeviceObject,
				DeviceObject,
				newDevExt->AttachedToDeviceObject,
				(PVOID)(((PSFILTER_DEVICE_EXTENSION)DeviceObject->
					DeviceExtension)->UserExtension),
				status
			);

			ClearFlag(SFilterDeviceObject->Flags,
				DO_DEVICE_INITIALIZING);

			return STATUS_SUCCESS;
		}

		interval.QuadPart = (500 * DELAY_ONE_MILLISECOND);

		KeDelayExecutionThread(KernelMode, FALSE, &interval);
	}
	OnSfilterAttachPost(
		SFilterDeviceObject,
		DeviceObject,
		NULL,
		(PVOID)(((PSFILTER_DEVICE_EXTENSION)DeviceObject->
			DeviceExtension)->UserExtension),
		status);

	return status;
}


#if WINVER >= 0x0501
BOOLEAN SfIsAttachedToDeviceWXPAndLater(
	PDEVICE_OBJECT DeviceObject,
	PDEVICE_OBJECT* AttachedDeviceObject OPTIONAL
)
{
	PDEVICE_OBJECT currentDevObj;
	PDEVICE_OBJECT nextDevObj;

	PAGED_CODE();

	ASSERT(NULL != CFsDynamicFunctions.GetAttachedDeviceReference);
	currentDevObj = (CFsDynamicFunctions.GetAttachedDeviceReference)(
		DeviceObject);

	do {
		if (IS_MY_DEVICE_OBJECT(currentDevObj)) {
			if (ARGUMENT_PRESENT(AttachedDeviceObject)) {
				*AttachedDeviceObject = currentDevObj;
			}
			else {
				ObDereferenceObject(currentDevObj);
			}
			return TRUE;
		}

		ASSERT(NULL != CFsDynamicFunctions.GetLowerDeviceObject);
		nextDevObj = (CFsDynamicFunctions.GetLowerDeviceObject)(
			currentDevObj);

		ObDereferenceObject(currentDevObj);

		currentDevObj = nextDevObj;
	} while (NULL != currentDevObj);

	if (ARGUMENT_PRESENT(AttachedDeviceObject)) {
		*AttachedDeviceObject = NULL;
	}
	return FALSE;
}
#endif

BOOLEAN SfIsAttachedToDeviceW2K(
	PDEVICE_OBJECT DeviceObject,
	PDEVICE_OBJECT* AttachedDeviceObject OPTIONAL
)
{
	PDEVICE_OBJECT currentDevice;

	PAGED_CODE();

	for (currentDevice = DeviceObject;
		currentDevice != NULL;
		currentDevice = currentDevice->AttachedDevice) {
		
		if (IS_MY_DEVICE_OBJECT(currentDevice)) {
			if (ARGUMENT_PRESENT(AttachedDeviceObject)) {
				ObReferenceObject(currentDevice);
				*AttachedDeviceObject = currentDevice;
			}
			return TRUE;
		}
	}

	if (ARGUMENT_PRESENT(AttachedDeviceObject)) {
		*AttachedDeviceObject = NULL;
	}
	return FALSE;
}

PUNICODE_STRING SfGetFileName(
	_In_ PFILE_OBJECT FileObject,
	_In_ NTSTATUS CreateStatus,
	_Inout_ PGET_NAME_CONTROL NameControl
)
{
	POBJECT_NAME_INFORMATION nameInfo;
	NTSTATUS status;
	ULONG size;
	ULONG bufferSize;

	NameControl->allocatedBuffer = NULL;

	nameInfo = (POBJECT_NAME_INFORMATION)NameControl->
		smallBuffer;
	bufferSize = sizeof(NameControl->smallBuffer);

	status = ObQueryNameString(
		(NT_SUCCESS(CreateStatus) ?
		(PVOID)FileObject :
	(PVOID)FileObject->DeviceObject),
		nameInfo,
		bufferSize,
		&size
		);

	if (status == STATUS_BUFFER_OVERFLOW) {
		bufferSize = size + sizeof(WCHAR);
		
		NameControl->allocatedBuffer = ExAllocatePoolWithTag(
			NonPagedPool,
			bufferSize,
			SFLT_POOL_TAG
		);

		if (NULL == NameControl->allocatedBuffer) {
			RtlInitEmptyUnicodeString(
				(PUNICODE_STRING)&NameControl->smallBuffer,
				(PWCHAR)(NameControl->smallBuffer + sizeof(
					UNICODE_STRING)),
					(USHORT)(sizeof(NameControl->smallBuffer) -
						sizeof(UNICODE_STRING))
			);
			return (PUNICODE_STRING)&NameControl->smallBuffer;
		}

		nameInfo = (POBJECT_NAME_INFORMATION)NameControl->allocatedBuffer;

		status = ObQueryNameString(
			FileObject,
			nameInfo,
			bufferSize,
			&size
		);
	}
		if (NT_SUCCESS(status) &&
			!NT_SUCCESS(CreateStatus)) {
			ULONG newSize;
			PCHAR newBuffer;
			POBJECT_NAME_INFORMATION newNameInfo;

			newSize = size + FileObject->FileName.Length;

			if (NULL != FileObject->RelatedFileObject) {
				newSize += FileObject->RelatedFileObject->FileName.Length
					+ sizeof(WCHAR);
			}

			if (newSize > bufferSize) {

				newBuffer = ExAllocatePoolWithTag(
					NonPagedPool,
					newSize,
					SFLT_POOL_TAG
				);

				if (NULL == newBuffer) {
					RtlInitEmptyUnicodeString(
						(PUNICODE_STRING)&NameControl->smallBuffer,
						(PWCHAR)(NameControl->smallBuffer +
							sizeof(UNICODE_STRING)),
							(USHORT)(sizeof(NameControl->smallBuffer) -
								sizeof(UNICODE_STRING))
					);

					return (PUNICODE_STRING)&NameControl->smallBuffer;
				}

				newNameInfo = (POBJECT_NAME_INFORMATION)newBuffer;

				RtlInitEmptyUnicodeString(
					&newNameInfo->Name,
					(PWCHAR)(newBuffer + sizeof(OBJECT_NAME_INFORMATION)),
					(USHORT)(newSize - sizeof(OBJECT_NAME_INFORMATION))
				);
				RtlCopyUnicodeString(&newNameInfo->Name,
					&nameInfo->Name
				);

				if (NULL != NameControl->allocatedBuffer) {
					ExFreePool(NameControl->allocatedBuffer);
				}

				NameControl->allocatedBuffer = newBuffer;
				bufferSize = newSize;
				nameInfo = newNameInfo;
			}
			else {
				nameInfo->Name.MaximumLength = (USHORT)(bufferSize -
					sizeof(OBJECT_NAME_INFORMATION));
			}

			if (NULL != FileObject->RelatedFileObject) {
				RtlAppendUnicodeStringToString(
					&nameInfo->Name,
					&FileObject->RelatedFileObject->FileName);

				RtlAppendUnicodeToString(&nameInfo->Name, L"\\");
			}

			RtlAppendUnicodeStringToString(
				&nameInfo->Name,
				&FileObject->FileName
			);

			ASSERT(nameInfo->Name.Length <= nameInfo->Name.MaximumLength);
		}
	

	return &nameInfo->Name;
}
#endif
