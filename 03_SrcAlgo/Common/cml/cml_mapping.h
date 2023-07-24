/*! \file **********************************************************************

  COMPANY:                   Continental AG, A.D.C. GmbH

  CPU:                       CPU-Independent

  COMPONENT:                 CML (Common Math Library)

  MODULNAME:                 cml_mapping.h

  DESCRIPTION:               name mapping for old components

  AUTHOR:                    Stephan Kaelberer

  CREATION DATE:             03.08.2012

  VERSION:                   $Revision: 1.25 $

  ---*/ /*---
  CHANGES:                   $Log: cml_mapping.h  $
  CHANGES:                   Revision 1.25 2017/11/29 07:33:00CET Kotre, Jeevan (uidk9586) (uidk9586) 
  CHANGES:                   Updated cml_mapping.h as per changes to cml_radar module.
  CHANGES:                   Revision 1.24 2017/11/24 07:48:23CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   cml_mapping updated with function name changes.
  CHANGES:                   Revision 1.23 2017/11/16 15:30:05CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_mapping.h
  CHANGES:                   Revision 1.22 2017/11/16 13:01:36CET Kotre-EXT, Jeevan (uidk9586) 
  CHANGES:                   Updated cml_mapping module with coding guidelines.
  CHANGES:                   Revision 1.21 2017/05/25 14:49:13CEST Thomas, Jyothy (uid22555) 
  CHANGES:                   updated mapping for CML_f_ModTrig
  CHANGES:                   Revision 1.20 2017/05/25 07:01:44CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   Updated function mapping for CML_v_CalcForwardTrafoEgomotionMatrix
  CHANGES:                   Revision 1.19 2015/07/07 07:35:57CEST Arulkumar-EXT, Nandu (uidr5428) 
  CHANGES:                   - undefining RAD2DEG macro before defining to avoid
  CHANGES:                      multiple definitions.
  CHANGES:                   - Added comments -  uidr5428 [Jul 7, 2015 7:35:58 AM CEST]
  CHANGES:                   Change Package : 354072:1 http://mks-psad:7002/im/viewissue?selection=354072
  CHANGES:                   Revision 1.18 2015/01/21 14:28:50CET Brunn, Marcus (brunnm) 
  CHANGES:                   reduction of ECU compiler warnings
  CHANGES:                   --- Added comments ---  brunnm [Jan 21, 2015 2:28:50 PM CET]
  CHANGES:                   Change Package : 292178:1 http://mks-psad:7002/im/viewissue?selection=292178
  CHANGES:                   Revision 1.17 2014/04/07 10:31:17CEST Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed erroneous include protection
  CHANGES:                   --- Added comments ---  uidg6516 [Apr 7, 2014 10:31:17 AM CEST]
  CHANGES:                   Change Package : 227281:3 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.16 2014/03/27 12:30:04CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed some QA-C- and Styleguide-issues
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 27, 2014 12:30:04 PM CET]
  CHANGES:                   Change Package : 227281:2 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.15 2014/03/25 11:31:44CET Schwarzkopf, Sebastian (uidg6516) 
  CHANGES:                   - fixed Doxygen comments
  CHANGES:                   --- Added comments ---  uidg6516 [Mar 25, 2014 11:31:44 AM CET]
  CHANGES:                   Change Package : 227281:1 http://mks-psad:7002/im/viewissue?selection=227281
  CHANGES:                   Revision 1.14 2014/02/04 15:11:24CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - improve code quality
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 4, 2014 3:11:25 PM CET]
  CHANGES:                   Change Package : 159154:34 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.13 2013/07/08 13:08:41CEST Schlensag, Andreas (schlensaga) 
  CHANGES:                   Add matrix transpose function
  CHANGES:                   --- Added comments ---  schlensaga [Jul 8, 2013 1:08:43 PM CEST]
  CHANGES:                   Change Package : 185100:3 http://mks-psad:7002/im/viewissue?selection=185100
  CHANGES:                   Revision 1.12 2013/05/26 23:04:56CEST Kozek-EXT, Werner (uidt8688) 
  CHANGES:                   update according to current update to cml_mtrx.c (new matrix manipulation methods related
  CHANGES:                   to Cholesky factorization)
  CHANGES:                   --- Added comments ---  uidt8688 [May 26, 2013 11:04:56 PM CEST]
  CHANGES:                   Change Package : 177735:1 http://mks-psad:7002/im/viewissue?selection=177735
  CHANGES:                   Revision 1.11 2013/05/14 09:25:37CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - clean up float and int macros
  CHANGES:                   --- Added comments ---  uidu0849 [May 14, 2013 9:25:37 AM CEST]
  CHANGES:                   Change Package : 159154:30 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.10 2013/04/10 12:28:40CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - map GDBsqrt_75 to CML_f_Sqrt
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 10, 2013 12:28:40 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.9 2013/04/09 12:55:48CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - Map SQRT_ to CML_f_Sqrt
  CHANGES:                   --- Added comments ---  uidu0849 [Apr 9, 2013 12:55:49 PM CEST]
  CHANGES:                   Change Package : 159154:21 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.8 2013/02/27 10:59:18CET Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - correct min/max for ECU
  CHANGES:                   --- Added comments ---  uidu0849 [Feb 27, 2013 10:59:19 AM CET]
  CHANGES:                   Change Package : 159154:17 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.7 2012/10/12 13:58:18CEST Oprisan, Dan (oprisand) 
  CHANGES:                   - Add MOD, REM, CEI, FLOOR functions to CML
  CHANGES:                   - remove obsolete FMOD_ macro from cml_mapping.h
  CHANGES:                   --- Added comments ---  oprisand [Oct 12, 2012 1:58:18 PM CEST]
  CHANGES:                   Change Package : 139701:13 http://mks-psad:7002/im/viewissue?selection=139701
  CHANGES:                   Revision 1.6 2012/10/01 14:24:56CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add mappings needed in FCT
  CHANGES:                   --- Added comments ---  uidu0849 [Oct 1, 2012 2:24:57 PM CEST]
  CHANGES:                   Change Package : 159154:10 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.5 2012/09/26 18:24:11CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add some mappings
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 26, 2012 6:24:12 PM CEST]
  CHANGES:                   Change Package : 159154:8 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.4 2012/09/25 13:42:29CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - include function fastlog10 and CalculatePolygonValue
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 25, 2012 1:42:31 PM CEST]
  CHANGES:                   Change Package : 159154:6 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.3 2012/09/24 18:17:21CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - add mapping of FMOD_
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 24, 2012 6:17:29 PM CEST]
  CHANGES:                   Change Package : 160472:1 http://mks-psad:7002/im/viewissue?selection=160472
  CHANGES:                   Revision 1.2 2012/09/20 13:29:46CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   - delete old log in file header
  CHANGES:                   --- Added comments ---  uidu0849 [Sep 20, 2012 1:29:46 PM CEST]
  CHANGES:                   Change Package : 159154:3 http://mks-psad:7002/im/viewissue?selection=159154
  CHANGES:                   Revision 1.1 2012/09/14 14:31:13CEST Meschenmoser, Daniel (uidu0849) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CML_CommonMathLibrary/04_Engineering/01_Source_Code/algo/cml/project.pj

**************************************************************************** */

