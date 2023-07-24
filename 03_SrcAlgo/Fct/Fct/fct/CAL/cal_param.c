/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_param.c

DESCRIPTION:               All functions for getting a value from a param table

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 1.10.1.1

**************************************************************************** */
#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */


#if (FCT_CFG_ACC_CAL)
#if (FCT_CFG_LOHP_COMPONENT)
#define Pt_scale 1024u
#endif /* (FCT_CFG_LOHP_COMPONENT) */

/*************************************************************************************************************************
  Functionname:    MAT_CALCULATE_PARAM_VALUE1D                                                                      */ /*!

  @brief           calculation of y(x) in a param table with interpolation

  @description     calculation of y(x) in a param table with interpolation

                    @startuml
                    Start
                    Partition MAT_CALCULATE_PARAM_VALUE1D {

                    : Find the range on the x-axis;
                    : Take x2 as the current position, y2 as next position and \n x1,y1 as previous positions in the table;
                    If (**Is given X value greater than first value in the table ?**) then (Yes)
                        : Consider two known points (x1,y1) and (x2,y2) and x as the x-value;
                        If (** If X lies in between x1 and x2 **) then (Yes)
                            : calculate the Y value using the linear interpolation formula;
                        Else (No)
                            : Y value is set to the value of y2 as y greater than y2;
                        Endif 
                    Else (no)
                        : Y value is set to the first y value from table;
                    Endif
                    }
                    Stop
                    @enduml

  @return          sint16  y(x) : interpolated value                   [Full range of sint16]

  @param[in]       table : pointer to param table [x1,y1,x2,y2,...]    [Full range of sint16]
  @param[in]       num   : number of points [x,y] in param table       [Full range of uint16]
  @param[in]       x     : x value                                     [Full range of sint16]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full    FCT_CFG_ACC_CAL : FCT Support for common ACC Library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-525-0009fc80">CAL_525</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
sint16  MAT_CALCULATE_PARAM_VALUE1D (const sint16 table[], const uint16 num, const sint16 x)
{
  uint16 n;
  uint16 table_index = 0u;
  sint16 y;
  sint16 x2;
  sint16 y2;
  sint16 x1;
  sint16 y1;

  /* find range on x-axle */
  n = 1u;
  while (
         (n < num)
         &&
         (x > table[table_index])
        )
  {
    table_index += 2u;
    n += 1u;
  }

  /* calculate y */
  if(n != 1u)
  {
    /*take actual table position and previous table position for interpolation*/
    x1 = table[table_index-2u];//PRQA S 3382
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason:wraparound will not occur on subtracting 2*/
    y1 = table[table_index-1u];//PRQA S 3382
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason:wraparound will not occur on subtracting 1*/

    x2 = table[table_index];
    y2 = table[table_index+1u];

    if(
       (x < x2) 
       && 
       (x1 < x2)
      )
    {
      /*interpolation*/
      y = (sint16) (((((sint32)x - (sint32)x1) * ((sint32)y2 - (sint32)y1)) / ((sint32)x2 - (sint32)x1)) + (sint32)y1);           
    }
    else
    {
      /*if x > actual (last) table position use last y value from table*/
      y = y2;
    }
  }
  else
  {
    /*if x was smaller than first value in table --> take first y value from table*/
    y = table[table_index+1u];
  }

  return y;
}

