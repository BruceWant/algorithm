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
		SfDtachFromFileSystemDevice(DeviceObject);
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
		if (RltCompareUnicodeString(&fsName,
					&fsrecName,
					TRUE) == 0 ) {
			return STATUS_SUCCESS;
		}
	}

	status = IoCreateDevice(CFsDriverObject,
		     sizeof(SFILTER_DEVICE_EXTENSION) + gUserExtensionsize,
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

	if (FlagOn(DeviceObject->Flags, DO_BUFFER_IO)) {
		SetFlag(newDeviceObject->Flags, DO_BUFFER_IO);
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
		goto ErrorCleanUpDevice;
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
		ASSERT(NULL != CFsDynamicFunction.EnumerateDeviceObjectList
		       && NULL != CFsDynamicFunction.GetDiskDeviceObject
		       && NULL != CFsDynamicFunction.GetDeviceAttachmentBaseRef
		       && NULL != CFsDynamicFunction.GetLowerDeviceObject);
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
			dexExt = ourAttachedDevice->DeviceExtension;

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

		devList = ExAllocatePoolWithTag(NonPagePool,
				(numDevices * sizeof(PDEVICE_OBJECT)),
				SFLT_POOL_TAG);
		if (NULL == devList) {
			return STATUS_INSUFFICIENT_RESOURCES;
		}
		
		ASSERT(NULL != CFsDynamicFunctions.EnumerateDeviceObjectList);
		status = (CFsDynamicFunctions.EnumberateDeviceObjectList)(
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
						StorageStackDeviceObject,
						&isShadowCopyVolume);

				if (NT_SUCCESS(status) &&
				    isShadowCopyVolume &&
				    !FlagOn(SfDebug, SFDEBUG_ATTACHED_TO_SHADOWN_COPIES)) {
					UNICODE_STRING shadowDeviceName;
					WCHAR shadowNameBuffer[MAX_DEVNAME_LENGTH];

					RtlInitEmptyUnicodeString(
							&shadowDeviceName,
							shadowNameBuffer,
							sizeof(shadowNameBuffer));
					SfGetObjectName(
						StorageStackDeviceObject,
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

				newDevExt = newDeviceObjet->DeviceExtension;
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

				if (!SfIoAttachedToDevice(devList[i],
							NULL)) {
					status = SfAttachedToMountedDevice(
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

					ExReleaseFastMutex(&gSfilterAttacheLock);
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
#endif