/**
@defgroup mapping MAPPING (name mapping for old components)
  @ingroup cml
@{ */

/*****************************************************************************
  QA-C
*****************************************************************************/
/* date: 2014-03-27, reviewer: S. Schwarzkopf, reason:  
   This file maps old identifiers to CML ones for compatibility. So function 
   like macros are accepted in this file.
*/
// PRQA S 3429 EOF
// PRQA S 3453 EOF

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/

/* allow inclusion of cml sub-headers only if external cml header is included */
#ifndef _CML_EXT_INCLUDED
  #pragma message(__FILE__": Inclusion of cml_mapping.h is discouraged. It exists only for compatibility with ARS3xx and might be deleted without prior notice. Include cml_ext.h instead.")
#endif /* #ifdef _CML_EXT_INCLUDED */

#ifndef _CML_MAPPING_INCLUDED
#define _CML_MAPPING_INCLUDED


/*****************************************************************************
  CONSTANTS
*****************************************************************************/
/*! CML_f_Pi */
#undef C_PI /* undefine constant possibly defined in glob_defs.h by SW */
#define C_PI           CML_f_Pi
/*! CML_f_Delta */
#define C_F32_DELTA    CML_f_Delta
/*! CML_f_SubsForLogOfZero */
#define GDB_SUBS_VAL_FOR_LOG_OF_ZERO CML_f_SubsForLogOfZero

/*! CML_KafiMatrixTypeVector */
#define MATTYPE_VECTOR          CML_KafiMatrixTypeVector
/*! CML_KafiMatrixTypeFull */
#define MATTYPE_FULL            CML_KafiMatrixTypeFull
/*! CML_KafiMatrixTypeSymmetric */
#define MATTYPE_SYMMETRIC       CML_KafiMatrixTypeSymmetric
/*! CML_KafiMatrixTypeDiagonal */
#define MATTYPE_DIAGONAL        CML_KafiMatrixTypeDiagonal
/*! CML_KafiMatrixTypeUpperRight */
#define MATTYPE_UPPERTRIANGULAR CML_KafiMatrixTypeUpperRight

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*! CML_t_SimpleKafi */
#define GDBSimpleKafi_t    CML_t_SimpleKafi
/*! CML_t_KafiMatrix */
#define GDBBaseMatrix_t    CML_t_KafiMatrix
/*! CML_t_BaseKafi */
#define GDBBaseKafi_t      CML_t_BaseKafi
/*! CML_t_LinFunctionArgs */
#define GDBLFunction_t     CML_t_LinFunctionArgs
/*! CML_t_TrafoMatrix2D */
#define GDBTrafoMatrix2D_t CML_t_TrafoMatrix2D
/*! CML_t_SymMatrix1 */
#define GDBSymMatrix1_t    CML_t_SymMatrix1
/*! CML_t_SymMatrix2 */
#define GDBSymMatrix2_t    CML_t_SymMatrix2
/*! CML_t_SymMatrix6s */
#define GDBSymMatrix6s_t   CML_t_SymMatrix6s
/*! CML_t_Vector1D */
#define GDBVector1_t       CML_t_Vector1D
/*! CML_t_Vector2D */
#define GDBVector2_t       CML_t_Vector2D
/*! CML_t_Point2D */
#define GDB_Math_Point_t   CML_t_Point2D
/*! CML_t_Matrix */
#define AlgoMatrix_t       CML_t_Matrix

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! CML_Deg2Rad */
#undef DEG2RAD /* undefine constant possibly defined in glob_defs.h by SW */
#define DEG2RAD(deg_)           CML_Deg2Rad(deg_)
/*! CML_Rad2Deg */
#undef RAD2DEG /* undefine constant possibly defined in other files */
#define RAD2DEG(deg_)           CML_Rad2Deg(deg_)
/*! CML_Sqr */
#define SQR(x)                  CML_Sqr(x)
/*! CML_f_Sqrt */
#define SQRT(x)                 CML_f_Sqrt(x)
/*! CML_f_Sqrt */
#define SQRT_(x)                CML_f_Sqrt(x)
/*! CML_f_Sqrt */
#define GDBsqrt_75(x)           CML_f_Sqrt(x)