#if (FCT_CFG_LOHP_COMPONENT)
/*************************************************************************************************************************
  Functionname:    MAT_CALCULATE_PARAM_VALUE2D                                                                      */ /*!

  @brief           calculation of z(x,y) in a param table with a bilinear interpolation

  @description     calculation of z(x,y) in a param table with a bilinear interpolation

                    @startuml
                    Start
                    Partition MAT_CALCULATE_PARAM_VALUE1D {

                    If (**If step size along x and y axis is non-zero**) then (Yes)
                        : Limit the x value within the x1 and maximum of x value; 
                        : Limit the y value within the y1 and maximum of y value;
                        : The value of functions at four points (x1,y1),(x1,y2),(x2,y1)and(x2,y2) are \n  specified in the parameter table as f11,f12,f21,f22; 
                        : Calculate dx1 using linear interpolation along x-direction for (x1,y1),(x2,y1);
                        : Calculate dx2 using linear interpolation along x-direction for (x1,y2),(x2,y2);
                        : Calculate bilinear interpolation of dx1 and dx2 along y-direction;
                    Else (No)
                        : The bilinear interpolated value for (x,y) is 0;
                    Endif
                    }
                    Stop
                    @enduml

  @return          sint16 z(x)  bilinear interpolated value                                [Full range of sint16]

  @param[in]       table  : pointer to param table [z(x1,y1),z(x2,y1),...],[z(x1,y2),...]  [Full range of sint16]
  @param[in]       numx   : number of points cols                                          [Full range of uint16]
  @param[in]       numy   : number of points rows                                          [Full range of uint16]
  @param[in]       stepx  : distance between cols (x2-x1)=(x3-x2)=stepx                    [Full range of sint32]
  @param[in]       stepy  : distance between rows (y2-y1)=(y3-y2)=stepy                    [Full range of sint32]
  @param[in]       firstx : value of x1                                                    [Full range of sint32]
  @param[in]       firsty : value of y1                                                    [Full range of sint32]
  @param[in]       x      : x value                                                        [Full range of sint32]
  @param[in]       y      : y value                                                        [Full range of sint32]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-526-0009fc80">CAL_526</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
sint16 MAT_CALCULATE_PARAM_VALUE2D (const sint16 table[], const uint16 numx, const uint16 numy, const sint32 stepx, sint32 stepy, sint32 firstx, sint32 firsty, sint32 x, sint32 y)
{
  sint16 z;
  /*position of roi in param table*/
  uint32 nx1, nx2, ndx;
  uint32 ny1, ny2, ndy;
  sint32 val;

  if((stepx != 0) && (stepy != 0))
  {
    /*test x being in xrange*/
    if(x < firstx)
    {
      x = firstx;
    }
    else
    {
      sint16         maxx;
      maxx = (sint16)(firstx + (((sint32)numx - (sint32)1) * stepx));
      x = MAT_MIN(x,(sint32)maxx);
    }

    /*test y being in xrange*/
    if(y < firsty)
    {
      y = firsty;
    }
    else
    {
      sint16         maxy;
      maxy = (sint16)(firsty + (((sint32)numy - (sint32)1) * stepy));
      y = MAT_MIN(y,(sint32)maxy);
    }

    /*get col/row of actual (x,y)*/

    /*------ x ------*/
    /*position between nx1 and nx2*/
    val = x - firstx;
    ndx = ( (uint32) val * Pt_scale) / (uint32) stepx; /* change caused by MISRA */
    /*previous col*/
    nx1 = ndx / (uint32)Pt_scale;   
    ndx-= nx1 * (uint32)Pt_scale;
    /*next col*/
    if((nx1 + (uint32)1) == (uint32)numx)
    {
      nx2 = nx1;
    }
    else
    {
      nx2 = nx1+(uint32)1;
    }

    /*------ y ------*/
    /*position between ny1 and ny2*/
    val = y - firsty;
    ndy = ((uint32) val * Pt_scale) / (uint32) stepy; /* change caused by MISRA */
    /*previous row*/
    ny1 = ndy / (uint32)Pt_scale;
    ndy-= ny1 * (uint32)Pt_scale;
    /*next row*/
    if((ny1 + (uint32)1) == (uint32)numy)
    {
      ny2 = ny1;
    }
    else
    {
      ny2 = ny1+(uint32)1;
    }

    /*interpolation (bilinear) between (px1,py1) and (px2,py2)*/

    /*take weighted point at (px1,py1)*/
    val = ((((sint32)Pt_scale - (sint32)ndx) * ((sint32)Pt_scale - (sint32)ndy)) / (sint32)Pt_scale) * (sint32)table[(ny1*(uint32)numx)+nx1];

    /*add weighted point at (px2,py1)*/
    if(ndx > (uint32)0)
    {
      val+= ((((sint32)ndx) * ((sint32)Pt_scale - (sint32)ndy)) / (sint32)Pt_scale) * (sint32)table[(ny1*(uint32)numx)+nx2];
    }
    else
    {
      /*do nothing*/
    }

    /*add weighted point at (px1,py2)*/
    if(ndy > (uint32)0)
    {
      val+= ((((sint32)Pt_scale - (sint32)ndx) * ((sint32)ndy)) / (sint32)Pt_scale) * (sint32)table[(ny2*(uint32)numx)+nx1];
    }
    else
    {
      /*do nothing*/
    }

    /*add weighted point at (px2,py2)*/
    if((ndx > (uint32)0) && (ndy > (uint32)0))
    {
      val+= (((((sint32)ndx) * ((sint32)ndy)) / (sint32)Pt_scale) * (sint32)table[(ny2*(uint32)numx)+nx2]);
    }

    /*get z from scaled value*/
    z = (sint16)(val / (sint32)Pt_scale);
  }
  else
  {
    z = 0;
  }
  return z;
}

