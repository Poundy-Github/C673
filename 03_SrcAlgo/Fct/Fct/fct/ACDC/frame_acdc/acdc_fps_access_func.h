#ifndef ACDC_FPS_ACCESS_H_INCLUDED
#define ACDC_FPS_ACCESS_H_INCLUDED

#include "acdc_mem.h"
#include "acdc_fps_type.h"

/*! Check if object is STOPPED */
ALGO_INLINE boolean EM_b_IsPrivObjStopped(EM_t_ObjNumber s_iObj)
{
	return (ACDC_p_GetEMGenObjAttributes(s_iObj)->uiDynConfidence > OD_CONSIDER_STOPPED_THRESHOLD);

	//return (EMData.pPrivObjList->Objects[s_iObj].Attributes.u_StoppedConfidence > OD_CONSIDER_STOPPED_THRESHOLD);
}

#endif