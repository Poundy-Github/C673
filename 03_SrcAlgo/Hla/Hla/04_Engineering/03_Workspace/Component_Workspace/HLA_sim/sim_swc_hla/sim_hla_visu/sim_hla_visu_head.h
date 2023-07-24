/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_hla_visu_head.h

  DESCRIPTION:            Virtual class providing important data for all child
                          classes

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.5 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_HLA_VISU_HEAD_H
#define SIM_HLA_VISU_HEAD_H

#include "stdafx.h"
#include "sim_swc_draw_base.h"
#include "sim_renderparam_helper.h"
#include "hla_evm_hil_ports.h"
#include "sim_visu_type.h"
#include "sim_hla_measdata.h"
#include "sim_hla_visu_table.h"
#include "sim_visu_color.h"
#include "sim_visu_menusub.h"

const string MENU_BUTTON_FUNC_OUTPUT          = "[o]utput";
const string MENU_BUTTON_FUNC_MATRIX          = "[m]atrix";
const string MENU_BUTTON_FUNC_MATRIX_S_NONE   = "";
const string MENU_BUTTON_FUNC_MATRIX_S_CAM    = "Cam";
const string MENU_BUTTON_FUNC_MATRIX_S_CAMANG = "Cam Angle";
const string MENU_BUTTON_FUNC_HB_DATA         = "[h]igh beam data";

const string MENU_BUTTON_DIAG_TIMEMEAS           = "Time [m]easurement";
const string MENU_BUTTON_DIAG_HLSTATEREQ         = "HL-[s]tateRequest";
const string MENU_BUTTON_DIAG_HLSTATEREQ_S_SMALL = "small";
const string MENU_BUTTON_DIAG_HLSTATEREQ_S_BIG   = "big";
const string MENU_BUTTON_DIAG_HLSTATEREQ_S_ALL   = "all";
const string MENU_BUTTON_DIAG_DATABLABEL         = "Data[b]ase lable";

const string MENU_BUTTON_INTF_BUS        = "bus [i]nput";
const string MENU_BUTTON_INTF_LSD        = "[l]sd input";
const string MENU_BUTTON_INTF_EMOBJECT   = "[e]m Objects";
const string MENU_BUTTON_INTF_DIMMING    = "[d]imming";
const string MENU_BUTTON_INTF_LIGHT_SIZE = "li[g]ht size";

const string MENU_BUTTON_GEN_ERRORLIST          = "[e]rror List";
const string MENU_BUTTON_GEN_ERRORLIST_S_NONE   = "";
const string MENU_BUTTON_GEN_ERRORLIST_S_ALL    = "all";
const string MENU_BUTTON_GEN_ERRORLIST_S_NOINFO = "no information";
const string MENU_BUTTON_GEN_ERRORLIST_S_NOWARN = "no warnings";
const string MENU_BUTTON_GEN_HORIZON            = "[h]orizont";
const string MENU_BUTTON_GEN_ROI                = "[r]oi";
const string MENU_BUTTON_GEN_VEHINFO            = "[v]ehicle Info";
const string MENU_BUTTON_GEN_RESET              = "[R]eset";

const string MENU_BUTTON_PLANE_SIL = "[1]SIL";
const string MENU_BUTTON_PLANE_ECU = "[2]ECU";
const string MENU_BUTTON_PLANE_EVM = "[3]EVM";
const string MENU_BUTTON_PLANE_ETH = "[4]ETH";
const string MENU_BUTTON_PLANE_CAN = "[5]CAN";

class CSimHlaVisuHead : public CSimColor
{
public:
  CSimHlaVisuHead ();
  ~CSimHlaVisuHead ();


  /* public members */
  const reqHlaPrtList_t*                pm_rteInputs;
  const SimHlaProPrtList_t*             pm_rteOutputs;
  const SimHlaInternMeasdataList_t*     pm_hlaInternMeasdata;
  const SimHlaMeasdata_t*               pm_hlaMeasdata;

  /* Important: m_keyboardInfo and m_mouseInfo must only be read in drawFunction thread. 
     Only the OnKeyboardMessage and OnMouseMessage events shall be stored. */
  t_KeyboardInfo m_keyboardInfo;
  t_MouseInfo m_mouseInfo;

  SimuLockedObjects     m_lockedObjects;
  uint8                 m_drawPlane;
  color_e               m_drawColor;
  int                   m_activePlane;

  /* roi data */
  RoiData m_HLARoi;
  RoiData m_SilRoi;
  RoiData m_SilColorRoi;

  int m_DrawImageOffsetX;
  int m_DrawImageOffsetY;

  void update_drawColor(int measfreezeVisu); 

protected:

private:

};

#endif //SIM_HLA_VISU_HEAD_H