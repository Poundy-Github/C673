/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_error.cpp

  DESCRIPTION:            Drawing of error messages

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.10 $

  ---*/ /*---

**************************************************************************** */
#include "stdafx.h"

#include "sim_hla_visu_error.h"

#include "resource.h"

#include "sim_swc_gdv_ifc.h"
#include "sim_gdvfont_ifc.h"

#include <string>
#include <cmath>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLu32.lib")


CSimHlaVisuError::CSimHlaVisuError()
//: 
{
}

CSimHlaVisuError::~CSimHlaVisuError()
{
}

void CSimHlaVisuError::Init()
{
  m_delayedErrorListVis.m_errorList.clear();
  for(int i = 0; i <= VISU_MAX; i++)
  {
    m_delayedErrorList[i].m_errorList.clear();
  }
}

void CSimHlaVisuError::drawErrorStack( const ISimRenderContext*          pContext,
                                       const bool                        m_algoWasExecuted,
                                       const int                         activePlane,
                                       const int                         activeErrorList,
                                       const t_ErrorHandling_ErrorStack* pHLAErrorStack,
                                             int&                        textPosX,
                                             int                         menuHeight /* =0 */
                                      )
{
  const int textHeight = 13;
  const int textPosY   = m_HLARoi.Y2 + 107 + menuHeight + 5;

  /* Return if error list is deactivated */
  if(activeErrorList == 0)
  {
    return;
  }

  /* Reduce counter every time the algo was executed */
  if(m_algoWasExecuted)
  {
    m_delayedErrorList[activePlane].update();
  }

  if(   (pHLAErrorStack == NULL)
     || (pHLAErrorStack->hashErrors == 0u)
     || (pHLAErrorStack->hashWarnings == 0u)
     || (pHLAErrorStack->hashInformation == 0u)
    )
  {
    /* It seems that error stack measfreeze is not correctly connected */
    CSimTable errorStackTable(12, "Arial", color_white, color_white, color_white);

    errorStackTable.SetCell(0, COL_0, "Error stack measfreeze not properly connected", m_drawColor);
    errorStackTable.SetPos(textPosX, textPosY);
    errorStackTable.draw(pContext, color_red);
    textPosX += errorStackTable.getTableWidth() +10;
  } 
  else
  {
    if(   (pHLAErrorStack->hashErrors != HLA_ERROR_HASH_ERRORS)
       || (pHLAErrorStack->hashWarnings != HLA_ERROR_HASH_WARNINGS)
       || (pHLAErrorStack->hashInformation != HLA_ERROR_HASH_INFORMATION)
      )
    {
      /* Enums of error stack measfreeze and current one are no longer matching */
      CSimTable errorStackTable(12, "Arial", color_white, color_white, color_white);

      errorStackTable.SetCell(0, COL_0, "MEAS/VISU INTERFACES OF ERROR STACK NOT MATCHING", m_drawColor);
      errorStackTable.SetPos(textPosX, textPosY);
      errorStackTable.draw(pContext, color_red);
      textPosX += errorStackTable.getTableWidth() +10;
    } 
    else
    {
      /* Add Errors to the list */
      fillDelayedErrorList( pHLAErrorStack, 
                            activePlane,
                            m_delayedErrorList[activePlane]
                           );
      
      /* Draw errors */
      drawErrors( pContext,
                  m_delayedErrorList[activePlane],
                  false,
                  textPosX,
                  textPosY
                 );
      
      /* draw warnings only if activated */
      if(activeErrorList < 3)
      {
        drawWarnings( pContext,
                      m_delayedErrorList[activePlane],
                      textPosX,
                      textPosY
                     );
      }
      /* draw information only if activated */
      if(activeErrorList < 2)
      {
        drawInformation( pContext,
                         m_delayedErrorList[activePlane],
                         textPosX,
                         textPosY
                        );
      }
    }
  }
}


void CSimHlaVisuError::s_delayedErrorList::insertError( const int         errSource,  
                                                        const uint32      errorBit
                                                      )                                                        
{
  insertElement(errSource, errorBit, m_errorList);
}

