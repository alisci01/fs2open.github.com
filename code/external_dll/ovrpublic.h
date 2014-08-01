#ifndef OVRPUBLIC_H_INCLUDED_
#define OVRPUBLIC_H_INCLUDED_

#include "external_dll/externalcode.h"
#include "globalincs/pstypes.h"

#define OVREDLLNAME "scptrackir.dll"

#define SCP_INITRESULT_SUCCESS 0
#define SCP_INITRESULT_BADKEY 1
#define SCP_INITRESULT_BADPATH 2
#define SCP_INITRESULT_PATHTOOLONG 3
#define SCP_INITRESULT_NODLL 4
#define SCP_INITRESULT_BADSIGNATURE 5
#define SCP_INITRESULT_UNABLETOREGISTER 6
#define SCP_INITRESULT_BADDATAFIELDS 7
#define SCP_INITRESULT_BADREGISTRATION 8
#define SCP_INITRESULT_BADTRANSMISSION 9

class OculusVRDLL : public SCP_ExternalCode
{
public:
	OculusVRDLL()
	{

	}

private:
	/* Functions */
}

#ifndef SCPDLL_EXTERNAL_LIB
extern OculusVRDLL gOvrDll_OculusVR;
#endif

#endif /* OVRPUBLIC_H_INCLUDED_ */