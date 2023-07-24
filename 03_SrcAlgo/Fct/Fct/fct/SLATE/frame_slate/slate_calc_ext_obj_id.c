/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Function Sensor Frame SLATE

MODULNAME:                 slate_calc_ext_obj_id.c

DESCRIPTION:               This module inherits algorithms for calculation of
                             external (CAN) object IDs.

AUTHOR:                    $Author: uib05783 $

CREATION DATE:             26.01.2017

VERSION:                   $Revision: 1.10 $


LEGACY VERSION:            Revision: 1.14.1.2
  
**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"  /*  PRQA S 0380 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: This will not have any effect on functionality */
/* Top level pre-proc branch to exclude all code if disabled */
#if (SLATE_CFG_USE_EXT_OBJ_ID)

/*****************************************************************************
  MACROS 
*****************************************************************************/

#if (SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)

#ifndef FCT_PAR_OBJ_EXT_ID_MODULO
#define FCT_PAR_OBJ_EXT_ID_MODULO   EM_N_OBJECTS
#endif

#ifndef FCT_PAR_OBJ_EXT_ID_OFFSET
#define FCT_PAR_OBJ_EXT_ID_OFFSET   0
#endif

#else
/*! Macro used to determine if a given external object ID is in use */
#define FCT_IS_EXTERN_ID_IN_USE(x)    (FCTExternIdUseBits[x >> 3] & (1u << (x & 7)))
#define FCT_SET_EXTERN_ID_USED(x)     (FCTExternIdUseBits[x >> 3] |= (1u << (x & 7)))
#define FCT_SET_EXTERN_ID_FREE(x)     (FCTExternIdUseBits[x >> 3] &= (uint8)(~(1u << (x & 7))))

#if (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID)
/*! Macro to get next external ID for the given ID passed in as argument. In this
case we need to return the next ((x + n) % FCT_NR_EXTERN_OBJECT_ID) that is not equal
to the FCT_EXTERN_OBJ_ID_NO_OBJECT value */
#define FCT_GET_NEXT_EXT_ID(x)       FCTGetNextExtObjIdWithSkip(x)
#else
/*! Macro to get next external ID for the given ID passed in as argument. In this
case it means merely returning ((x + 1) % FCT_NR_EXTERN_OBJECT_ID)*/
#define FCT_GET_NEXT_EXT_ID(x)        (((x) < (FCT_NR_EXTERN_OBJECT_ID-1))?((x) + 1):(0))
#endif  /* (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID) */
#endif  /* SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */

/*! If configuration does not define the number of external object-IDs available,
then assume the ARS310 default of 31 possibilities [0 .. 30] */
#ifndef FCT_NR_EXTERN_OBJECT_ID
#define FCT_NR_EXTERN_OBJECT_ID     (31)
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
/*! The type used to track the external ID assignment age on an object */
typedef uint8 FCTExtIdAge_t;
#endif

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! The maximum assignment age of an external ID */
#define FCT_MAX_EXT_ID_ASSIGN_AGE  255

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*! Array of EM_N_OBJECTS length storing for each internal object ID
the external ID assigned or special FCT_EXTERN_OBJ_ID_NO_OBJECT value if
no ID was assigned */
SET_MEMSEC_VAR(FCTIntern2ExternID)
static FCTSenExtObjId_t FCTIntern2ExternID[EM_N_OBJECTS];

#if (!SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)

/*! Array of FCT_NR_EXTERN_OBJECT_ID bits, storing for each external ID
it's usage state. If the i-th bit is set, that means the given external
ID is in use */
SET_MEMSEC_VAR(FCTExternIdUseBits)
static uint8 FCTExternIdUseBits[(FCT_NR_EXTERN_OBJECT_ID + 7)>>3];

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
/*! Array for tracking the cycles how long a given external ID was not
assigned. This can be used to maximize the time between assignment of
a given external ID */
SET_MEMSEC_VAR(FCTExtIdAssignAge)
static FCTExtIdAge_t FCTExtIdAssignAge[FCT_NR_EXTERN_OBJECT_ID];
#endif

/*! The counter determining which external object ID gets assigned next */
SET_MEMSEC_VAR(FCTExternIDCtr)
static FCTSenExtObjId_t FCTExternIDCtr;

/*! The counter showing how many external IDs are currently in use */
SET_MEMSEC_VAR(FCTExtIdsUsed)
static FCTSenExtObjId_t FCTExtIdsUsed;

#endif  /* SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

#if (!SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
#if (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID)
static FCTSenExtObjId_t FCTGetNextExtObjIdWithSkip(FCTSenExtObjId_t in_id);
#endif
static void FCTAssignExtIdToObj(ObjNumber_t iInternID);
#endif


