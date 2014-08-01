#ifndef OVRPUBLIC_H_INCLUDED_
#define OVRPUBLIC_H_INCLUDED_

/*
	Largely following the same structure as trackirpublic.h, though we don't need
	to resort to dynamic library stuff.
*/

#include <OVR.h>
#include "globalincs/pstypes.h"

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
#define SCP_INITRESULT_INITFAILED 10
#define SCP_INITRESULT_NOHMDDETECTED 11
#define SCP_INITRESULT_TRACKCONFIGFAILED 12
#define SCP_INITRESULT_RENDERCONFIGFAILED 13

class OculusVR
{
public:
	OculusVR( )
	{
		m_enabled = false;
		hmd = NULL;
	}

	int Init( )
	{
		if (!ovr_Initialize())
			return SCP_INITRESULT_INITFAILED;

		hmd = ovrHmd_Create(0);

		if (!hmd)
			return SCP_INITRESULT_NOHMDDETECTED;

		if (!ovrHmd_ConfigureTracking(hmd,
			ovrTrackingCap_Orientation |
			ovrTrackingCap_MagYawCorrection |
			ovrTrackingCap_Position, 0))
			return SCP_INITRESULT_TRACKCONFIGFAILED;

		m_enabled = true;
		return SCP_INITRESULT_SUCCESS;
	}

	int Close( )
	{
		if (hmd)
			ovrHmd_Destroy( hmd );

		ovr_Shutdown();

		return 0;
	}

	void PollTracking( )
	{
		// TODO refer to OVR docs about prediction based timing from ovrHmd_BeginFrame or ovrHmdBeginFrameTiming
		ovrTrackingState ts = ovrHmd_GetTrackingState(hmd, ovr_GetTimeInSeconds());

		// TODO break out tracking state for orientation/positioning/etc
	}

private:
	
	ovrHmd hmd;
	bool m_enabled;
}

#ifndef SCPDLL_EXTERNAL_LIB
extern OculusVR gOculusVR;
#endif

#endif /* OVRPUBLIC_H_INCLUDED_ */