/*! CML_u_Abs(x) */
#undef iABS /* undefine constant possibly defined in glob_defs.h by SW */
#define iABS(x)                 CML_u_Abs(x)
/*! (((x)<(0))?(-(x)):(x)) */
#define ABS(x)                  (((x)<(0))?(-(x)):(x))
/*! CML_f_Abs(x) */
#define fABS(x)                 CML_f_Abs(x)
/*! CML_Sign(x) */
#define fSIGN(x)                CML_Sign(x)

/*! CML_Round(x) */
#define ROUND(x)                CML_Round(x)
/*! CML_s_Round2Int(x) */
#define ROUND_TO_INT(x)         CML_s_Round2Int(x)
/*! CML_u_Round2Uint(x) */
#define ROUND_TO_UINT(x)        CML_u_Round2Uint(x)
/*! CML_f_ModTrig(x, y) */
#define GDB_fmod(x, y)          CML_f_ModTrig(x, y)
/*! CML_GetBit(source, bitmask) */
#define GET_BIT(source, bitmask) CML_GetBit(source, bitmask)
/*! CML_SetBit(source, bitmask) */
#define SET_BIT(source, bitmask) CML_SetBit(source, bitmask)
/*! CML_ClearBit(source, bitmask) */
#define CLEAR_BIT(source, bitmask) CML_ClearBit(source, bitmask)
/*! CML_f_IsZero(value) */
#define F32_IS_ZERO(value)      CML_f_IsZero(value)
/*! CML_f_IsNonZero(value) */
#define F32_IS_NZERO(value)     CML_f_IsNonZero(value)

/*! CML_Min(x,y) */
#define MIN(x,y)                CML_Min(x,y)
/*! CML_Max(x,y) */
#define MAX(x,y)                CML_Max(x,y)
/*! CML_MinMax(min,max,value) */
#define MINMAX(min,max,value)   CML_MinMax(min,max,value)
/*! CML_f_Min(x,y) */
#define MIN_FLOAT(x,y)          CML_f_Min(x,y)
/*! CML_f_Max(x,y) */
#define MAX_FLOAT(x,y)          CML_f_Max(x,y)
/*! CML_f_MinMax(min,max,value) */
#define MINMAX_FLOAT(min,max,value) CML_f_MinMax(min,max,value)
/*! CML_f_MultAdd(a,b,d) */
#define MUL_ADD_FLOAT(a,b,d)    CML_f_MultAdd(a,b,d)
/*! CML_f_Curvature2Radius(x) */
#define A2_TO_RAD(x)            CML_f_Curvature2Radius(x)

/*! CML_f_LowPassFilter(neu,alt,zeit_k) */
#define GDB_FILTER(neu,alt,zeit_k) CML_f_LowPassFilter(neu,alt,zeit_k)
/*! CML_VectMatIndex(index) */
#define VECT_MAT_INDEX(index) CML_VectMatIndex(index)
/*! CML_LinFuncInit(MIN_Y,MAX_Y,MIN_X,MAX_X) */
#define GDB_LINEARE_FCT_INIT(MIN_Y,MAX_Y,MIN_X,MAX_X) CML_LinFuncInit(MIN_Y,MAX_Y,MIN_X,MAX_X)