/*************************************************************************************************************************
  Functionname:    FCTSen_v_SLATEInitExternObjID                                                                    */ /*!

  @brief           Initialize the external object-ID lookup hashes (SLATE)

  @description     Initialize the external object-ID lookup hashes (SLATE)
                   @startuml
                   Start
                    Partition FCTSen_v_SLATEInitExternObjID
                    Repeat
	                -At default assign the internal ID as external ID with offset
	                If(unless external ID would match the special reserved no object ID) then (True)
	                    -set external ID to sum of external ID and FCT external ID Modulo	
	                 endif
	                 -Update Internal to external array with external ID
	               	Repeatwhile(for valid EM Objects)
                       -Clear assignment information external object ID to internal ID
                       -Clear assignment information for internal object to external object
                   
	               	Repeat
	               	   -reset assigned external ID age
	               	Repeat while(for all valid  avaiable objests)
	                    - Initialize the external object ID counter
                        - Set number of external IDs used to zero
                   
                   end
                   @enduml


  @return          void

  @param[in]       void

  @glob_in         -
  @glob_out        FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID           [full range of unsigned int]

  @c_switch_part   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                            and external ID, simply counting up modulo EM_N_OBJECTS with the external ID

  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             -
  @post            FCTExternIdUseBits & FCTIntern2ExternID array initialized with the respective not assigned value, 
                   FCTExternIDCtr is reset to 0 as initial value

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSen_v_SLATEInitExternObjID(void)
{
  FCTSenExtObjId_t i;
  FCTSenExtObjId_t iExtObj;

#if (SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)

  /* Clear assignment information for internal object 2 external object */
  for (i = 0u; i < (FCTSenExtObjId_t)EM_N_OBJECTS; i++)
  {
    /* At default assign the internal ID as external ID with offset */
    iExtObj = i + (FCTSenExtObjId_t)FCT_PAR_OBJ_EXT_ID_OFFSET;
# if (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID)
    /* Unless that external ID would match the special reserved no object ID */
    if (iExtObj == (FCTSenExtObjId_t)FCT_EXTERN_OBJ_ID_NO_OBJECT)
    {
      iExtObj += (FCTSenExtObjId_t)FCT_PAR_OBJ_EXT_ID_MODULO;
    }
# endif
    FCTIntern2ExternID[i] = iExtObj;
  }

#else
  /* Clear assignment information external object ID to interal ID */
  for(iExtObj = (FCTSenExtObjId_t) 0; iExtObj < (FCTSenExtObjId_t)((FCT_NR_EXTERN_OBJECT_ID+7)>>3); iExtObj++)
  {
    FCTExternIdUseBits[iExtObj] = 0;
  }

  /* Clear assignment information for internal object 2 external object */
  for (i = (ObjNumber_t) 0; i < (ObjNumber_t)EM_N_OBJECTS; i++)
  {
    FCTIntern2ExternID[i] = FCT_EXTERN_OBJ_ID_NO_OBJECT;
  }

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
  for (iExtObj = (FCTSenExtObjId_t)0; iExtObj < (FCTSenExtObjId_t)FCT_NR_EXTERN_OBJECT_ID; iExtObj++)
  {
    /* Also reset assigned external ID age */
    FCTExtIdAssignAge[iExtObj] = 0;
  }
#endif

#if (FCT_EXTERN_OBJ_ID_NO_OBJECT != 0)
  /* Initialize the external object ID counter */
  FCTExternIDCtr = 0;
#else
  /* Initialize the external object ID counter */
  FCTExternIDCtr = 1;
#endif

  /* Set number of external IDs used to zero */
  FCTExtIdsUsed  = 0;
#endif  /* SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */
}

