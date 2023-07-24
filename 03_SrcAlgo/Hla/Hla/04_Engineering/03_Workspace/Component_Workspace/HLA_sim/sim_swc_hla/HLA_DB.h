#include "sim_hla_labelDB.h"
#include "sim_hla_labelDB.cpp"
#include "DB_wrapper.h"
#include "DB_wrapper.cpp"


static const char* SelectString_MFC300_HLA_LDROI = "\
\"TAN\", \
\"FrameMtLDROITimeStamp\", \
\"LDROI_CYCLE_ID\", \
\"LDROI_CYCLE_COUNTER\", \
\"ROI_TRACK_ID\", \
\"ROI_QUANTATY_OF_COORDINATES\", \
\"ROI_COORDINATE_X_1\", \
\"ROI_COORDINATE_Y_1\", \
\"ROI_COORDINATE_X_2\", \
\"ROI_COORDINATE_Y_2\", \
\"ROI_COORDINATE_X_3\", \
\"ROI_COORDINATE_Y_3\", \
\"ROI_COORDINATE_X_4\", \
\"ROI_COORDINATE_Y_4\", \
\"IHCR_Street_Lighting\", \
\"IHCPR_EVA_Lightclass_Left\", \
\"IHCPR_EVA_Lightclass_Right\", \
\"LDROI_DATATYPE\", \
\"IHCR_Kind_Of_Lightclass\", \
\"IHCR_Other_Active_Lights\"";


class Buffer_MFC300_HLA_LDROI
{
public:
  TCHAR  TAN[53];
  UINT64 FrameMtLDROITimeStamp;
  UINT   LDROI_CYCLE_ID;
  UINT   LDROI_CYCLE_COUNTER;
  UINT   ROI_TRACK_ID;
  UINT   ROI_QUANTATY_OF_COORDINATES;
  UINT   ROI_COORDINATE_X_1;
  UINT   ROI_COORDINATE_Y_1;
  UINT   ROI_COORDINATE_X_2;
  UINT   ROI_COORDINATE_Y_2;
  UINT   ROI_COORDINATE_X_3;
  UINT   ROI_COORDINATE_Y_3;
  UINT   ROI_COORDINATE_X_4;
  UINT   ROI_COORDINATE_Y_4;
  TCHAR  IHCR_Street_Lighting[51];
  TCHAR  IHCPR_EVA_Lightclass_Left[51];
  TCHAR  IHCPR_EVA_Lightclass_Right[51];
  TCHAR  LDROI_DATATYPE[13];
  TCHAR  IHCR_Kind_Of_Lightclass[51];
  TCHAR  IHCR_Other_Active_Lights[51];

  BEGIN_COLUMN_MAP(Buffer_MFC300_HLA_LDROI)
    COLUMN_ENTRY(1, TAN)
    COLUMN_ENTRY(2, FrameMtLDROITimeStamp)
    COLUMN_ENTRY(3, LDROI_CYCLE_ID)
    COLUMN_ENTRY(4, LDROI_CYCLE_COUNTER)
    COLUMN_ENTRY(5, ROI_TRACK_ID)
    COLUMN_ENTRY(6, ROI_QUANTATY_OF_COORDINATES)
    COLUMN_ENTRY(7, ROI_COORDINATE_X_1)
    COLUMN_ENTRY(8, ROI_COORDINATE_Y_1)
    COLUMN_ENTRY(9, ROI_COORDINATE_X_2)
    COLUMN_ENTRY(10, ROI_COORDINATE_Y_2)
    COLUMN_ENTRY(11, ROI_COORDINATE_X_3)
    COLUMN_ENTRY(12, ROI_COORDINATE_Y_3)
    COLUMN_ENTRY(13, ROI_COORDINATE_X_4)
    COLUMN_ENTRY(14, ROI_COORDINATE_Y_4)
    COLUMN_ENTRY(15, IHCR_Street_Lighting)
    COLUMN_ENTRY(16, IHCPR_EVA_Lightclass_Left)
    COLUMN_ENTRY(17, IHCPR_EVA_Lightclass_Right)
    COLUMN_ENTRY(18, LDROI_DATATYPE)
    COLUMN_ENTRY(19, IHCR_Kind_Of_Lightclass)
    COLUMN_ENTRY(20, IHCR_Other_Active_Lights)

    END_COLUMN_MAP()
};

extern LabelDB<Buffer_MFC300_HLA_LDROI> *pLabelDB;