/*! CML_CreateMatrix(name, rows, cols) */
#define ALGO_MTRX_CREATE(name, rows, cols) CML_CreateMatrix(name, rows, cols)
/*! CML_GetMatrixElement(name, row, col) */
#define ALGO_MTRX_ELEM(name, row, col) CML_GetMatrixElement(name, row, col)
/*! CML_SetMatrixSize(name, rows, cols) */
#define ALGO_MTRX_SET_SIZE(name, rows, cols) CML_SetMatrixSize(name, rows, cols)
/*! CML_IsMatrixEmpty(name) */
#define ALGO_MTRX_IS_EMPTY(name) CML_IsMatrixEmpty(name)

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*! CML_f_Mod(f_dividend, f_divisor) */
#define CML_f_ModTrig(f_dividend, f_divisor) CML_f_Mod(f_dividend, f_divisor)
/*! CML_Bayes2(ProbabilityA, ProbabilityB, CPT) */
#define AlgoMathBayes2(ProbabilityA, ProbabilityB, CPT) CML_u_bayes2(ProbabilityA, ProbabilityB, CPT)
/*! CML_Bayes5(ProbabilityA, ProbabilityB, ProbabilityC, ProbabilityD, ProbabilityE, CPT) */
#define AlgoMathBayes5(ProbabilityA, ProbabilityB, ProbabilityC, ProbabilityD, ProbabilityE, CPT) CML_u_bayes5(ProbabilityA, ProbabilityB, ProbabilityC, ProbabilityD, ProbabilityE, CPT)

/*! CML_v_TransformPosition2D(M, DistX, DistY) */
#define GDBmathTrafoPos2D(M, DistX, DistY)  CML_v_TransformPosition2D(M, DistX, DistY)
/*! CML_f_TransformXPosition2D(M , fDistX , fDistY) */
#define GDBmathTrafoXPos2D(M , fDistX , fDistY) CML_f_TransformXPosition2D(M , fDistX , fDistY)
/*! CML_f_TransformYPosition2D(M , fDistX , fDistY) */
#define GDBmathTrafoYPos2D(M , fDistX , fDistY) CML_f_TransformYPosition2D(M , fDistX , fDistY)

/*! CML_v_KalmanMeasUpdate(GDBKafi, KMat, FVec, CMat, fMeas, fMeasNoise) */
#define GDBKalmanMeasUpdate(GDBKafi, KMat, FVec, CMat, fMeas, fMeasNoise) CML_v_KalmanMeasUpdate(GDBKafi, KMat, FVec, CMat, fMeas, fMeasNoise)
/*! CML_v_KalmanPDiagUpdate(GDBKafi) */
#define GDBKalmanUpdatePDiag(GDBKafi) CML_v_KalmanPDiagUpdate(GDBKafi)
/*! CML_v_KalmanTimeUpdate(GDBKafi, WMat, DAMat, DAWVec) */
#define GDBKalmanTimeUpdate(GDBKafi, WMat, DAMat, DAWVec) CML_v_KalmanTimeUpdate(GDBKafi, WMat, DAMat, DAWVec)
/*! CML_v_KalmanCreateMat(pmatM, pData, MatType, uiRows, uiColumns) */
#define GDBKalmanCreateMat(pmatM, pData, MatType, uiRows, uiColumns) CML_v_KalmanCreateMat(pmatM, pData, MatType, uiRows, uiColumns)
/*! CML_f_KalmanGetMatElement(pmatM, uiRow, uiColumn) */
#define GDBKalmanGetMat(pmatM, uiRow, uiColumn) CML_f_KalmanGetMatElement(pmatM, uiRow, uiColumn)
/*! CML_v_KalmanSetMat(pmatM, uiRow, uiColumn, fValue) */
#define GDBKalmanSetMat(pmatM, uiRow, uiColumn, fValue) CML_v_KalmanSetMat(pmatM, uiRow, uiColumn, fValue)

/*! CML_u_SimpleKafiInit(kafi) */
#define GDBmathSimpleKafiInit(kafi) CML_u_simpleKafiInit(kafi)
/*! CML_u_SimpleKafiPrediction(kafi) */
#define GDBmathSimpleKafiPrediction(kafi) CML_u_simpleKafiPrediction(kafi)
/*! CML_u_SimpleKafiUpdate(kafi) */
#define GDBmathSimpleKafiUpdate(kafi) CML_u_simpleKafiUpdate(kafi)

/*! CML_f_LinearInterpolation(dX1, dY1, dX2, dY2, dXPos) */
#define dGDBmathGewichtGerade(dX1, dY1, dX2, dY2, dXPos) CML_f_LinearInterpolation(dX1, dY1, dX2, dY2, dXPos)
/*! CML_f_BoundedLinInterpol(dPara, dEingang) */
#define dGDBmathLineareFunktion(dPara, dEingang) CML_f_BoundedLinInterpol(dPara, dEingang)
/*! CML_f_GetPickupDist(fObjRelSpeed, fEgoSpeed, fEgoDeceleration, fGapTime, fLatencyTime) */
#define GDBGetPickupDist(fObjRelSpeed, fEgoSpeed, fEgoDeceleration, fGapTime, fLatencyTime) CML_f_GetPickupDist(fObjRelSpeed, fEgoSpeed, fEgoDeceleration, fGapTime, fLatencyTime)
/*! CML_f_BoundedLinInterpol2(IVal, Imin, Imax, Omin, Omax) */
#define GDBmathLinFuncLimBounded(IVal, Imin, Imax, Omin, Omax) CML_f_BoundedLinInterpol2(IVal, Imin, Imax, Omin, Omax)
/*! CML_f_LowPassFilter2(Old, New, Alpha) */
#define GDB_Math_LowPassFilter(Old, New, Alpha) CML_f_LowPassFilter2(Old, New, Alpha)
/*! CML_f_BoundedLinInterpol3(P1, P2, In) */
#define GDB_Math_LinInterpol(P1, P2, In) CML_f_BoundedLinInterpol3(P1, P2, In)
/*! CML_f_BoundedLinInterpol5(P1, P2, In) */
#define Math_LinInterpol_i32(P1, P2, In) CML_f_BoundedLinInterpol5(P1, P2, In)
/*! CML_f_CalculatePolygonValue(iNrOfTableRows, pTable, fInputValue) */
#define GDB_Math_CalculatePolygonValue(iNrOfTableRows, pTable, fInputValue) CML_f_CalculatePolygonValue(iNrOfTableRows, pTable, fInputValue)
/*! CML_f_fastlog10(x) */
#define fastlog10(x) CML_f_fastlog10(x)