#if (!SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
#if (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID)
/*************************************************************************************************************************
  Functionname:    FCTGetNextExtObjIdWithSkip                                                                       */ /*!

  @brief           Get next external object ID that comes after the one passed

  @description     Returns the next external object ID that comes after the external object ID passed as argument. 
                   Note: this function is needed for the special case when the value FCT_EXTERN_OBJ_ID_NO_OBJECT
				   @startuml
                   Start
	               Partition FCTGetNextExtObjIdWithSkip
	               -calculate the next ID modulo FCT_NR_EXTERN_OBJECT_ID
                      If(the ID is exactly the one that means 'no object) then (True)
	                	-move to the next object
                      endif
                   
                   end
                   @enduml
 
                   smaller then FCT_NR_EXTERN_OBJECT_ID (i.e.: part of the numeric range of external IDs)


  @return          static FCTSenExtObjId_t : Next External object ids                                       [Full range of unsigned int]

  @param[in]       in_id : Input External object ids                                                        [Full range of unsigned int]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                                               and external ID, simply counting up modulo EM_N_OBJECTS with the external ID
  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
static FCTSenExtObjId_t FCTGetNextExtObjIdWithSkip(FCTSenExtObjId_t in_id)
{
  FCTSenExtObjId_t out_id = in_id;
  /* First calculate the next ID modulo FCT_NR_EXTERN_OBJECT_ID */
  if (in_id < (FCT_NR_EXTERN_OBJECT_ID-1))
  {
    out_id = in_id + 1;
  }
  else
  {
    out_id = 0;
  }
  /* If the ID is exactly the one that means 'no object', then
  advance to the next one */
  if (out_id == FCT_EXTERN_OBJ_ID_NO_OBJECT)
  {
    out_id = ((FCT_EXTERN_OBJ_ID_NO_OBJECT + 1) % FCT_NR_EXTERN_OBJECT_ID);
  }
  return out_id;
}
#endif

/*************************************************************************************************************************
  Functionname:    FCTAssignExtIdToObj                                                                              */ /*!

  @brief           Assign an external object ID to an object

  @description     Assign an external object ID to the given object
                   @startuml
                   Start
                   Partition FCTAssignExtIdToObj
                   If(given ID is already assigned to the object) then (True)
                    Note
    			     An ID is already assigned
		            End note
				    -Do nothing
		           Else
			       - find an ID to assign. For this we primarily search for unused external IDs. If we don't find any then use the oldest assignment if externalID age tracking enabled
		           Endif
                 - Reset age, since an external ID already assigned, and actively used
                   end
                 @enduml


  @return          static void

  @param[in]       iInternID : Internal object id                                                                                                             [-1 ... 39]

  @glob_in         FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID                                                     [full range of unsigned int8]
  @glob_in         FCTExternIDCtr : FCT external ID counter                                                                                                   [full range of uint8]
  @glob_in         FCT_IS_EXTERN_ID_IN_USE(iFreeID) : Macro used to determine if a given external object ID is in use                                         [TRUE, FALSE]
  @glob_in         FCTExtIdAssignAge : Array for tracking the cycles how long a given external ID was not assigned. This can be used to 
                          maximize the time between assignment of a given external ID                                                                         [0 ... 254]
  @glob_in         FCT_GET_NEXT_EXT_ID : Get next external id as define in this function.

  @glob_out        FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID                                                     [full range of unsigned int8]
  @glob_out        None ? : Global output filled in this function
  @glob_out        FCTExtIdAssignAge : Array for tracking the cycles how long a given external ID was not assigned. This can be used to 
                          maximize the time between assignment of a given external ID                                                                         [0 ... 254]


  @c_switch_part   SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING : Configuration switch to enable assignment age based trackign of external IDs
                            (this means the object that has not been OOI for the longest time will have it's ID removed if all external IDs are exhausted as defined in fct_config.h
  @c_switch_part   FCT_SIMU : Macro to enable simulation debug information

  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment
  @c_switch_full   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                                               and external ID, simply counting up modulo EM_N_OBJECTS with the external ID


  @pre             FCTSenInitExternObjID called previously
  @post            The given object is assigned an external ID

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
static void FCTAssignExtIdToObj(ObjNumber_t iInternID)
{
  FCTSenExtObjId_t iFreeID;
  FCTSenExtObjId_t iAttemptCnt;
#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
  FCTSenExtObjId_t iOldestExtId = 0;
  FCTExtIdAge_t iOldestAge   = 0;
#endif

  /* Check if an ID is already assigned to the object */
  iFreeID = FCTIntern2ExternID[iInternID];
  if (iFreeID != FCT_EXTERN_OBJ_ID_NO_OBJECT)
  {
    /* An ID is already assigned */
  }
  else
  {
    /* No external ID assigned to the object, find an ID to assign. For this
    we primarily search for unused external IDs. If we don't find any
    (theoretically possible - then use the oldest assignment if external
    ID age tracking enabled) */
    iFreeID = FCTExternIDCtr;
#ifdef FCT_SIMU
    assert(FCTExternIDCtr != FCT_EXTERN_OBJ_ID_NO_OBJECT);
#endif
    iAttemptCnt = 0;
    while ((FCT_IS_EXTERN_ID_IN_USE(iFreeID)) && (iAttemptCnt < FCT_NR_EXTERN_OBJECT_ID))
    {
#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
      /* If the given ID has not been used longer then the oldest one we had so far,
      select this one as the oldest used one */
      if (iOldestAge < FCTExtIdAssignAge[iFreeID])
      {
        iOldestExtId = iFreeID;
        iOldestAge = FCTExtIdAssignAge[iFreeID];
      }
#endif
      /* It's not free, increment attempt counter */
      iAttemptCnt++;
      /* Go to next external ID with wrap-around */
      iFreeID = FCT_GET_NEXT_EXT_ID(iFreeID);
    }

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
    /* Set to use oldest external ID */
    iFreeID = iOldestExtId;
#endif

    /* Check if the external ID the find loop terminated on is indeed free */
    if (FCT_IS_EXTERN_ID_IN_USE(iFreeID))
    {
      /* Do not increment counter of external object IDs */
    }
    else
    {
      /* Increment the number of external IDs used */
      FCTExtIdsUsed++;
    }

    /* Store the next extern ID to start searching from */
    FCTExternIDCtr = FCT_GET_NEXT_EXT_ID(iFreeID);

    /* Assign the ID */
    FCT_SET_EXTERN_ID_USED(iFreeID);
    FCTIntern2ExternID[iInternID] = iFreeID;
  }

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
  /* Reset age, since an external ID already assigned, and actively used */
  FCTExtIdAssignAge[iFreeID] = 0;