void CSimHlaVisuError::s_delayedErrorList::insertWarning( const int         errSource,  
                                                          const uint32      errorBit
                                                        )                                                        
{
  insertElement(errSource, errorBit, m_warningList);
}

void CSimHlaVisuError::s_delayedErrorList::insertInformation( const int         errSource, 
                                                              const uint32      errorBit
                                                            )
{
  insertElement(errSource, errorBit, m_informationList);
}


void CSimHlaVisuError::s_delayedErrorList::insertElement( const int         errSource, 
                                                          const uint32      errorBit,
                                                                ErrorList&  list
                                                        )                                                        
{
  ErrorItem errorItem;

  /* Fill error item so that we can add it to error list later on */
  errorItem.counter   = fadeOutFrames;
  errorItem.errSource = errSource;
  errorItem.errBit    = errorBit;

  /* Try to find this the new entry in the error list */
  for (ErrorList::iterator it = list.begin(); it != list.end(); ++it)
  {
    if(   (errSource == it->errSource)
       && (errorBit  == it->errBit)
      )
    {
      /* we found it -> erase as we want to add it later on to make sure it's at the end of the list */
      it = list.erase(it);
      break;
    }
  }

  /* Add entry at the end of the list */
  list.push_back(errorItem);
}

void CSimHlaVisuError::s_delayedErrorList::update()
{
  updateList(m_errorList);
  updateList(m_warningList);
  updateList(m_informationList);
}


void CSimHlaVisuError::s_delayedErrorList::updateList(ErrorList& list)
{
  ErrorList::iterator it = list.begin();

  while(it != list.end())
  {
    it->counter--;

    if (it->counter <= 0)
    {
      it = list.erase(it);
    }
    else
    {
      ++it;
    }
  }
}


void CSimHlaVisuError::fillDelayedErrorList( const t_ErrorHandling_ErrorStack* pHLAErrorStack,
                                             const int                         errSource,
                                                   s_delayedErrorList&         errorList
                                            )
{
  /* ERRORS */
  /* Loop over all bits in error array */
  for(int errorBit = 0; errorBit < HLA_ERROR_LAST_ENUM_ENTRY; errorBit++)
  {
    /* Create one entry in the delayedErrorList for every error in error stack */
    if(CML_GetBit(pHLAErrorStack->errors[errorBit >> 5u], 1u << (errorBit & 31u)) == b_TRUE)
    {
    /* Right shift by 5 is equal to integer division by 32, 
     * i.e. we can extract which bit field is affected .
     * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
     */
      errorList.insertError(errSource, errorBit);
    }
  }

  /* WARNINGS */
  /* Loop over all bits in warning array */
  for(int warningBit = 0; warningBit < HLA_WARNING_LAST_ENUM_ENTRY; warningBit++)
  {
    /* Create one entry in the delayedErrorList for every error in error stack */
    if(CML_GetBit(pHLAErrorStack->warnings[warningBit >> 5u], 1u << (warningBit & 31u)) == b_TRUE)
    {
    /* Right shift by 5 is equal to integer division by 32, 
     * i.e. we can extract which bit field is affected .
     * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
     */
      errorList.insertWarning(errSource, warningBit);
    }
  }

  /* INFORMATION */
  /* Loop over all bits in error array */
  for(int informationBit = 0; informationBit < HLA_INFORMATION_LAST_ENUM_ENTRY; informationBit++)
  {
    /* Create one entry in the delayedErrorList for every information in error stack */
    if(CML_GetBit(pHLAErrorStack->information[informationBit >> 5u], 1u << (informationBit & 31u)) == b_TRUE)
    {
    /* Right shift by 5 is equal to integer division by 32, 
     * i.e. we can extract which bit field is affected .
     * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
     */
      errorList.insertInformation(errSource, informationBit);
    }
  }
}

