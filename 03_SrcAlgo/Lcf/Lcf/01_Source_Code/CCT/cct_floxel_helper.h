/*! \file cct_floxel_helper.h
*****************************************************************************
COMPANY:          (C) Copyright Continental AG, All rights reserved.

PROJECT:

CPU:

COMPONENT:

MODULNAME:        CCT

DESCRIPTION:      Contains methods to get the different status of Floxels

AUTHOR:

CREATION DATE:

VERSION:          $Revision: 1.1 $

CHANGES:

*****************************************************************************
**/

#ifndef cct_floxel_helper_h__
#define cct_floxel_helper_h__

#include "algo_type.h"
#include "cct_float_tools.h"
#include "cml_ext_cpp.h"
#include <algorithm>

#if SIB_FLOXEL_DATA_INTFVER > 3
// this define is used to distinguish between older versions of SIB - which set a status bit when
// the floxel is on the hood of the car - and newer version which set the same bit if the floxel
// suffers from low image contrast
#define CCT_FLOXEL_HELPER_SIB_NO_HOOD_STATUS
#endif

namespace cct
{


  /**************************************************************************
  Classnname        CFloxelHelper                                       */ /*!

  @brief            Contains methods to set and get the different status of Floxels
  @description      Layout of the uiNumValidDispAndStatus member in SibFloxelGeometry_t
  *
  *  ---------------------------------------------------------------------------------
  *  |  07 | 06 | 05 | 04 | 03 | 02 | 01 | 00 |
  *  |  status bits       | # valid disp.     |
  *  ---------------------------------------------------------------------------------
  *  bit 04 : set if standard deviation of disparities within floxel exceeds a certain threshold
  *  bit 05 : set if this floxel lies on the hood of the car or if the floxel has low contrast, depending on SIB version used
  *  bit 06 and 07: floxel quality level (0..3)
  *****************************************************************************/
  class CFloxelHelper
  {
  public:
    static const uint16 IMAGE_WIDTH  = 1024U;
    static const uint16 IMAGE_HEIGHT =  512U;

    static const uint8 NUM_DISPARITIES_MASK     = 0x0FU;  /*!< Mask to get number of Valid Disparities */
    static const uint8 STATUS_STD_MASK          = 0x10U;  /*!< Mask to get the High STD flag */
    static const uint8 STATUS_QUAL_MASK         = 0xC0U;  /*!< Mask to get the floxel quality*/
#ifdef CCT_FLOXEL_HELPER_SIB_NO_HOOD_STATUS
    static const uint8 STATUS_LOW_CONTRAST_MASK = 0x20U;  /*!< Mask to get the low intensity contrast flag*/
#else
    static const uint8 STATUS_HOOD_MASK         = 0x20U;  /*!< Mask to get the Hood Floxel flag*/
#endif