#endif
}
#endif  /* !SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */


/*************************************************************************************************************************
  Functionname:    FCTSenDetermineExternObjID                                                                       */ /*!

  @brief           Assign external object IDs for OOI

  @description     Assign external object IDs to objects and do internal housekeeping necessary for external ID assignment.
                   This is the main cyclic method that shall be called to assign external object IDs to the objects of interest.
				   @startuml
					Start
					Partition FCTSenDetermineExternObjID  {
					
					Repeat
						If(Object is deleted) then(True)
						-Do not assign External ID
						Else(false)
							If(Object is New) then (True)
							- Assign external ID to New and non-deleted objects
							- Increment the left over IDs, otherwise start over 
							-skip to the next modulo external ID,If the new ID is the one reserved for no object
							Endif
							- Assign the current external object ID to the object
					
						endif
					Repeatwhile(for all the EM objects)
					
					- Increase the age of all external ID assignments .FCTAssignExtIdToObj function will reset OOI objects to zero later
					
					- Go through list of internal objects, and if one was deleted, remove the corresponding external object ID assigned 
					
					- Assertion that we need more external object IDs then internal objects when assigning an external object ID for each
					
					- For all objects set external object ID
					- for every relevant object, set it's external object-ID
					- Copy external object ID to public object list 
					- verify that for each internal ID with an external ID assigned, the external ID map has the proper internal ID
					- verify that all entries in the extern id map have the correct intern ID
					- Verify that the number of used IDs is correctly tracked
					- verify that all OOI objects have an external ID
					
					
					}
					
					End 
					@enduml


  @return          void

  @param[in]       void

  @glob_in         SLATE_b_GetObjIsDeleted : Macro which returns true if the maintenance state of given object is Deleted, false otherwise as defined in algo_glob.h   [TRUE, FALSE]
  @glob_in         SLATE_b_GetObjIsNew : Macro which returns true if the maintenance state of given object is New, false otherwise as defined in algo_glob.h           [TRUE, FALSE]
  @glob_in         OBJ_GET_EXTERNAL_OBJ_ID : Macro to return external id of given object of interest as defined in fct_sen.h                                  [full range of unsigned char]
  @glob_in         FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID                                                     [full range of unsigned int8]
  @glob_in         FCTExtIdAssignAge : Array for tracking the cycles how long a given external ID was not assigned. This can be used to 
                          maximize the time between assignment of a given external ID                                                                         [0 ... 254]
  @glob_in         FCT_SET_EXTERN_ID_FREE : Macro to set the given external id's use state as free as defined in the same file.
  @glob_in         OBJ_GET_OOI_LIST_OBJ_IDX : Get internal object id                                                                                          [-1 ... 39]
  @glob_in         FCTSEN_pCDCustomOutput->ABAObj.iABAObjID : ABA object id                 [Range could not be found]
  @glob_in         FCTSEN_pCDCustomOutput->CMSPedestrianOutput.iCMSPedObjID : CMS pedestrian object id        [Range could not be found]
  @glob_in         FCT_pCDHypothesesSen->Header.uiNumOfHypotheses : Number of hypothesis                                                                      [full range of unsigned char]
  @glob_in         FCT_pCDHypothesesSen->Hypothesis : Hypotheses of type Hypothesis_t as defined in Rte_type.h
  @glob_in         pHypo->uiObjectRef : Reference object number                                                                                               [-1 ... 39]

  @glob_out        pHypo->uiObjectRef : Reference object number                                                                                               [-1 ... 39]

  @glob_out        -

  @c_switch_part   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                            and external ID, simply counting up modulo EM_N_OBJECTS with the external ID as defined in fct_config.h
  @c_switch_part   SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING : Configuration switch to enable assignment age based trackign of external IDs
                            (this means the object that has not been OOI for the longest time will have it's ID removed if all external IDs are exhausted as defined in fct_config.h
  @c_switch_part   SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS : Configuration switch, when not set, only the objects that are in the
                            OOI list get external object IDs assigned. Otherwise when set all tracked objects get external object IDs assigned as defined in fct_config.h
  @c_switch_part   FCT_CFG_ASSIGN_EXT_ID_TO_OOI_OBJECTS : FCT support for assigning external id to object of interest objects
  @c_switch_part   FCT_SIMU : Macro to enable simulation debug information
  @c_switch_part   FCT_CFG_TRUCK_CMS_LEVEL : Configuration switch to enable Truck specific CMS Level calculation and stationary object selection on static course  (FCT_CD) as defined in fct_config.h
  @c_switch_part   FCT_CFG_TRUCK_CMS_PED_LEVEL : Configuration switch to enable Truck specific pedestrian CMS level calculation in FCT_CD as defined in fct_config.h
  @c_switch_part   SLATE_CFG_ASSIGN_EXT_ID_CD_HYPOTHESIS : Configuration switch enabling external ID assignment to all objects that get a CD hypothesis assigned as defined in fct_config.h


  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             FCTSenInitExternObjID done & OOI objects selected (so that their external IDs can be assigned)
  @post            External object IDs assigned to OOI objects

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenDetermineExternObjID(void)
{
#if (SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
  FCTSenExtObjId_t iObj;

  /* increment external ID */
  for (iObj = 0u; iObj < (FCTSenExtObjId_t)EM_N_OBJECTS; iObj++)
  {
    /* Deleted objects need to get the no object external ID assigned, but only
    on the external interface (i.e.: without modifying the array FCTIntern2ExternID,
    so that the next object created with the given internal ID gets the next
    object ID */
    if (SLATE_b_GetObjIsDeleted((ObjNumber_t)iObj))
    {
      //OBJ_GET_EXTERNAL_OBJ_ID(iObj) = (uint8)FCT_EXTERN_OBJ_ID_NO_OBJECT;
      SLATE_p_GetFCTPubObj_OOI((ObjNumber_t)iObj)->cExternalID = (uint8)FCT_EXTERN_OBJ_ID_NO_OBJECT;
    }
    else
    {
      /* Non-deleted object need to get an external ID assigned */
      /* New objects need to get a new external ID assigned */
      if (SLATE_b_GetObjIsNew((ObjNumber_t)iObj))
      {
        FCTSenExtObjId_t iNewExtId = FCTIntern2ExternID[iObj];
        /* If there are IDs left to increment to, then do so, otherwise
        start over */
        if (iNewExtId < (FCTSenExtObjId_t)(FCT_NR_EXTERN_OBJECT_ID - FCT_PAR_OBJ_EXT_ID_MODULO))
        {
          iNewExtId += (FCTSenExtObjId_t)FCT_PAR_OBJ_EXT_ID_MODULO;
        }
        else
        {
          iNewExtId = iObj + (FCTSenExtObjId_t)FCT_PAR_OBJ_EXT_ID_OFFSET;
        }
# if (FCT_EXTERN_OBJ_ID_NO_OBJECT < FCT_NR_EXTERN_OBJECT_ID)
        /* If the new ID would be the one reserved for no object, then
        skip to the next modulo external ID */
        if (iNewExtId == (FCTSenExtObjId_t)FCT_EXTERN_OBJ_ID_NO_OBJECT)
        {
          iNewExtId += (FCTSenExtObjId_t)FCT_PAR_OBJ_EXT_ID_MODULO;
        }
# endif
        FCTIntern2ExternID[iObj] = iNewExtId;
      }
      /* Assign the current external object ID to the object */
      //OBJ_GET_EXTERNAL_OBJ_ID(iObj) = FCTIntern2ExternID[iObj];
      SLATE_p_GetFCTPubObj_OOI((ObjNumber_t)iObj)->cExternalID = FCTIntern2ExternID[iObj];
#ifdef FCT_SIMU
      assert((FCTIntern2ExternID[iObj] % FCT_PAR_OBJ_EXT_ID_MODULO) == (iObj + FCT_PAR_OBJ_EXT_ID_OFFSET));
      assert(FCTIntern2ExternID[iObj] != FCT_EXTERN_OBJ_ID_NO_OBJECT);
#endif
    }
  }