/*! CML_v_CalculateCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardRaw, pTrafoMatrix2DCOFBackwardRaw, fSpeedCorrected, fEgoAcceleration, fYawRate_e, fCycleTime) */
#define GDBmathCalculateCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardRaw, pTrafoMatrix2DCOFBackwardRaw, fSpeedCorrected, fEgoAcceleration, fYawRate_e, fCycleTime) CML_v_CalculateCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardRaw, pTrafoMatrix2DCOFBackwardRaw, fSpeedCorrected, fEgoAcceleration, fYawRate_e, fCycleTime)
/*! CML_v_CalcCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardTgtSync, pTrafoMatrix2DCOFForJitTgtSync, fEgoSpeedXTgtSync, fEgoAccelXTgtSync, fYawRateTgtSync, fYawRateVarTgtSync, fYawRateMaxJitterTgtSync, fSensorXPosition, fSensorYPosition, fSlipAngleTgtSync, fSlipAngleVarTgtSync, fCycleTime) */
#define GDBmathCalcCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardTgtSync, pTrafoMatrix2DCOFForJitTgtSync, fEgoSpeedXTgtSync, fEgoAccelXTgtSync, fYawRateTgtSync, fYawRateVarTgtSync, fYawRateMaxJitterTgtSync, fSensorXPosition, fSensorYPosition, fSlipAngleTgtSync, fSlipAngleVarTgtSync, fCycleTime) CML_v_CalcCOFEgomotionMatrices(pTrafoMatrix2DCOFForwardTgtSync, pTrafoMatrix2DCOFForJitTgtSync, fEgoSpeedXTgtSync, fEgoAccelXTgtSync, fYawRateTgtSync, fYawRateVarTgtSync, fYawRateMaxJitterTgtSync, fSensorXPosition, fSensorYPosition, fSlipAngleTgtSync, fSlipAngleVarTgtSync, fCycleTime)
/*! CML_v_CalcForwardTrafoEgomotionMatrix(p_TrafoMatrix2DCOFForwardTgtSync, f_EgoSpeedXTgtSync, f_EgoAccelXTgtSync, f_YawRateTgtSync, f_SensorXPosition, f_SensorYPosition, f_CycleTime) */
#define CML_v_CalcCOFEgomotionMatrices_EM_V6(p_TrafoMatrix2DCOFForwardTgtSync, f_EgoSpeedXTgtSync, f_EgoAccelXTgtSync, f_YawRateTgtSync, f_SensorXPosition, f_SensorYPosition, f_CycleTime)  CML_v_CalcForwardTrafoEgomotionMatrix(p_TrafoMatrix2DCOFForwardTgtSync, f_EgoSpeedXTgtSync, f_EgoAccelXTgtSync, f_YawRateTgtSync, f_SensorXPosition, f_SensorYPosition, f_CycleTime) 
/*! CML_GetTrafoMatrixByAngle(fAngle) */
#define GDBGetTrafoMatrixByAngle(fAngle) CML_GetTrafoMatrixByAngle(fAngle)
/*! CML_GetTrafoMatrixByDisplacement(fX, fY) */
#define GDBGetTrafoMatrixByDisplacement(fX, fY) CML_GetTrafoMatrixByDisplacement(fX, fY)
/*! CML_f_ComputeClothoidLateralDistance(fXpos, fC0, fC1, fAngle) */
#define GDBRoadClothoid(fXpos, fC0, fC1, fAngle) CML_f_ComputeClothoidLateralDistance(fXpos, fC0, fC1, fAngle)

