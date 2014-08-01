#ifndef OVRPUBLIC_H_INCLUDED_
#define OVRPUBLIC_H_INCLUDED_

/*
	Largely following the same structure as trackirpublic.h, though we don't need
	to resort to dynamic library stuff.
*/

#include <OVR.h>
#include "externalcode.h"
#include "globalincs/pstypes.h"

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

    bool Enabled( )
    {
        return m_enabled;
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