static const char* SelectString_MFC300_HLA_LDSS = "\
\"TAN\", \
\"FrameMtLDSSTimeStampStart\", \
\"LDSS_START_CYCLE_ID\", \
\"LDSS_START_CYCLE_COUNTER\", \
\"FrameMtLDSSTimeStampStop\", \
\"LDSS_STOP_CYCLE_ID\", \
\"LDSS_STOP_CYCLE_COUNTER\", \
\"GEN_Country\", \
\"GEN_State\", \
\"GEN_Road_Type\", \
\"GEN_Weather\", \
\"GEN_Street_Conditions\", \
\"CSF_Light_Conditions\", \
\"GEN_Tunnel\", \
\"GEN_Road_Works\", \
\"GEN_Special_Weather_Conditions\", \
\"CSF_Contamination\", \
\"GEN_Slope\", \
\"LDSS_START_DATATYPE\", \
\"LDSS_STOP_DATATYPE\", \
\"SLAF_Phyisical_Seperation\", \
\"IHCR_Street_Lighting_S\", \
\"IHCR_Car_Light_Visibly\"";

class Buffer_MFC300_HLA_LDSS
{
public:
  TCHAR  TAN[53];
  UINT64 FrameMtLDSSTimeStampStart;
  UINT   LDSS_START_CYCLE_ID;
  UINT   LDSS_START_CYCLE_COUNTER;
  UINT64 FrameMtLDSSTimeStampStop;
  UINT   LDSS_STOP_CYCLE_ID;
  UINT   LDSS_STOP_CYCLE_COUNTER;
  TCHAR  GEN_Country[51];
  TCHAR  GEN_State[51];
  TCHAR  GEN_Road_Type[51];
  TCHAR  GEN_Weather[51];
  TCHAR  GEN_Street_Conditions[51];
  TCHAR  CSF_Light_Conditions[51];
  TCHAR  GEN_Tunnel[51];
  TCHAR  GEN_Road_Works[51];
  TCHAR  GEN_Special_Weather_Conditions[51];
  TCHAR  CSF_Contamination[51];
  TCHAR  GEN_Slope[51];
  TCHAR  LDSS_START_DATATYPE[13];
  TCHAR  LDSS_STOP_DATATYPE[13];
  TCHAR  SLAF_Phyisical_Seperation[11];
  TCHAR  IHCR_Street_Lighting_S[51];
  TCHAR  IHCR_Car_Light_Visibly[51];

  BEGIN_COLUMN_MAP(Buffer_MFC300_HLA_LDSS)
    COLUMN_ENTRY(1, TAN)
    COLUMN_ENTRY(2, FrameMtLDSSTimeStampStart)
    COLUMN_ENTRY(3, LDSS_START_CYCLE_ID)
    COLUMN_ENTRY(4, LDSS_START_CYCLE_COUNTER)
    COLUMN_ENTRY(5, FrameMtLDSSTimeStampStop)
    COLUMN_ENTRY(6, LDSS_STOP_CYCLE_ID)
    COLUMN_ENTRY(7, LDSS_STOP_CYCLE_COUNTER)
    COLUMN_ENTRY(8, GEN_Country)
    COLUMN_ENTRY(9, GEN_State)
    COLUMN_ENTRY(10, GEN_Road_Type)
    COLUMN_ENTRY(11, GEN_Weather)
    COLUMN_ENTRY(12, GEN_Street_Conditions)
    COLUMN_ENTRY(13, CSF_Light_Conditions)
    COLUMN_ENTRY(14, GEN_Tunnel)
    COLUMN_ENTRY(15, GEN_Road_Works)
    COLUMN_ENTRY(16, GEN_Special_Weather_Conditions)
    COLUMN_ENTRY(17, CSF_Contamination)
    COLUMN_ENTRY(18, GEN_Slope)
    COLUMN_ENTRY(19, LDSS_START_DATATYPE)
    COLUMN_ENTRY(20, LDSS_STOP_DATATYPE)
    COLUMN_ENTRY(21, SLAF_Phyisical_Seperation)
    COLUMN_ENTRY(22, IHCR_Street_Lighting_S)
    COLUMN_ENTRY(23, IHCR_Car_Light_Visibly)
    END_COLUMN_MAP()
};

extern LabelDB_LDSS<Buffer_MFC300_HLA_LDSS> *pLabelDB_LDSS;
