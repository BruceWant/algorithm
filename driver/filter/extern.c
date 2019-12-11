#include "include\\extern.h"



BOOLEAN OnSfilterAttachPre(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PUNICODE_STRING DeviceName,
	_In_ PVOID extension
)
{
	UNREFERENCED_PARAMETER(ourDevice);
	UNREFERENCED_PARAMETER(theDeviceToAttach);
	UNREFERENCED_PARAMETER(DeviceName);
	UNREFERENCED_PARAMETER(extension);

	return TRUE;
}



VOID OnSfilterAttachPost(
	_In_ PDEVICE_OBJECT ourDevice,
	_In_ PDEVICE_OBJECT theDeviceToAttach,
	_In_ PDEVICE_OBJECT theDeviceToAttached,
	_In_ PVOID extension,
	_In_ NTSTATUS status
)
{
	UNREFERENCED_PARAMETER(ourDevice);
	UNREFERENCED_PARAMETER(theDeviceToAttach);
	UNREFERENCED_PARAMETER(theDeviceToAttached);
	UNREFERENCED_PARAMETER(extension);
	UNREFERENCED_PARAMETER(status);
}


SF_RET OnSfilterIrpPre(
	_In_ PDEVICE_OBJECT dev,
	_In_ PDEVICE_OBJECT next_dev,
	_In_ PVOID extension,
	_In_ PIRP irp,
	_Out_ NTSTATUS* status,
	PVOID* context)
{
	UNREFERENCED_PARAMETER(dev);
	UNREFERENCED_PARAMETER(next_dev);
	UNREFERENCED_PARAMETER(extension);
	//UNREFERENCED_PARAMETER(status);
	UNREFERENCED_PARAMETER(context);

	*status = STATUS_SUCCESS;

	PIO_STACK_LOCATION irpsp = IoGetCurrentIrpStackLocation(irp);
	PFILE_OBJECT file = irpsp->FileObject;

	if (file == NULL)
	{
		return SF_IRP_PASS;
	}
	return SF_IRP_PASS;
}


VOID OnSfilterIrpPost(
	_In_ PDEVICE_OBJECT dev,
	_In_ PDEVICE_OBJECT next_dev,
	_In_ PVOID extension,
	_In_ PIRP irp,
	_In_ NTSTATUS status,
	PVOID context)
{

}