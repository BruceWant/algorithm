#ifndef FSF_H
#define FSF_H

#include "fsapi.h"

typedef struct _KPH_CLIENT
{
	struct
	{
		ULONG VerificationPerformed : 1;
		ULONG VerificationSucceeded : 1;
		ULONG KeysGenerated : 1;
		ULONG SpareBits : 29;
	};
	FAST_MUTEX StateMutex;
	NTSTATUS VerificationStatus;
	PVOID VerifiedProcess;
	HANDLE VerifiedProcessId;
	PVOID VerifiedRangeBase;
	SIZE_T VerifiedRangeSize;
	FAST_MUTEX KeyBackoffMutex;
	//KPH_KEY L1Key;
	//KPH_KEY L2Key;
} KPH_CLIENT, * PKPH_CLIENT;

#endif