#else
  ObjNumber_t nr, iInternID;
  FCTSenExtObjId_t ExtId;

#if (SLATE_CFG_EXT_ID_ASSIGN_AGE_TRACKING)
  /* Increase the age of all external ID assignments (FCTAssignExtIdToObj
  function will reset age to zero when used */
  for (ExtId = (FCTSenExtObjId_t)0; ExtId < (FCTSenExtObjId_t)FCT_NR_EXTERN_OBJECT_ID; ExtId++)
  {
    /* Increase assigned external ID age (will be reset for OOI objects to zero later) */
    if (FCTExtIdAssignAge[ExtId] < FCT_MAX_EXT_ID_ASSIGN_AGE)
    {
      FCTExtIdAssignAge[ExtId]++;
    }
  }
#endif

  /* Go through list of internal objects, and if one was deleted, remove
  the corresponding external object ID assigned (if any) */
  for (nr = (ObjNumber_t)0; nr < (ObjNumber_t)EM_N_OBJECTS; nr++)
  {
    ExtId = FCTIntern2ExternID[nr];

    /* Check if given internal object ID has an external ID assigned */
    if (ExtId != FCT_EXTERN_OBJ_ID_NO_OBJECT)
    {
      /* Yes, an external object ID is assigned. Check if the object has deceased */
      if ( (SLATE_b_GetObjIsDeleted(nr)) || (SLATE_b_GetObjIsNew(nr)) )
      {
        /* Object is new - reset it's assigned external object ID */
        FCTIntern2ExternID[nr]  = FCT_EXTERN_OBJ_ID_NO_OBJECT;
        FCT_SET_EXTERN_ID_FREE(ExtId);
        /* Decrement number of external object Ids used */
        FCTExtIdsUsed--;
      }
    }
  }