void CSimHlaVisuError::drawErrors( const ISimRenderContext* pContext,
                                   const s_delayedErrorList delayedErrorList,
                                         bool               drawdebug,
                                         int&               textPosX,
                                         int                textPosY
                                   )
{
  CSimTable errorList(7, "Arial", color_grey, color_light_grey, color_white);
  uint16 row = 0;
  color_e drawColor = m_drawColor;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  /* Draw headline of error box */
  errorList.SetCell(row, COL_0, "ERROR list", color_yellow);

  /* Draw errors only if list is not empty */
  if(!delayedErrorList.m_errorList.empty())
  {      
    /* Main loop over every error in the list */
    for ( s_delayedErrorList::ErrorList::const_reverse_iterator it = delayedErrorList.m_errorList.rbegin();
          it != delayedErrorList.m_errorList.rend();
          it++
          )
    {
      switch(it->errBit)
      {
/* ### START_GENERATED_ERRORS ### */
      case HLA_ERROR_PRO_PORT_NULL_POINTER_LIST:
        errorList.SetCell(++row, COL_0, "PRO_PORT_NULL_POINTER_LIST", drawColor);
        break;
      case HLA_ERROR_PRO_PORT_NULL_POINTER_COMP_STATE:
        errorList.SetCell(++row, COL_0, "PRO_PORT_NULL_POINTER_COMP_STATE", drawColor);
        break;
      case HLA_ERROR_PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL:
        errorList.SetCell(++row, COL_0, "PRO_PORT_NULL_POINTER_HEADLIGHT_CONTROL", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_LIST:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_LIST", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_ADD_RTA_EVENT:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_ADD_RTA_EVENT", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_MEAS_START_CYCLE:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_MEAS_START_CYCLE", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_MEAS_FREEZE:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_MEAS_FREEZE", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_DEM_SET_EVENT:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_DEM_SET_EVENT", drawColor);
        break;
      case HLA_ERROR_SERVICES_NULL_POINTER_DEM_EXT_DATA:
        errorList.SetCell(++row, COL_0, "SERVICES_NULL_POINTER_DEM_EXT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_LIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_LIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_BASE_CONTROL_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_CPAR_HLAF:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_CPAR_HLAF", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_BASE_CONTROL_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_CPAR_HLAF:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_CPAR_HLAF", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_VERSION_NUMBER_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_BASE_CONTROL_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_BASE_CONTROL_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_CPAR_HLAF:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_CPAR_HLAF", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INIT_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_CPAR_HLAF:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_CPAR_HLAF", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_INVALID_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_BASE_CONTROL_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_BASE_CONTROL_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_CPAR_HLAF_PAR:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_CPAR_HLAF_PAR", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_MONO_CALI:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VEH_SIG:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_VEH_SIG", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_VDY_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_VDY_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_BLOCKAGE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_BLOCKAGE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_YAW_RATE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_YAW_RATE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_CURVE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_CURVE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_VELOCITY:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_VELOCITY", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_ACCELERATION:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_ACCELERATION", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_MOTION_STATE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_MOTION_STATE", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_DISPLAY_SPEED", drawColor);
        break;
      case HLA_ERROR_REQ_PORTS_BUS_SIG_STATE_WIPER_STATE:
        errorList.SetCell(++row, COL_0, "REQ_PORTS_BUS_SIG_STATE_WIPER_STATE", drawColor);
        break;
      case HLA_ERROR_CRITICAL_INPUTS_MONO_CALI:
        errorList.SetCell(++row, COL_0, "CRITICAL_INPUTS_MONO_CALI", drawColor);
        break;
      case HLA_ERROR_CRITICAL_INPUTS_VDY:
        errorList.SetCell(++row, COL_0, "CRITICAL_INPUTS_VDY", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_ALGO_CONFIG_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_KEEP_ON_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_TURN_ON_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_TURN_OFF_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_SPEED_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_MATRIX_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_MATRIX_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_RANGE_CHECK_HLAF_DIMMING_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_KEEP_ON_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_PLAUSIBILITY_CHECK_HLAF_KEEP_ON_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_PLAUSIBILITY_CHECK_HLAF_TURN_ON_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_CPAR_PLAUSIBILITY_CHECK_HLAF_SPEED_PARAMETERS:
        errorList.SetCell(++row, COL_0, "CPAR_PLAUSIBILITY_CHECK_HLAF_SPEED_PARAMETERS", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_SIG_STATE:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_SIG_STATE", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_HEADLIGHTCONTROL:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_OBJID", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_OBJID", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_OBJID", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_OBJID", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_OBJID", drawColor);
        break;
      case HLA_ERROR_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID:
        errorList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_MINLIGHT_OBJID", drawColor);
        break;
      case HLA_ERROR_BLOCKAGE_NO_VALID_INPUT:
        errorList.SetCell(++row, COL_0, "BLOCKAGE_NO_VALID_INPUT", drawColor);
        break;
      case HLA_ERROR_LAST_ENUM_ENTRY:
        errorList.SetCell(++row, COL_0, "LAST_ENUM_ENTRY", drawColor);
        break;
/* ### END_GENERATED_ERRORS ### */
      default:
        _snprintf(tmpTxt, maxTxt, "!!! UNKNOWN ERROR: %i !!!", it->errBit);
        errorList.SetCell(++row, COL_0, tmpTxt, drawColor);
        break;
      }
      _snprintf(tmpTxt, maxTxt, "%i", delayedErrorList.fadeOutFrames - it->counter);
      errorList.SetCell(row, COL_1, tmpTxt, drawColor);
    }
  }
  errorList.SetPos(textPosX, textPosY);
  errorList.draw(pContext, color_red);
  textPosX += errorList.getTableWidth() +10;
}

void CSimHlaVisuError::drawWarnings( const ISimRenderContext* pContext,
                                     const s_delayedErrorList delayedErrorList,
                                           int&               textPosX,
                                           int                textPosY
                                     )
{
  CSimTable warningList(7, "Arial", color_grey, color_light_grey, color_white);
  uint16 row = 0;
  color_e drawColor = m_drawColor;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];

  /* Draw headline of warning box */
  warningList.SetCell(row, COL_0, "WARNING list", color_yellow);

  /* Draw warnings only if list is not empty */
  if(!delayedErrorList.m_warningList.empty())
  {    
    /* Main loop over every warning in the list */
    for ( s_delayedErrorList::ErrorList::const_reverse_iterator it = delayedErrorList.m_warningList.rbegin();
          it != delayedErrorList.m_warningList.rend();
          it++
          )
    {
      switch(it->errBit)
      {
/* ### START_GENERATED_WARNINGS ### */
      case HLA_WARNING_REQ_PORTS_SIG_STATE_CPAR_HLAF:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_CPAR_HLAF", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_MONO_CALI:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_MONO_CALI", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_HLA_BUS_INPUT_SIGNALS", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_VEH_SIG:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_VEH_SIG", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_VDY_DATA:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_VDY_DATA", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_BLOCKAGE:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_BLOCKAGE", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_LSD_ENVIRONMENT_DATA", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_LSD_LIGHTOBJECTLIST", drawColor);
        break;
      case HLA_WARNING_REQ_PORTS_SIG_STATE_LSD_LIGHTLIST:
        warningList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_LSD_LIGHTLIST", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_ALGO_CONFIG_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_KEEP_ON_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_ON_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_TURN_OFF_DELAY_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_SPEED_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_MATRIX_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS:
        warningList.SetCell(++row, COL_0, "CPAR_DIFF_TO_DEFAULTS_HLAF_DIMMING_PARAMETERS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_COMP_STATE_INTERFACE_VERSION:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_COMP_STATE_INTERFACE_VERSION", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SIG_STATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_COMP_STATE_SIG_STATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_COMP_STATE_COMP_STATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_COMP_STATE_COMP_STATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_COMP_STATE_SCHEDULER_SUBMODE_REQUEST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_COMP_STATE_ALGO_QUALIFIER:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_COMP_STATE_ALGO_QUALIFIER", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_NVM_HLAR_LEARNINGVALUES:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_NVM_HLAR_LEARNINGVALUES", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_HLAFUNCTIONSTATUS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TRAFFICSTYLE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_CITYSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_WEATHERSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_TUNNELSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_MOTORWAYSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_BRIGHTNESSSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SENSMODE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SPEEDSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_HEADLIGHTCONTROL_COMMON_SCENEINFO", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_NGFA:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_NGFA", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_GFASTATUS:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_GFASTATUS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_HIGHBEAMSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_DIST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_LOWBEAM_DIST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_ANG:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_LOWBEAM_ANG", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_LOWBEAM_STATUS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIX_TURNOFFREASON:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIX_TURNOFFREASON", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DIST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DIST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG_CAM:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_ANG_CAM", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTSTATE", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLEFT_DISTRELIABILITY", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_DIST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_DIST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG_CAM:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYRIGHT_ANG_CAM", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_ANG_CAM:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYLOWER_ANG_CAM", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_ANG_CAM:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_BNDRYUPPER_ANG_CAM", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_DIST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_DIST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_ANG:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_CLOSESTOBJ_ANG", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_DIST:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_MINLIGHT_DIST", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_MINLIGHT_ANG:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_MINLIGHT_ANG", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_TTB18LEFT", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_TTB18LEFT_STATUS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_TTB18RIGHT:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_TTB18RIGHT", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_MATRIXGFA_EXISTENCEPROB:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_MATRIXGFA_EXISTENCEPROB", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_LIGHTDIMMING_DIMMINGSTATUS", drawColor);
        break;
      case HLA_WARNING_OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA:
        warningList.SetCell(++row, COL_0, "OUTPUT_CHECK_LIGHTDIMMING_DIMMINGAREA", drawColor);
        break;
      case HLA_WARNING_ROI_LIMITED_TOP:
        warningList.SetCell(++row, COL_0, "ROI_LIMITED_TOP", drawColor);
        break;
      case HLA_WARNING_ROI_LIMITED_BOTTOM:
        warningList.SetCell(++row, COL_0, "ROI_LIMITED_BOTTOM", drawColor);
        break;
      case HLA_WARNING_ROI_LIMITED_LEFT:
        warningList.SetCell(++row, COL_0, "ROI_LIMITED_LEFT", drawColor);
        break;
      case HLA_WARNING_ROI_LIMITED_RIGHT:
        warningList.SetCell(++row, COL_0, "ROI_LIMITED_RIGHT", drawColor);
        break;
      case HLA_WARNING_OUT_OF_RANGE_ROI_HEIGHT:
        warningList.SetCell(++row, COL_0, "OUT_OF_RANGE_ROI_HEIGHT", drawColor);
        break;
      case HLA_WARNING_OUT_OF_RANGE_ROI_WIDTH:
        warningList.SetCell(++row, COL_0, "OUT_OF_RANGE_ROI_WIDTH", drawColor);
        break;
      case HLA_WARNING_OUT_OF_RANGE_FOE_X:
        warningList.SetCell(++row, COL_0, "OUT_OF_RANGE_FOE_X", drawColor);
        break;
      case HLA_WARNING_OUT_OF_RANGE_FOE_Y:
        warningList.SetCell(++row, COL_0, "OUT_OF_RANGE_FOE_Y", drawColor);
        break;
      case HLA_WARNING_TIME_DIFF_BETWEEN_TWO_CYCLES_TOO_BIG:
        warningList.SetCell(++row, COL_0, "TIME_DIFF_BETWEEN_TWO_CYCLES_TOO_BIG", drawColor);
        break;
      case HLA_WARNING_LAST_ENUM_ENTRY:
        warningList.SetCell(++row, COL_0, "LAST_ENUM_ENTRY", drawColor);
        break;
/* ### END_GENERATED_WARNINGS ### */
      default:
        _snprintf(tmpTxt, maxTxt, "!!! UNKNOWN WARNING: %i !!!", it->errBit);
        warningList.SetCell(++row, COL_0, tmpTxt, drawColor);
        break;
      }
      _snprintf(tmpTxt, maxTxt, "%i", delayedErrorList.fadeOutFrames - it->counter);
      warningList.SetCell(row, COL_1, tmpTxt, drawColor);
    }
  }
  warningList.SetPos(textPosX, textPosY);
  warningList.draw(pContext, color_red);
  textPosX += warningList.getTableWidth() +10;
}


void CSimHlaVisuError::drawInformation( const ISimRenderContext* pContext,
                                        const s_delayedErrorList delayedErrorList,
                                              int&               textPosX,
                                              int                textPosY
                                        )
{
  CSimTable informationList(7, "Arial", color_grey, color_light_grey, color_white);
  uint16 row = 0;
  color_e drawColor = m_drawColor;
  /* temporary text buffer */
  const size_t maxTxt = 100;
  char tmpTxt[maxTxt];


  /* Draw headline of warning box */
  informationList.SetCell(row, COL_0, "INFORMATION list", color_yellow);

  /* Draw information only if list is not empty */
  if(!delayedErrorList.m_informationList.empty())
  {    
    /* Main loop over every warning in the list */
    for ( s_delayedErrorList::ErrorList::const_reverse_iterator it = delayedErrorList.m_informationList.rbegin();
          it != delayedErrorList.m_informationList.rend();
          it++
          )
    {
      switch(it->errBit)
      {
/* ### START_GENERATED_INFOS ### */
      case HLA_INFORMATION_REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_EM_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_NULL_POINTER_HLA_RADAR_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_EM_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_VERSION_NUMBER_HLA_RADAR_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_VERSION_NUMBER_HLA_RADAR_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_SIG_STATE_EM_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_EM_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_SIG_STATE_HLA_RADAR_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_SIG_STATE_HLA_RADAR_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_EM_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_TIMESTAMP_HLA_RADAR_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_EM_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_REQ_PORTS_MEAS_COUNTER_HLA_RADAR_OBJECT_LIST:
        informationList.SetCell(++row, COL_0, "REQ_PORTS_MEAS_COUNTER_HLA_RADAR_OBJECT_LIST", drawColor);
        break;
      case HLA_INFORMATION_CALIBRATION_DIFF_TO_EMO_CALI:
        informationList.SetCell(++row, COL_0, "CALIBRATION_DIFF_TO_EMO_CALI", drawColor);
        break;
      case HLA_INFORMATION_CALIBRATION_INPUT_QUALI:
        informationList.SetCell(++row, COL_0, "CALIBRATION_INPUT_QUALI", drawColor);
        break;
      case HLA_INFORMATION_EDMA_COPY_FAILED:
        informationList.SetCell(++row, COL_0, "EDMA_COPY_FAILED", drawColor);
        break;
      case HLA_INFORMATION_EDMA_WAIT_FAILED:
        informationList.SetCell(++row, COL_0, "EDMA_WAIT_FAILED", drawColor);
        break;
      case HLA_INFORMATION_SCRATCHBUF_L2_NOT_AVAILABLE:
        informationList.SetCell(++row, COL_0, "SCRATCHBUF_L2_NOT_AVAILABLE", drawColor);
        break;
      case HLA_INFORMATION_SCRATCHBUF_LOCK_FAILED:
        informationList.SetCell(++row, COL_0, "SCRATCHBUF_LOCK_FAILED", drawColor);
        break;
      case HLA_INFORMATION_SCRATCHBUF_UNLOCK_FAILED:
        informationList.SetCell(++row, COL_0, "SCRATCHBUF_UNLOCK_FAILED", drawColor);
        break;
      case HLA_INFORMATION_LAST_ENUM_ENTRY:
        informationList.SetCell(++row, COL_0, "LAST_ENUM_ENTRY", drawColor);
        break;
/* ### END_GENERATED_INFOS ### */
      default:
        _snprintf(tmpTxt, maxTxt, "!!! UNKNOWN INFORMATION: %i !!!", it->errBit);
        informationList.SetCell(++row, COL_0, tmpTxt, drawColor);
        break;
      }
      _snprintf(tmpTxt, maxTxt, "%i", delayedErrorList.fadeOutFrames - it->counter);
      informationList.SetCell(row, COL_1, tmpTxt, drawColor);
    }
  }
  informationList.SetPos(textPosX, textPosY);
  informationList.draw(pContext, color_red);
  textPosX += informationList.getTableWidth() +10;
}

