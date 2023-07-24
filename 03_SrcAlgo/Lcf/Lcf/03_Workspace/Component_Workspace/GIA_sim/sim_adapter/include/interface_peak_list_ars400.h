/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            interface_peak_list_ars400

  DESCRIPTION:          ARS400 peak list layout header file (all versions)

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        07.02.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interface_peak_list_ars400.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:24CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:56:10CET ungvaryg 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/include/project.pj


**************************************************************************** */
#ifndef INTERFACE_PEAK_LIST_ARS400
#define INTERFACE_PEAK_LIST_ARS400

//
// Peak-list used up to rte_type.h version 1.27.1.14 (inclusive),
// up to ARS400_algo_interface_types.xls 1.24 (inclusive)
//
namespace PeakListV0
{
  typedef unsigned short a_NoisePowDistr_array_t[16];/* Distribution of OS 396/198 in log2 over 16 beams in this range gate */

  typedef unsigned short a_MedianPowDistr_array_t[16];/* Distribution of OS 256/128 in log2 over 16 beams in this range gate */

  typedef unsigned short a_MaxPowDsitr_array_t[16];/* Distribution of maxima over 16 beams in this range gate */

  typedef struct
  {
    a_NoisePowDistr_array_t a_NoisePowDistr;
    a_MedianPowDistr_array_t a_MedianPowDistr;
    a_MaxPowDsitr_array_t a_MaxPowDsitr;
    unsigned short u_MaxPower;
    unsigned short u_NofDetections;
    unsigned short u_IdxRaDoCellPL;
    unsigned short u_unusedGap;
  } FPGA_t_RangeCell;

  static const unsigned int NumFarPeaks = 112;
  static const unsigned int NumNearPeaks = 256;

  typedef FPGA_t_RangeCell          a_RangeCell_array_t_Far[NumFarPeaks];
  typedef FPGA_t_RangeCell          a_RangeCell_array_t_Near[NumNearPeaks];

  typedef struct FPGA_t_StaticPlFar
  {
    a_RangeCell_array_t_Far a_RangeCell;
  } FPGA_t_StaticPlFar;

  typedef struct FPGA_t_StaticPlNear
  {
    a_RangeCell_array_t_Near a_RangeCell;
  } FPGA_t_StaticPlNear;
};  // End of namespace PeakListV0

//
// Updated peak-list starting from rte_type.h version 1.27.1.15,
// starting from ARS400_algo_interface_types.xls 1.25
//
namespace PeakListV1
{
  static const unsigned int NumFarPeaks = 128;
  static const unsigned int NumNearPeaks = 128;

  typedef PeakListV0::FPGA_t_RangeCell a_RangeCell_array_t_2[NumFarPeaks];/* RangeCell of static PL */

  typedef PeakListV0::FPGA_t_RangeCell a_RangeCell_array_t_3[NumNearPeaks];/* RangeCell of static PL */

  typedef struct FPGA_t_StaticPlFar
  {
    a_RangeCell_array_t_2 a_RangeCell;
  } FPGA_t_StaticPlFar; /* @vaddr:FPGA_VADDR_STATIC_PL_FAR @cycleid:FPGA_ENV @vname:FPGA_t_StaticPlFar */

  typedef struct FPGA_t_StaticPlNear
  {
    a_RangeCell_array_t_3 a_RangeCell;
  } FPGA_t_StaticPlNear;  /* @vaddr:FPGA_VADDR_STATIC_PL_NEAR @cycleid:FPGA_ENV @vname:FPGA_t_StaticPlNear */
};  // End of namespace PeakListV1

#endif