#if (SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS)
# ifdef FCT_SIMU
  /* Assertion that we need more external object IDs then internal
  objects when assigning an external object ID for each. Ideally
  this would be a compile-time check (with pre-proc statement), but
  due to the EM_N_OBJECTS object-like macro containing a cast
  can not be done... */
  assert(EM_N_OBJECTS < FCT_NR_EXTERN_OBJECT_ID);
# endif
  /* For all objects set external object ID */
  for (nr = 0; nr < EM_N_OBJECTS; nr++)
  {
    if (!SLATE_b_GetObjIsDeleted(nr))
    {
      FCTAssignExtIdToObj(nr);
    }
  }
#else
  /* If ACC active assign extern IDs to it's objects */
# if (FCT_CFG_SLATE_COMPONENT)
  /* for every relevant object, set it's external object-ID */
  for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
  {
    iInternID = OBJ_GET_OOI_LIST_OBJ_IDX(nr);    /* get the internal object-ID */

    if (iInternID != OBJ_INDEX_NO_OBJECT)
    {
      FCTAssignExtIdToObj(iInternID);
    }
  }
# endif /* FCT_CFG_SLATE_COMPONENT */
#endif  /* SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS */

  /* Copy external object ID to public object list */
  for (nr = 0; nr < EM_N_OBJECTS; nr++)
  {
    const FCTSenExtObjId_t ExtId = FCTIntern2ExternID[nr];
    /* Store external object ID in public list */
    OBJ_GET_EXTERNAL_OBJ_ID(nr) = ExtId;
  }