/*! CML_v_InitMatrix(A, RowNr, ColNr, fVal) */
#define AlgoMtrxInit(A, RowNr, ColNr, fVal) CML_v_initMatrix(A, RowNr, ColNr, fVal)
/*! CML_v_CopyMatrix(Res, A) */
#define AlgoMtrxCopy(Res, A) CML_v_copyMatrix(Res, A)
/*! CML_v_CopyArrayToSymMatrix(Res, RowNr, ColNr, pData) */
#define AlgoMtrxCopyFromSym(Res, RowNr, ColNr, pData) CML_v_copyArrayToSymMatrix(Res, RowNr, ColNr, pData)
/*! CML_v_CreateIdentityMatrix(Res, Size) */
#define AlgoMtrxIdent(Res, Size) CML_v_createIdentityMatrix(Res, Size)
/*! CML_v_AddMatrices(Res, A, B) */
#define AlgoMtrxAdd(Res, A, B) CML_v_addMatrices(Res, A, B)
/*! CML_v_SubtractMatrices(Res, A, B) */
#define AlgoMtrxSub(Res, A, B) CML_v_subtractMatrices(Res, A, B)
/*! CML_v_MultiplyMatrices(Res, A, B) */
#define AlgoMtrxMul(Res, A, B) CML_v_multiplyMatrices(Res, A, B)
/*! CML_v_MultiplyMatricesToSymResult(Res, A, B) */
#define AlgoMtrxMulSym(Res, A, B) CML_v_multiplyMatricesToSymResult(Res, A, B)
/*! CML_v_MultiplyMatrixWithTranspose(Res, A, B) */
#define AlgoMtrxMulTrsp(Res, A, B) CML_v_MultiplyMatrixWithTranspose(Res, A, B)
/*! CML_v_InvertMatrix(Res, A) */
#define AlgoMtrxInv(Res, A) CML_v_InvertMatrix(Res, A)
/*! CML_v_ScaleMatrix(A, fVal) */
#define AlgoMtrxScale(A, fVal) CML_v_scaleMatrix(A, fVal)
/*! CML_v_CholeskyMatrix(Res, A) */
#define AlgoMtrxChol(Res, A) CML_v_choleskyMatrix(Res, A)
/*! CML_v_LowTriaInvMatrix(Res,A) */
#define AlgoMtrxLowTriaInv(Res, A) CML_v_lowTriaInvMatrix(Res,A)
/*! CML_v_LowTriaSqrMatrix(Res,A)  */
#define AlgoMtrxLowTriaSqr(Res, A) CML_v_lowTriaSqrMatrix(Res,A) 
/*! CML_v_UppTriaSqrMatrix(Res,A) */
#define AlgoMtrxUppTriaSqr(Res, A) CML_v_uppTriaSqrMatrix(Res,A)
/*! CML_v_TransposeMatrix(Res, A) */
#define AlgoMtrxTrsp(Res, A) CML_v_transposeMatrix(Res, A)

/*! CML_v_InitWeightedSample(sample) */
#define GDBmathMessIntervallInit(sample) CML_v_initWeightedSample(sample)
/*! CML_v_AddSamplePoint(sample, value, weight) */
#define GDBmathMessIntervallHinzufuegen(sample, value, weight) CML_v_addSamplePoint(sample, value, weight)
/*! CML_v_MultiplySampleWithFactor(sample, factor) */
#define GDBmathMessIntervallReduzieren(sample, factor) CML_v_multiplySampleWithFactor(sample, factor)
/*! CML_v_ComputeMeanStd(sample) */
#define GDBmathMittelStdAbwBerechnen(sample) CML_v_computeMeanStd(sample)
/*! CML_f_CalcStdGaussianCDF(fValue, fAver, fSigma) */
#define GDBCalcCumulatDistrFunction(fValue, fAver, fSigma) CML_f_CalcStdGaussianCDF(fValue, fAver, fSigma)


