/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                    Umesh Babu Harsha (uidj3583)

CREATION DATE:             30.09.2016

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef OOI_ACCESS_FUNC_H_INCLUDED
#define OOI_ACCESS_FUNC_H_INCLUDED

#include "ooi_custom_ext.h"
#include "ooi_ext.h"
#include "ooi_par.h"
#include "slate_access_func.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup ooi
@{ */
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
ALGO_INLINE const float32 * OOI_pf_GetPredictedLatDispl(ObjNumber_t t_ObjNr);
ALGO_INLINE eRelObjLossReason_t  * OOI_t_LM_ObOOIGetOOILossReason(OOI_RelObjEnum_t t_OOINr);
ALGO_INLINE ObjNumber_t const * OOI_pu_GetOOIListObjId (uint8 OOI_Obj);
ALGO_INLINE OOI_RelObject_t * OOI_pt_GetRelObj(void);


/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:    OOI_pf_GetPredictedLatDispl                                                                       */ /*!

  @brief           Inline access function for predicted distance to course for object

  @description     Inline access function for predicted distance to course for object

  @return          Reference to predicted distance to course for object

  @param[in]       iObj : FCT Object number [0u ... EM_N_OBJECTS-1]

  @c_switch_part   None
  @c_switch_full   None

  @created         11.07.2018
  @changed         11.07.2018

  @author          Grant Davtjan | grant.davtjan@continental-corporation.com | +49 (8382) 9699-633
*************************************************************************************************************************/
ALGO_INLINE const float32 * OOI_pf_GetPredictedLatDispl(ObjNumber_t t_ObjNr)
{
  SLATE_ASSERT((t_ObjNr >= 0) && (t_ObjNr < EM_N_OBJECTS)); //PRQA S 3112
  /* date: 2018-07-12, reviewer:Grant Davtjan, reason: Used/will be used to check array index is within the bound */

  return &(t_OOI_Output.f_PredictedLatDispl[t_ObjNr]);
}

/*************************************************************************************************************************
  Functionname:    OOI_t_LM_ObOOIGetOOILossReason                                                                          */ /*!

  @brief           Get function for Object loss reason for OOI object list

  @description     Returns the object loss reason for the OOI List, by taking object number as input.

                   @startuml
                     start
                       Partition OOIObjectLossReason {
                         - return Object loss reason for the corresponding object number within the number of OOI.
                       }
                    stop
                  @enduml

  @return          t_OOI_Output.OOI_t_eRelObjVerlustGrund[i] : Object loss reason for the corresponding object number 't_OOINr' [Address of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                      with i in [0u ... OOI_NUMBER_OF_OOI]

  @param[in]       t_OOINr : Index of the object whose loss is being evaluated                                                  [Full range of datatype eObjOOI_t as defined in Rte_Type.h]
  @param[out]      -

  @glob_in         t_OOI_Output.OOI_t_eRelObjVerlustGrund[i] : Object loss reason for the corresponding object number 't_OOINr' [Address of datatype eRelObjLossReason_t as defined in Rte_Type.h]
                      array size [0u ... OOI_NUMBER_OF_OOI]
  @glob_out        - 

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            No changes 

  @created         03.04.2007
  @changed         24.03.2016

  @author          Venkat Guttula@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/

ALGO_INLINE eRelObjLossReason_t * OOI_t_LM_ObOOIGetOOILossReason(OOI_RelObjEnum_t t_OOINr)
{
  return &(t_OOI_Output.OOI_t_eRelObjVerlustGrund[t_OOINr]);
}

/*************************************************************************************************************************
  Functionname:    OOI_pu_GetOOIListObjId                                                                          */ /*!

  @brief           Inline function for accessing the object number of OOI Objects

  @description     Inline function for accessing the object number of OOI Objects

                    @startuml
                      start
                        Partition OOI_ObjectNumber {
                          - return OOI Object number
                        }
                      stop
                    @enduml

  @return          &t_OOI_Output.OOI_ObjNumber[i] : Reference to object number of OOI Object number [0 ... EM_N_OBJECTS-1] of datatype OOIOutput_t as defined in ooi_ext.h]
                      with i in [0 ... EM_N_OBJECTS-1]

  @param[in]       OOI_Obj : FCT Object ID of datatype ObjNumber_t as defined in Rte_type.h  [0u ... EM_N_OBJECTS-1]
  @param[out]      -

  @glob_in         t_OOI_Output.OOI_ObjNumber[OOI_Obj] : OOI Object number                   [0u ... EM_N_OBJECTS-1]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @created         15.12.2016
  @changed         15.12.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
ALGO_INLINE ObjNumber_t const * OOI_pu_GetOOIListObjId (uint8 OOI_Obj)
{
  return &(t_OOI_Output.OOI_ObjNumber[OOI_Obj]);
}


/*************************************************************************************************************************
  Functionname:    OOI_pt_GetRelObj                                                                          */ /*!

  @brief           Inline function for accessing the relevant object (OOI-0) information

  @description     Inline function for accessing the relevant object (OOI-0) information

                    @startuml
                      start
                        Partition OOI_pt_GetRelObj {
                          - return OOI-0 information
                        }
                      stop
                    @enduml

  @return          &(t_OOI_Output.t_OOI_RelObject) : Reference to OOI-0 structure

  @param[in]       -
  @param[out]      -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @created         06.06.2019
  @changed         06.06.2019

  @author          Radhakrishna Vemula | radhakrishna.vemula@continental-corporation.com 
*************************************************************************************************************************/
ALGO_INLINE OOI_RelObject_t * OOI_pt_GetRelObj(void)
{
  return &(t_OOI_Output.t_OOI_RelObject[OBJ_NEXT_OOI]);
}

///@}
#endif /* END IF OOI_ACCESS_FUNC_H_INCLUDED */