#ifdef FCT_SIMU
  {
    FCTSenExtObjId_t ExtId;
    FCTSenExtObjId_t UsedIdsInt;
    FCTSenExtObjId_t UsedIdsExt;

    /* Special code to verify that all hashes used are in-tact: first loop
    verifies that for each intern ID with an extern ID assigned, the extern
    ID map has the proper intern ID */
    UsedIdsInt = 0;
    for (nr = 0; nr<EM_N_OBJECTS; nr++)
    {
      ExtId = FCTIntern2ExternID[nr];
      if (ExtId != FCT_EXTERN_OBJ_ID_NO_OBJECT)
      {
        assert(ExtId < FCT_NR_EXTERN_OBJECT_ID);
        assert(FCT_IS_EXTERN_ID_IN_USE(ExtId));
        UsedIdsInt++;
      }
    }
    /* Second loop verifies that all entries in the extern id map have the correct
    intern ID */
    UsedIdsExt = 0;
    for (ExtId = 0; ExtId<FCT_NR_EXTERN_OBJECT_ID; ExtId++)
    {
      if (FCT_IS_EXTERN_ID_IN_USE(ExtId))
      {
        /* Find the corresponding external ID */
        for (nr = 0; (nr<EM_N_OBJECTS) && (FCTIntern2ExternID[nr] != ExtId); nr++);
        assert(nr < EM_N_OBJECTS);
        assert(FCTIntern2ExternID[nr] == ExtId);
        UsedIdsExt++;
      }
    }
    /* Verify that the number of used IDs is correctly tracked */
    assert(UsedIdsInt == UsedIdsExt);
    assert(UsedIdsInt == FCTExtIdsUsed);
    /* Finally verify that all OOI objects have an external ID */
    for(nr = 0; nr < OOI_NUMBER_OF_OOI; nr++)
    {
      iInternID = OBJ_GET_OOI_LIST_OBJ_IDX(nr);    /* get the internal object-ID */

      if (iInternID != OBJ_INDEX_NO_OBJECT)
      {
        ExtId = FCTIntern2ExternID[iInternID];
        assert(ExtId >= 0);
        assert(ExtId < FCT_NR_EXTERN_OBJECT_ID);
      }
    }
  }
#endif
#endif  /* SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */

}


/*************************************************************************************************************************
  Functionname:    FCTSenMergeExtObjID                                                                              */ /*!

  @brief           Determine the external object-ID for merged objects

  @description     Determine the external object-ID for merged objects
                   @startuml
                   Start
                   Partition FCTAssignExtIdToObj
                   If(given ID is already assigned to the object) then (True)
                   Note
    			     An ID is already assigned
		           End note
				  -Do nothing
		          Else
			        - find an ID to assign. For this we primarily search for unused external IDs. If we don't find any then use the oldest assignment if externalID age tracking enabled
		          Endif
                    - Reset age, since an external ID already assigned, and actively used
                  end
                  @enduml

  @return          void

  @param[in]       uiObjectToKeep : Object number to keep                                                                             [-1 ... 39]
  @param[in]       uiObjectToDelete : Object number to delete                                                                         [-1 ... 39]

  @glob_in         FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID                             [full range of unsigned int8]
  @glob_out        FCTIntern2ExternID[EM_N_OBJECTS] : Array of object numbers to store external object-ID                             [full range of unsigned int8]
  @glob_in         OBJ_GET_OOI_POS : Macro to get position of object of interest as defined in fct_sen.h and Rte_Type.h               [-1 ... 5]
  @glob_in         FCT_SET_EXTERN_ID_FREE : Macro to set the given external id's use state as free as defined in the same file.
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS : Configuration switch, when not set, only the objects that are in the
                            OOI list get external object IDs assigned. Otherwise when set all tracked objects get external object IDs assigned

  @c_switch_part   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                            and external ID, simply counting up modulo EM_N_OBJECTS with the external ID

  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             FCTSenInitExternObjID already called
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenMergeExtObjID(ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete)
{
#if (SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
   _PARAM_UNUSED(uiObjectToKeep);
   _PARAM_UNUSED(uiObjectToDelete);
#else
  FCTSenExtObjId_t ExtIDtoKeep;
  FCTSenExtObjId_t ExtIDtoDelete;

  ExtIDtoKeep = FCTIntern2ExternID[uiObjectToKeep];
  ExtIDtoDelete = FCTIntern2ExternID[uiObjectToDelete];

  if (ExtIDtoKeep != FCT_EXTERN_OBJ_ID_NO_OBJECT)
  {
    if (ExtIDtoDelete != FCT_EXTERN_OBJ_ID_NO_OBJECT)
    {
      /* Both objects have an external ID assigned. In this case object to
      keep's ID shall be kept if it's assignment age is less or equal then
      the deleted objects. Otherwise the deleted object's shall be kept */
#if (SLATE_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS)
      /* Keep the external ID assignment of the deleted object if it is part of
      the OOI list, while the kept object is not */
      if ((OBJ_GET_OOI_POS(uiObjectToKeep) == OBJ_NOT_OOI) && (OBJ_GET_OOI_POS(uiObjectToDelete) != OBJ_NOT_OOI))
      {
        /* Assign the deleted object's external ID assignment to the kept one */
        FCTIntern2ExternID[uiObjectToKeep]    = ExtIDtoDelete;
        FCTIntern2ExternID[uiObjectToDelete]  = FCT_EXTERN_OBJ_ID_NO_OBJECT;

        FCT_SET_EXTERN_ID_FREE(ExtIDtoKeep);
      }
      else