//Description: Added to comply with new naming convention standards
//for cml_trigo module
#define GDBtan_56s  CML_f_tan56s
#define GDB_tan32s  CML_f_tan32s
#define GDBexp_100s  CML_f_exp100s
#define GDB_cos32  CML_f_cos32
#define GDB_sin32  CML_f_sin32
#define GDB_tan32  CML_f_tan32
#define GDBcos_52  CML_f_cos52
#define GDBsin_52  CML_f_sin52
#define GDBtan_52  CML_f_tan52
#define GDBatan_66  CML_f_atan66
#define GDBacos_66  CML_f_acos66
#define GDBasin_66  CML_f_asin66
#define GDBexp_power  CML_f_expPower
#define GDBexp_100  CML_f_exp100
#define GDBatan2_66  CML_f_atan2
#define GDBexp  CML_f_exp
#define GDBsincos  CML_f_sincos
#define CML_sin66 CML_f_sin66
#define CML_cos66 CML_f_cos66
#define CML_tanh58 CML_f_tanh58
#define CML_sin66_Core CML_f_sin66Core
#define CML_cos66_Core CML_f_cos66Core
#define CML_sin33_Core CML_f_sin33Core
#define CML_cos33_Core CML_f_cos33Core
#define CML_atan18 CML_f_atan18
//for cml_misc module
#define CML_Sqrt_VeryFast CML_f_sqrtVeryFast
#define CML_Exp_VeryFast CML_f_expVeryFast
#define CML_AlphaMaxBetaMin CML_f_alphaMaxBetaMin
#define CML_FastestInv CML_f_fastestInv
#define CML_FastInv23 CML_f_fastInv23
#define CML_FastInv47 CML_f_fastInv47
#define CML_FastInv69 CML_f_fastInv69
#define CML_Ln_VeryFast CML_f_lnVeryFast
#define CML_InvSqrt14 CML_f_invSqrt14
#define CML_InvSqrt53 CML_f_invSqrt53
#define CML_InvSqrt67 CML_f_invSqrt67
#define CML_InvSqrt27 CML_f_invSqrt27
#define CML_Sqrt14 CML_f_sqrt14
#define CML_Sqrt27 CML_f_sqrt27
#define CML_Sqrt53 CML_f_sqrt53
#define CML_Sqrt67 CML_f_sqrt67
#define CML_b_IsPointInsidePolygon CML_b_isPointInsidePolygon
#define CML_f_Mod CML_f_mod
#define CML_f_Rem CML_f_rem
#define CML_s_CountNrOfBitsSet CML_s_countNrOfBitsSet
#define CML_f_SqrtApprox CML_f_sqrtApprox
#define CML_f_PowerOfTwo CML_f_powerOfTwo
#define CML_s_GetLutIndex CML_s_getLutIndex
#define CML_s_GetLutIndexBackwards CML_s_getLutIndexBackwards
#define CML_f_XPowY CML_f_xPowY
#define CML_f_AlphaMaxBetaMin CML_f_alphaMaxBetaMin
#define CML_s_AlphaMaxBetaMinInt CML_s_alphaMaxBetaMinInt
#define CML_f_PowToDB CML_f_powToDB
#define CML_f_MagToDB CML_f_magToDB
#define CML_f_ModReciprocal CML_f_modReciprocal
#define CML_f_Sign CML_f_sign
#define CML_f_Hypot CML_f_hypot
//for cml_interpol module
#define CML_f_LinearInterpolation CML_f_linearInterpolation
#define CML_f_BoundedLinInterpol CML_f_boundedLinInterpol
#define CML_f_BoundedLinInterpol2 CML_f_boundedLinInterpol2
#define CML_f_BoundedLinInterpol3 CML_f_boundedLinInterpol3
#define CML_f_BoundedLinInterpol4 CML_f_boundedLinInterpol4
#define CML_f_BoundedLinInterpol5 CML_f_boundedLinInterpol5
#define CML_CalculateCubicSplineClamped CML_b_calculateCubicSplineClamped
//cml_complex module
#define CML_f_CalculatePolygonValue CML_f_calculatePolygonValue
#define CML_v_Cartesian2Polar CML_v_cartesian2Polar
#define CML_v_Polar2Cartesian CML_v_polar2Cartesian
#define CML_v_MultiplyComplex CML_v_multiplyComplex
#define CML_v_DivideComplex CML_v_divideComplex
#define CML_v_QuadraticEquationComplex CML_v_quadraticEquationComplex
//cml_kafi module
#define CML_v_KalmanTimeUpdate CML_v_kalmanTimeUpdate
#define CML_v_KalmanMeasUpdate CML_v_kalmanMeasUpdate
#define CML_v_KalmanPDiagUpdate CML_v_kalmanPDiagUpdate
#define CML_v_KalmanCreateMat CML_v_kalmanCreateMat
#define CML_v_KalmanSetMat CML_v_kalmanSetMat
#define CML_f_KalmanGetMatElement CML_f_kalmanGetMatElement
#define CML_u_SimpleKafiInit CML_u_simpleKafiInit
#define CML_u_SimpleKafiPrediction CML_u_simpleKafiPrediction
#define CML_u_SimpleKafiUpdate CML_u_simpleKafiUpdate
#define CML_v_PhaseUnwrapping CML_v_phaseUnwrapping
//cml_mtrx module
#define CML_v_InitMatrix CML_v_initMatrix
#define CML_v_CreateIdentityMatrix CML_v_createIdentityMatrix
#define CML_v_AddMatrices CML_v_addMatrices
#define CML_v_SubtractMatrices CML_v_subtractMatrices
#define CML_v_MultiplyMatrices CML_v_multiplyMatrices
#define CML_v_MultiplyMatricesToSymResult CML_v_multiplyMatricesToSymResult
#define CML_v_MultiplyMatrixWithTranspose CML_v_multiplyMatrixWithTranspose
#define CML_v_InvertMatrix CML_v_invertMatrix
#define CML_v_ScaleMatrix CML_v_scaleMatrix
#define b_InvertMatrixCramer2 CML_b_invertMatrixCramer2
#define b_InvertMatrixCramer3 CML_b_invertMatrixCramer3
#define CML_v_CopyMatrix CML_v_copyMatrix
#define CML_v_CopyArrayToSymMatrix CML_v_copyArrayToSymMatrix
#define CML_v_CholeskyMatrix CML_v_choleskyMatrix
#define CML_v_LowTriaInvMatrix CML_v_lowTriaInvMatrix
#define CML_v_LowTriaSqrMatrix CML_v_lowTriaSqrMatrix
#define CML_v_UppTriaSqrMatrix CML_v_uppTriaSqrMatrix
#define CML_v_TransposeMatrix CML_v_transposeMatrix
#define CML_a_InitMatrixHeader CML_initMatrixHeader
//cml_bayes module
#define CML_Bayes2 CML_u_bayes2
#define CML_Bayes3 CML_u_bayes3
#define CML_Bayes4 CML_u_bayes4
#define CML_Bayes5 CML_u_bayes5
//cml_fourier module
#define CML_v_InverseFFT16 CML_v_inverseFFT16
//cml_stat module
#define CML_v_InitWeightedSample CML_v_initWeightedSample
#define CML_v_AddSamplePoint CML_v_addSamplePoint
#define CML_v_MultiplySampleWithFactor CML_v_multiplySampleWithFactor
#define CML_v_ComputeMeanStd CML_v_computeMeanStd
#define CML_f_CalcGaussErrorFunction CML_f_calcGaussErrorFunction
#define CML_f_CalcStdGaussianCDF CML_f_calcStdGaussianCDF
#define CML_v_Init_LSF CML_v_initLSF
#define CML_v_InitResults_LSF CML_v_initResultsLSF
#define CML_v_AddData_LSF CML_v_addDataLSF
#define CML_f_CalculateSlope_LSF CML_f_calculateSlopeLSF
#define CML_f_CalculateCorrelation_LSF CML_f_calculateCorrelationLSF
#define CML_f_CalculateYIntersection_LSF CML_f_calculateYIntersectionLSF
#define CML_f_CalculateSquareError_LSF CML_f_calculateSquareErrorLSF
#define CML_f_CalculateMeanSquareError_LSF CML_f_calculateMeanSquareErrorLSF
#define CML_v_CalculateQuality_LSF CML_v_calculateQualityLSF
#define CML_v_CalculateAll_LSF CML_v_calculateAllLSF
#define CML_f_Predict_LSF CML_f_predictLSF
#define CML_v_Init_LSF_ForgetExponential CML_v_initLSFForgetExponential
#define CML_v_AddData_LSF_ForgetExponential CML_v_addDataLSFForgetExponential
#define CML_v_CalculateAll_LSF_ForgetExponential CML_v_calculateAllLSFForgetExponential
#define CML_f_CalcQuantile CML_f_calcQuantile
#define CML_f_StdGaussQuantile CML_f_stdGaussQuantile
#define CML_f_GaussQuantile CML_f_gaussQuantile
#define CML_v_Init_LSF_Quant CML_v_initLSFQuant
#define CML_v_DecodeData_LSF_Quant CML_v_decodeDataLSFQuant
#define CML_v_EncodeData_LSF_Quant CML_v_encodeDataLSFQuant
//cml_vector module
#define VectorWeightedPNorm CML_f_vectorWeightedPNorm
#define Vector2AddP_i16 CML_v_vector2AddPi16
#define Vector2SubP_i16 CML_v_vector2SubPi16
#define Vector2Mull_i16 CML_vector2Mulli16
#define Vector2ScalarProd_i16 CML_s_vector2ScalarProdi16
#define Vector2GetSqrDist_i16 CML_s_vector2GetSqrDisti16
#define Vector2MathRotate2D_i16 CML_v_vector2MathRotate2Di16
#define Vector2AngleToXAxis_i16 CML_f_vector2AngleToXAxisi16
#define Vector2Init_i16 CML_v_vector2Initi16
#define Vector2AddI16_i32 CML_vector2AddI16i32
#define Vector2ScalarProd_i32 CML_s_vector2ScalarProdi32
#define Vector2YAxisIntersectionAdd_i32 CML_b_vector2YAxisIntersectionAddi32
#define Vector2Add_f32 CML_vector2Addf32
#define Vector2Sub_f32 CML_vector2Subf32
#define Vector2GetYPointOnLine_f32 CML_b_vector2GetYPointOnLinef32
#define Vector2GetSqrDist_f32 CML_f_vector2GetSqrDistf32
#define Vector2GetSqrDistI32_f32 CML_f_vector2GetSqrDistI32f32
#define Vector2GetSqrDistI16_f32 CML_f_vector2GetSqrDistI16f32
#define Vector2AngleToXAxis_f32 CML_f_vector2AngleToXAxisf32
//cml_radar module
#define CML_CalculateDistancePoint2Circle CML_calculateDistancePoint2Circle
#define CML_CalculateDistancePoint2Clothoid CML_calculateDistancePoint2Clothoid
#define CML_f_ApproximateRefpoint CML_f_approximateRefPoint
#define CML_f_ComputeClothoidLateralDistance CML_f_computeClothoidLateralDistance
#define CML_f_GetPickupDist CML_f_getPickupDist
#define CML_f_LowPassFilter2 CML_v_lowPassFilter2
#define CML_v_CalcCOFEgomotionMatrices CML_v_calcCOFEgomotionMatrices
#define CML_v_CalcForwardTrafoEgomotionMatrix CML_v_calcForwardTrafoEgomotionMatrix
#define CML_v_CalculateCOFEgomotionMatrices CML_v_calculateCOFEgomotionMatrices
#endif/* #ifndef _CML_MAPPING_INCLUDED */


/** @} end defgroup */