    /**************************************************************************
    Functionname     getNumValidDisparities()                      */ /*!

    @brief           Getter method for number of valid disparities
    @description     -
    @param[in]       uiNumValidDispAndStatus The status value of a floxel
    @return          Number of valid disparities in the given floxel
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    inline static uint8 getNumValidDisparities(uint8 uiNumValidDispAndStatus)
    {
      return (uiNumValidDispAndStatus & NUM_DISPARITIES_MASK);
    }

    /**************************************************************************
    Functionname     hasHighDisparityStd()                      */ /*!

    @brief           Checks if a floxel has the high STD flag enabled
    @description     -
    @param[in]       uiNumValidDispAndStatus The status value of a floxel
    @return          True if high STD flag is enabled else false
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    inline static bool hasHighDisparityStd(uint8 uiNumValidDispAndStatus)
    {
      return ((uiNumValidDispAndStatus & STATUS_STD_MASK) != 0 );
    }

#ifdef CCT_FLOXEL_HELPER_SIB_NO_HOOD_STATUS
    /**************************************************************************
    Functionname     isLowContrastFloxel()                      */ /*!

    @brief           Returns true if this floxel has low intensity contrast
    @description     -
    @param[in]       uiNumValidDispAndStatus The status value of a floxel
    @return          True if above conditions are fulfilled, else false
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    inline static bool isLowContrastFloxel(uint8 uiNumValidDispAndStatus)
    {
      return (0 != (uiNumValidDispAndStatus & STATUS_LOW_CONTRAST_MASK));
    }
#else
    /**************************************************************************
    Functionname     isHoodFloxel()                      */ /*!

    @brief           Checks if a floxel has the hood flag enabled
    @description     -
    @param[in]       uiNumValidDispAndStatus The status value of a floxel
    @return          True if hood flag is enabled else false
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    inline static bool isHoodFloxel(uint8 uiNumValidDispAndStatus)
    {
      return ((uiNumValidDispAndStatus & STATUS_HOOD_MASK) != 0 );
    }
#endif

    /**************************************************************************
    Functionname     isHighQualityFloxel()                      */ /*!

    @brief           This function considers a floxel to be of high quality if all of the following apply:
                     - it has at least one valid disparity
                     - it does not lie on the hood of the car
                     - it does not have high standard deviation in disparity
    @description     -
    @param[in]       uiNumValidDispAndStatus The status value of a floxel
    @return          True if above conditions are fulfilled, else false
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    inline static bool isHighQualityFloxel(uint8 uiNumValidDispAndStatus)
    {
#ifdef CCT_FLOXEL_HELPER_SIB_NO_HOOD_STATUS
      return ((uiNumValidDispAndStatus & NUM_DISPARITIES_MASK) != 0)
        &&   ((uiNumValidDispAndStatus & STATUS_STD_MASK     ) == 0);
#else
      return ((uiNumValidDispAndStatus & NUM_DISPARITIES_MASK)                 != 0)
        &&   ((uiNumValidDispAndStatus & (STATUS_HOOD_MASK | STATUS_STD_MASK)) == 0);
#endif
    }

    inline static uint8 getQuality(uint8 uiNumValidDispAndStatus)
    {
      return (uiNumValidDispAndStatus & STATUS_QUAL_MASK) >> 6;
    }

    inline static sint32 getFloxelColFromImageX(const sint32 imageX, const sint32 floxelOffsetX)
    {
      return (imageX - floxelOffsetX) / static_cast<sint32>(SIB_FLOXEL_SIZE_HORIZONTAL_PX);
    }

    inline static sint32 getFloxelRowFromImageY(const sint32 imageY, const sint32 floxelOffsetY)
    {
      return (imageY - floxelOffsetY) / static_cast<sint32>(SIB_FLOXEL_SIZE_VERTICAL_PX);
    }

    inline static sint32 getCenterXFromFloxelCol(const sint32 floxelCol, const sint32 floxelOffsetX)
    {
      // the offset-calculation (last part) to get the pixel center is equal to the sib-harvester code
      return floxelOffsetX + (floxelCol * static_cast<sint32>(SIB_FLOXEL_SIZE_HORIZONTAL_PX)) + (((static_cast<sint32>(SIB_FLOXEL_SIZE_HORIZONTAL_PX)/2)/2) * 2);
    }

    inline static sint32 getLeftXFromFloxelCol(const sint32 floxelCol, const sint32 floxelOffsetX)
    {
      return floxelOffsetX + (floxelCol * static_cast<sint32>(SIB_FLOXEL_SIZE_HORIZONTAL_PX));
    }

    inline static sint32 getCenterYFromFloxelRow(const sint32 floxelRow, const sint32 floxelOffsetY)
    {
      // the offset-calculation (last part) to get the pixel center is equal to the sib-harvester code
      return floxelOffsetY + (floxelRow * static_cast<sint32>(SIB_FLOXEL_SIZE_VERTICAL_PX)) + (((static_cast<sint32>(SIB_FLOXEL_SIZE_VERTICAL_PX)/2)/2) * 2);
    }

    inline static sint32 getBottomYFromFloxelRow(const sint32 floxelRow, const sint32 floxelOffsetY)
    {
      return floxelOffsetY + ((floxelRow + 1) * static_cast<sint32>(SIB_FLOXEL_SIZE_VERTICAL_PX));
    }

    inline static sint32 getTopYFromFloxelRow(const sint32 floxelRow, const sint32 floxelOffsetY)
    {
      return floxelOffsetY + (floxelRow * static_cast<sint32>(SIB_FLOXEL_SIZE_VERTICAL_PX));
    }

  private:
    /**************************************************************************
    Functionname     RoadModel()                      */ /*!

    @brief           The Constructor of the class
    @description     -
    @param[in]       -
    @param[out]      -
    @return          -
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    CFloxelHelper();

    /**************************************************************************
    Functionname     RoadModel()                      */ /*!

    @brief           Copy Constructor
    @description     -
    @param[in]       -
    @param[out]      -
    @return          -
    @pre             -
    @post            -
    @author          -
    *****************************************************************************/
    CFloxelHelper& operator=(const CFloxelHelper&);
  };
}

#endif // cct_floxel_helper_h__