#endif
      {
        /* Keep the kept object's external ID assignment */
        FCTIntern2ExternID[uiObjectToDelete]  = FCT_EXTERN_OBJ_ID_NO_OBJECT;
        FCT_SET_EXTERN_ID_FREE(ExtIDtoDelete);
      }
      /* Decrement the number of external IDs used */
      FCTExtIdsUsed--;
    }
    else
    {
      /* Object to be deleted has no external ID assigned - nothing to do */
    }
  }
  else
  {
    if (ExtIDtoDelete != FCT_EXTERN_OBJ_ID_NO_OBJECT)
    {
      /* Only the deleted object had an external ID assigned, move that to the
      object to be kept. */
      FCTIntern2ExternID[uiObjectToKeep]    = ExtIDtoDelete;
      FCTIntern2ExternID[uiObjectToDelete]  = FCT_EXTERN_OBJ_ID_NO_OBJECT;
    }
    else
    {
      /* Nothing to do, neither object had external ID assigned */
    }
  }
#endif  /* SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO */
}


/*************************************************************************************************************************
  Functionname:    FCTSenGetObjExtID                                                                                */ /*!

  @brief           Get the external object-ID

  @description     Get the external object-ID
                   @startuml
                   Start 
                   Partition FCTSenGetObjExtID
                    If(given object is with in EM object list)then (True)
                   -Get the external object-ID of a given object 
                   endif
                   end
                   @enduml


  @return          FCTSenExtObjId_t : External id of given object                                  [full range of unsigned int]

  @param[in]       ObjNr : Object number                                                           [-1 ... 39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | 
*************************************************************************************************************************/
FCTSenExtObjId_t FCTSenGetObjExtID(ObjNumber_t const ObjNr)
{
  FCTSenExtObjId_t ExtObjId;

  ExtObjId = FCT_EXTERN_OBJ_ID_NO_OBJECT;

  if( (ObjNr >= 0) && (ObjNr < EM_N_OBJECTS) )
  {
    ExtObjId = FCTIntern2ExternID[ObjNr];
  }

  return (FCTSenExtObjId_t) ExtObjId;
}


/*************************************************************************************************************************
  Functionname:    FCTSenSetObjExtID                                                                                */ /*!

  @brief           Set the external object-ID from another file

  @description     Set the external object-ID from another file
                   @startuml
                   Start 
                   Partition FCTSenSetObjExtID
                   If(given object is with in EM object list)then (True)
                   -Set the external object-ID
                   endif
                   end
                   @enduml


  @return          void

  @param[in]       ObjNr : Index of the object that is merged and into which the old object was merged           [-1 ... 39]
  @param[in]       u_ExtID : External id to be assigned                                                          [full range of unsigned int]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/10/2016

  @author          Marie-Theres Boll | Marie-Theres.Boll@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenSetObjExtID(ObjNumber_t const ObjNr, FCTSenExtObjId_t const u_ExtID)
{
  if( (ObjNr >= 0) && (ObjNr < EM_N_OBJECTS) )
  {
    FCTIntern2ExternID[ObjNr] = u_ExtID;
  }
}

#if 0 /* Unused */
/* **************************************************************************** 

  @fn             FCTSenGetAssignObjExtID                      */ /*!  

  @brief           Get the external object-ID for given object (with assignment)

  @description     Get the external object-ID for a given object. If the object does not yet have one assigned, 
                   this will assign one to it.
				   @startuml
                   Start 
                   Partition FCTSenGetAssignObjExtID  {
                   If(object is not assigned with external object ID) then(true)
                   -assign external ID to the object 
                   -Get the external object-ID for given object
                   endif
                   }
                   end
                   @enduml


  @return          FCTSenExtObjId_t : External object id                                            [full range of unsigned int]

  @param[in]       ObjNr : Object number for external id needs to be provided                       [-1 ... 39]

  @glob_in         -
  @glob_out        -

  @c_switch_part   SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO : Configuration switch to enable 1-1 mapping between internal ID
                                               and external ID, simply counting up modulo EM_N_OBJECTS with the external ID
  @c_switch_full   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment


  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
FCTSenExtObjId_t FCTSenGetAssignObjExtID(ObjNumber_t const ObjNr)
{
  FCTSenExtObjId_t ExtObjId = FCTSenGetObjExtID(ObjNr);

#if (!SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
  if (ExtObjId == FCT_EXTERN_OBJ_ID_NO_OBJECT)
  {
    FCTAssignExtIdToObj(ObjNr);
    ExtObjId = FCTSenGetObjExtID(ObjNr);
  }
#endif

  return (FCTSenExtObjId_t) ExtObjId;
}
#endif

#endif    /* #if SLATE_CFG_USE_EXT_OBJ_ID */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