/*************************************************************************************************************************
  Functionname:    cal_calculate_param_value_1D                                                                      */ /*!

  @brief           calculation of y(x) in a param table with interpolation

  @description     calculation of y(x) in a param table with interpolation

                    @startuml
                    Start
                    Partition CAL_CALCULATE_PARAM_VALUE_1D {

                    : Find the segment on x-table for given x vaue; 
                    If (** Is x smaller than first value in x-table ?**) then (Yes)
                        : y is set to first value from y-table;
                    Elseif (**Is x smaller than last value in x-table ?**) then (Yes)
                        : y is set to first value from y-table;
                    else (x lies between the first and last value in x-table)
                        : calculate the y value using the linear interpolation; 
                    Endif
                    }
                    Stop
                    @enduml

  @return          float  y(x) : interpolated value                   [Full range of float]

  @param[in]       table_x : pointer to param table [x1,x2,...]       [Full range of float]
  @param[in]       table_y : pointer to param table [y1,y2,...]       [Full range of float]
  @param[in]       count   : number of points in param tables         [Full range of uint16]
  @param[in]       x       : x value                                  [Full range of float]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-525-0009fc80">CAL_525</a> \n

  @created         -
  @changed         3/7/2016

*************************************************************************************************************************/
float cal_calculate_param_value_1D (const float table_x[], const float table_y[], uint16 count, float x)
{
  uint16 i;
  float y = 0.f;
  float x1, x2;
  float y1, y2;

  /* find segment on x-table */
  for (i=0; (i<count) && (x>table_x[i]); i++);/* PRQA S 3342, 3138, 2214 */
  /* date: 2017-11-24, reviewer: Shruthi Ramaiah, reason : Not Safety critical*/

  if (i == 0U)
  {
    /* begin of table */
    y = table_y[0];
  }
  else if (i >= count)
  {
    /* end of table */
    y = table_y[count-1U];
  }
  else
  {
    /* inside table */
    x1 = table_x[i-1U];
    x2 = table_x[i];
    y1 = table_y[i-1U];
    y2 = table_y[i];

    /* interpolation */
    if ((x2 - x1) > C_F32_DELTA)
    {
      y = (x - x1) * (y2 - y1) / (x2 - x1) + y1;
    }
  }

  return y;
}

/*************************************************************************************************************************
  Functionname:    cal_calculate_param_gradient_1D                                                                      */ /*!

  @brief           calculation of (dy(x)/dx) in a param table with interpolation

  @description     calculation of (dy(x)/dx) in a param table with interpolation

                    @startuml
                    Start
                    Partition CAL_CALCULATE_PARAM_GRADIENT_1D {

                    : Find the segment on x-table for given x vaue; 
                    If (** Is x smaller than first value in x-table ?**) then (Yes)
                        : x1,y1 are set to the first value in the x-table and y-table;
                        : x2,y2 are set to the second value in the x-table and y-table;
                    elseif (** Is x greater than last value in x-table ?**) then (Yes)
                        : x1,y1 are set to the (last-1)th value in the x-table and y-table;
                        : x2,y2 are set to the last value in the x-table and y-table;
                    Else
                        : x1,y1 are set to previous closest value of x in x-table \n and corresponding y-table;
                        : x2,y2 are set to next closest value of x in x-table \n and corresponding y-table;
                    Endif
                    : Gradient value is calculated as the slope between (x1,y1) and (x2,y2);

                    }
                    Stop
                    @enduml

  @return          float  y(x) : gradient value                       [Full range of float]

  @param[in]       table_x : pointer to param table [x1,x2,...]       [Full range of float]
  @param[in]       table_y : pointer to param table [y1,y2,...]       [Full range of float]
  @param[in]       count   : number of points in param tables         [Full range of uint16]
  @param[in]       x       : x value                                  [Full range of float]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_LOHP_COMPONENT  : Configuration switch for component LOHP

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-527-0009fc80">CAL_527</a> \n

  @created         25/09/2018
  @changed         25/09/2018

*************************************************************************************************************************/
float cal_calculate_param_gradient_1D (const float table_x[], const float table_y[], uint16 count, float x)
{
  uint16 i;
  float y = 0.f;
  float x1, x2;
  float y1, y2;

  /* find segment on x-table */
  for (i=0; (i<count) && (x>table_x[i]); i++);/* PRQA S 3342, 3138, 2214 */
  /* date: 2018-11-28, reviewer: Ravi Kiran Gurrala, reason : Not Safety critical*/

  if (i == 0U)
  {
    /* begin of table */
    x1 = table_x[0];
    x2 = table_x[1];
    y1 = table_y[0];
    y2 = table_y[1];
  }
  else if (i >= count)
  {
    /* end of table */
    x1 = table_x[count-2U];
    x2 = table_x[count-1U];
    y1 = table_y[count-2U];
    y2 = table_y[count-1U];
  }
  else
  {
    /* inside table */
    x1 = table_x[i-1U];
    x2 = table_x[i];
    y1 = table_y[i-1U];
    y2 = table_y[i];
  }

  /* gradient calculation */
  if ((x2 - x1) > C_F32_DELTA)
  {
    y = (y2 - y1) / (x2 - x1);           
  }

  return y;
}
#endif /* (FCT_CFG_LOHP_COMPONENT) */
#endif /* (FCT_CFG_ACC_CAL) */

