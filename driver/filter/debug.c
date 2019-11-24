#include "include\\debug.h"


VOID CFsReadDriverParameters(
	_In_ PUNICODE_STRING RegistryPath
)
{
	OBJECT_ATTRIBUTES attributes;
	HANDLE driverRegKey;
	NTSTATUS status;
	ULONG resultLength;
	UNICODE_STRING valueName;
	UCHAR buffer[sizeof(KEY_VALUE_PARTIAL_INFORMATION) +
		sizeof(LONG)];
	PAGED_CODE();

	if (0 == SfDebug) {
		InitializeObjectAttributes(&attributes,
			RegistryPath,
			OBJ_CASE_INSENSITIVE,
			NULL,
			NULL);

		status = ZwOpenKey(&driverRegKey,
			KEY_READ,
			&attributes);
		if (!NT_SUCCESS(status)) {
			return;
		}

		RtlInitUnicodeString(&valueName, L"DebugFlags");

		status = ZwQueryValueKey(driverRegKey,
			&valueName,
			KeyValuePartialInformation,
			buffer,
			sizeof(buffer),
			&resultLength);

		if (NT_SUCCESS(status)) {
			SfDebug = *((PLONG)
				& (((PKEY_VALUE_PARTIAL_INFORMATION)
					buffer)->Data));
		}

		ZwClose(driverRegKey);
	}
}
