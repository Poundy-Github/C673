/*
 * Sdc_Perception_Type.h
 *
 *  Created on: May 6, 2023
 *      Author: uif69946
 */

#ifndef _SDC_PERCEPTION_TYPE_H_
#define _SDC_PERCEPTION_TYPE_H_

/*==================[inclusions]============================================*/
#include "Std_Types.h" /* AUTOSAR standard types */

/*==================[macros]=================================================*/
#define SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE STD_ON
#define SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE STD_ON
#define SDC_PERCEPTION_J3_LANE_COORDINATE_TRANSFORM STD_ON

#define SDC_TX_FC_OBJECT_NUMBER 20
#define SDC_FS_NORMAL_COMMINUCATION 2

#if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)
#define SDC_J3_TSR_TFL_TRAFFICSIGN_NUM (8u)
#endif

/*TODO : definition of the Perception data parrern*/
#define SDC_PERCEPTION_DATA_SYNC_PATTERN (0xAA550001U)
#define SDC_PERCEPTION_DATA_OBSTACLE_PATTERN (0xAA550002U)
#define SDC_PERCEPTION_DATA_LANE_PATTERN (0xAA550003U)
#define SDC_PERCEPTION_DATA_TSR_TFL_PATTERN (0xAA550004U)
#define SDC_PERCEPTION_DATA_IHBC_PATTERN (0xAA550005U)
#define SDC_PERCEPTION_DATA_FREE_SPACE_PATTERN (0xAA550006U)
#define SDC_PERCEPTION_DATA_AEB_PATTERN (0xAA550007U)
/*==================[type definitions]======================================*/
/*J3 Perception Data related Struct*/
// Pattern
typedef struct
{
	uint32 Pattern;
	uint32 Reserved;
} s_Sdc_Percption_Pattern_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Percption_Pattern_Data_t data;
} u_Sdc_Percption_Pattern_t;

// Sync
typedef union
{
	uint8 raw[8];
	uint64 ImageTimestamp;
} u_Sdc_Perception_SyncMsg1_t;

typedef union
{
	uint8 raw[8];
	uint64 SPITimestamp;
} u_Sdc_Perception_SyncMsg2_t;

typedef struct
{
	uint32 FrameIndex;
	uint8 CameraID : 4;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint8 SWMajorVersion : 4;
	uint8 SWMiddleVersion : 4;
	uint8 SWMinorVersion : 4;
	uint8 Reserved;
} s_Sdc_Perception_SyncMsg3Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_SyncMsg3Data_t data;
} u_Sdc_Perception_SyncMsg3_t;

typedef struct
{
	u_Sdc_Percption_Pattern_t SyncPattern;
	u_Sdc_Perception_SyncMsg1_t SyncMsg1;
	u_Sdc_Perception_SyncMsg2_t SyncMsg2;
	u_Sdc_Perception_SyncMsg3_t SyncMsg3;
} s_Sdc_Perception_SyncMsgData_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Percption_Pattern_t) + sizeof(u_Sdc_Perception_SyncMsg1_t) + sizeof(u_Sdc_Perception_SyncMsg2_t) + sizeof(u_Sdc_Perception_SyncMsg3_t)];
	s_Sdc_Perception_SyncMsgData_t data;
} u_Sdc_Perception_Sync_t;

// Obstacle
typedef struct
{
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint8 NumObstacles;
	uint8 ID_CIPV;
	uint8 ID_MCP;
	uint16 CIPV_TTC;
	uint16 MCP_TTC;
	uint8 MCP_TTC_Valid : 4;
	uint8 CIPV_TTC_Valid : 4;
	uint8 CIPV_HWM_Valid : 4;
	uint8 reserved_3 : 4;
	uint16 CIPV_HWM;
} s_Sdc_Perception_ObstacleHeader1_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleHeader1_Data_t data;
} u_Sdc_Perception_ObstacleHeader1_t;

typedef struct
{
	uint8 MCP_TTC_Valid : 4;
	uint8 CIPV_TTC_Valid : 4;
	uint8 CIPV_HWM_Valid : 4;
	uint8 reserved_3 : 4;
	uint16 CIPV_HWM;
	uint32 reserved_4;
} s_Sdc_Perception_ObstacleHeader2_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleHeader2_Data_t data;
} u_Sdc_Perception_ObstacleHeader2_t;

typedef struct
{
	uint8 ObstacleID;
	uint8 ObstacleValid : 4;
	uint8 ObstacleReplaced : 4;
	uint16 ObstacleAge;
	uint8 ObstacleConfidence;
	uint8 ObstacleMotionCategory : 4;
	uint8 ObstacleMotionStatus : 4;
	uint8 ObstacleMeasuringStatus : 4;
	uint8 ObstacleClass : 4;
	uint8 VehicleSubType : 4;
	uint8 PedSubType : 4;
} s_Sdc_Perception_ObstacleDataA_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataA_Data_t data;
} u_Sdc_Perception_ObstacleDataA_t;

typedef struct
{
	uint8 PedPos;
	uint8 PedOrientation;
	uint8 ObstacleLaneAssignment;
	uint8 ObstacleOccluded;
	uint16 ObstacleLength;
	uint16 ObstacleWidth;
} s_Sdc_Perception_ObstacleDataB_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataB_Data_t data;
} u_Sdc_Perception_ObstacleDataB_t;

typedef struct
{
	uint16 ObstacleHeight;
	uint8 CIPVFlag : 4;
	uint8 MCPFlag : 4;
	uint8 ObstacleBlinkerInfo : 4;
	uint8 ObstacleBrakeLights : 4;
	float32 ObstacleCenterAngle;
} s_Sdc_Perception_ObstacleDataC_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataC_Data_t data;
} u_Sdc_Perception_ObstacleDataC_t;

typedef struct
{
	uint8 ObstaclePositionType;
	uint8 reserved_0;
	uint16 Obstacle_TTC;
	float32 ObstaclePosX;
} s_Sdc_Perception_ObstacleDataD_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataD_Data_t data;
} u_Sdc_Perception_ObstacleDataD_t;

typedef struct
{
	float32 ObstaclePosY;
	float32 ObstacleVelX;
} s_Sdc_Perception_ObstacleDataE_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataE_Data_t data;
} u_Sdc_Perception_ObstacleDataE_t;

typedef struct
{
	float32 ObstacleVelY;
	float32 ObstacleAccX;
} s_Sdc_Perception_ObstacleDataF_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataF_Data_t data;
} u_Sdc_Perception_ObstacleDataF_t;

typedef struct
{
	float32 ObstaclePosXSTD;
	float32 ObstaclePosYSTD;
} s_Sdc_Perception_ObstacleDataG_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataG_Data_t data;
} u_Sdc_Perception_ObstacleDataG_t;

typedef struct
{
	float32 ObstacleVelXSTD;
	float32 ObstacleVelYSTD;
} s_Sdc_Perception_ObstacleDataH_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataH_Data_t data;
} u_Sdc_Perception_ObstacleDataH_t;

typedef struct
{
	float32 ObstacleAccY;
	float32 ObstacleAngle;
} s_Sdc_Perception_ObstacleDataI_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataI_Data_t data;
} u_Sdc_Perception_ObstacleDataI_t;

typedef struct
{
	float32 ObstacleAngleStd;
	float32 ObstacleVelXAbs;
} s_Sdc_Perception_ObstacleDataJ_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataJ_Data_t data;
} u_Sdc_Perception_ObstacleDataJ_t;

typedef struct
{
	float32 ObstacleVelYAbs;
	uint8 RollingCounter_Obstacle;
	uint8 Checksum_Obstacle;
	uint16 reserved_1;
} s_Sdc_Perception_ObstacleDataK_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataK_Data_t data;
} u_Sdc_Perception_ObstacleDataK_t;

typedef struct
{
	float32 ObjCornerPointPoxX;
	float32 CutInDistance;
} s_Sdc_Perception_ObstacleDataL_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataL_Data_t data;
} u_Sdc_Perception_ObstacleDataL_t;

typedef struct
{
	float32 ObjCornerPointPoxY;
	float32 ObstacleCurvatureRadius;
} s_Sdc_Perception_ObstacleDataM_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataM_Data_t data;
} u_Sdc_Perception_ObstacleDataM_t;

typedef struct
{
	uint8 ObstacleTrackingConfidence;
	uint8 CutInFlag;
	uint8 CutInLane 				: 4;
	uint8 LeftDoor					: 4;
	uint8 RightDoor					: 4;
	uint8 TrunkDoor					: 4;
	float32 CutinSpeed;
} s_Sdc_Perception_ObstacleDataN_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataN_Data_t data;
} u_Sdc_Perception_ObstacleDataN_t;

typedef struct
{
	float32 ObstacleAccRefX;
	float32 ObstacleAccRefY;
} s_Sdc_Perception_ObstacleDataO_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataO_Data_t data;
} u_Sdc_Perception_ObstacleDataO_t;

typedef struct
{
	uint16 Img2dBox_Left;
	uint16 Img2dBox_Top;
	uint16 Img2dBox_Right;
	uint16 Img2dBox_Button;
} s_Sdc_Perception_ObstacleDataP_Data_t; // add by yf at 22.10.13

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleDataP_Data_t data;
} u_Sdc_Perception_ObstacleDataP_t; // add by yf at 22.10.13

typedef struct
{
	u_Sdc_Perception_ObstacleDataA_t ObstacleDataA;
	u_Sdc_Perception_ObstacleDataB_t ObstacleDataB;
	u_Sdc_Perception_ObstacleDataC_t ObstacleDataC;
	u_Sdc_Perception_ObstacleDataD_t ObstacleDataD;
	u_Sdc_Perception_ObstacleDataE_t ObstacleDataE;
	u_Sdc_Perception_ObstacleDataF_t ObstacleDataF;
	u_Sdc_Perception_ObstacleDataG_t ObstacleDataG;
	u_Sdc_Perception_ObstacleDataH_t ObstacleDataH;
	u_Sdc_Perception_ObstacleDataI_t ObstacleDataI;
	u_Sdc_Perception_ObstacleDataJ_t ObstacleDataJ;
	u_Sdc_Perception_ObstacleDataK_t ObstacleDataK;
	u_Sdc_Perception_ObstacleDataL_t ObstacleDataL;
	u_Sdc_Perception_ObstacleDataM_t ObstacleDataM;
	u_Sdc_Perception_ObstacleDataN_t ObstacleDataN;
	u_Sdc_Perception_ObstacleDataO_t ObstacleDataO;
	u_Sdc_Perception_ObstacleDataP_t ObstacleDataP; // add by yf at 22.10.13
} s_Sdc_Perception_ObstacleData_Data_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Perception_ObstacleDataA_t) + sizeof(u_Sdc_Perception_ObstacleDataB_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataC_t) + sizeof(u_Sdc_Perception_ObstacleDataD_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataE_t) + sizeof(u_Sdc_Perception_ObstacleDataF_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataG_t) + sizeof(u_Sdc_Perception_ObstacleDataH_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataI_t) + sizeof(u_Sdc_Perception_ObstacleDataJ_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataK_t) + sizeof(u_Sdc_Perception_ObstacleDataL_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataM_t) + sizeof(u_Sdc_Perception_ObstacleDataN_t) +
			  sizeof(u_Sdc_Perception_ObstacleDataO_t) + sizeof(u_Sdc_Perception_ObstacleDataP_t)]; // add by yf at 22.10.14
	s_Sdc_Perception_ObstacleData_Data_t data;
} u_Sdc_Perception_ObstacleData_t;

typedef struct
{
	uint8 CutinSpeedValid : 4;
	uint8 ObsProNotOnRoadValid : 4;
	uint8 ObsProCoverdByOthersValid : 4;
	uint8 ObsProObserveJumpValid : 4;
	uint8 ObsProObserveSideValid : 4;
	uint8 ObsProBtTapLevel1Valid : 4;
	uint8 ObsProBtTapLevel2Valid : 4;
	uint8 ObsProBtTapLevel3Valid : 4;
	uint32 Obstacle_Internal_ID;
} s_Sdc_Perception_ObstacleInternalID_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleInternalID_Data_t data;
} u_Sdc_Perception_ObstacleInternalID_t;

typedef struct
{
	uint16 RollingCounter_Obstacle;
	uint16 reserved_4;
	uint32 CRCChecksum_Obstacle;
} s_Sdc_Perception_ObstacleCRC_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_ObstacleCRC_Data_t data;
} u_Sdc_Perception_ObstacleCRC_t;

typedef struct
{
	u_Sdc_Percption_Pattern_t ObstaclePattern;
	u_Sdc_Perception_ObstacleHeader1_t ObstacleHeader1;
	u_Sdc_Perception_ObstacleHeader2_t ObstacleHeader2;
	u_Sdc_Perception_ObstacleData_t ObstacleData[20];			  // 20-->10
	u_Sdc_Perception_ObstacleInternalID_t ObstacleInternalID[20]; // 20-->10
	u_Sdc_Perception_ObstacleCRC_t ObstacleCRC;
} s_Sdc_Perception_Obstacle_t;

// Lane
typedef struct
{
	uint16 LaneTrackID;
	uint8 LaneConfidence;
	uint8 LaneMeasuringStatus : 4;
	uint8 LaneTypeClass : 4;
	uint8 LaneMarkColor;
	uint8 LaneQuality;
	uint8 LaneCrossing;
	uint8 LaneWidthMarking;
} s_Sdc_Perception_LKA_LaneA_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LKA_LaneA_Data_t data;
} u_Sdc_Perception_LKA_LaneA_t;

typedef struct
{
	uint16 LaneViewRangeStart;
	uint16 LaneViewRangeEnd;
	uint16 LaneTLC;
	sint16 LaneModelC0;
} s_Sdc_Perception_LKA_LaneB_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LKA_LaneB_Data_t data;
} u_Sdc_Perception_LKA_LaneB_t;

typedef struct
{
	float32 LaneModelC1;
	float32 LaneModelC2;
} s_Sdc_Perception_LKA_LaneC_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LKA_LaneC_Data_t data;
} u_Sdc_Perception_LKA_LaneC_t;

typedef struct
{
	float32 LaneModelC3;
	uint8 ObstacleFlag : 4;
	uint8 LaneExtraNearPointType : 4;
	uint8 LaneExtraFarPointType : 4;
	uint8 Stopline_Relevancy : 4;
	uint16 LaneExtraFarPointPosX;
} s_Sdc_Perception_LKA_LaneD_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LKA_LaneD_Data_t data;
} u_Sdc_Perception_LKA_LaneD_t;

typedef struct
{
	sint16 LaneExtraFarPointPosY;
	uint16 LaneExtraNearPointPosX;
	sint16 LaneExtraNearPointPosY;
	uint8 LaneParsingConfidence;
	uint8 LineRmse;
} s_Sdc_Perception_LKA_LaneE_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LKA_LaneE_Data_t data;
} u_Sdc_Perception_LKA_LaneE_t;

typedef struct
{
	u_Sdc_Perception_LKA_LaneA_t LKA_LaneA;
	u_Sdc_Perception_LKA_LaneB_t LKA_LaneB;
	u_Sdc_Perception_LKA_LaneC_t LKA_LaneC;
	u_Sdc_Perception_LKA_LaneD_t LKA_LaneD;
	u_Sdc_Perception_LKA_LaneE_t LKA_LaneE;
} s_Sdc_Perception_LKA_Lane_Data_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Perception_LKA_LaneA_t) + sizeof(u_Sdc_Perception_LKA_LaneB_t) + sizeof(u_Sdc_Perception_LKA_LaneB_t) + sizeof(u_Sdc_Perception_LKA_LaneB_t) + sizeof(u_Sdc_Perception_LKA_LaneE_t)];
	s_Sdc_Perception_LKA_Lane_Data_t data;
} u_Sdc_Perception_LKA_Lane_t;

typedef struct
{
	uint16 LaneTrackID;
	uint8 LaneConfidence;
	uint8 LaneMeasuringStatus : 4;
	uint8 LaneTypeClass : 4;
	uint8 LaneQuality;
	uint8 ConeRoadEdgeParsingConfidence;
	uint16 ConeRoadEdgeViewRangeStart;
} s_Sdc_Perception_Cone_Road_Edge_A_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_Cone_Road_Edge_A_Data_t data;
} u_Sdc_Perception_Cone_Road_Edge_A_t;

typedef struct
{
	uint16 ConeRoadEdgeViewRangeEnd;
	sint16 ConeRoadEdgeModelC0;
	float32 ConeRoadEdgeModelC1;
} s_Sdc_Perception_Cone_Road_Edge_B_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_Cone_Road_Edge_B_Data_t data;
} u_Sdc_Perception_Cone_Road_Edge_B_t;

typedef struct
{
	float32 ConeRoadEdgeModelC2;
	float32 ConeRoadEdgeModelC3;
} s_Sdc_Perception_Cone_Road_Edge_C_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_Cone_Road_Edge_C_Data_t data;
} u_Sdc_Perception_Cone_Road_Edge_C_t;

typedef struct
{
	u_Sdc_Perception_Cone_Road_Edge_A_t ConeRoadEdge_A;
	u_Sdc_Perception_Cone_Road_Edge_B_t ConeRoadEdge_B;
	u_Sdc_Perception_Cone_Road_Edge_C_t ConeRoadEdge_C;
} s_Sdc_Perception_Cone_Road_Edge_Data_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Perception_Cone_Road_Edge_A_t) + sizeof(u_Sdc_Perception_Cone_Road_Edge_B_t) + sizeof(u_Sdc_Perception_Cone_Road_Edge_C_t)];
	s_Sdc_Perception_Cone_Road_Edge_Data_t data;
} u_Sdc_Perception_Cone_Road_Edge_t;

typedef struct
{
	uint8 RoadType;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint16 HostEstimatedWidth;
	uint8 CurrentWeather : 4;
	uint8 CurrentTime : 4;
	uint8 LightType : 4;
	uint8 DisStoplineValid : 4;
	sint16 DisStopline;
} s_Sdc_Perception_Road_Information_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_Road_Information_Data_t data;
} u_Sdc_Perception_Road_Information_t;

typedef struct
{
	uint16 LaneTrackID;
	uint8 LaneConfidence;
	uint8 LaneMeasuringStatus : 4;
	uint8 RoadEdgeTypeClass : 4;
	uint8 LaneQuality;
	uint8 RoadEdgeParsingConfidence;
	uint16 RoadEdgeViewRangeStart;
} u_Sdc_Perception_Road_Edge_A_Data_t;

typedef struct
{
	uint16 RoadEdgeViewRangeEnd;
	sint16 RoadEdgeModelC0;
	float RoadEdgeModelC1;
} u_Sdc_Perception_Road_Edge_B_Data_t;

typedef struct
{
	float RoadEdgeModelC2;
	float RoadEdgeModelC3;
} u_Sdc_Perception_Road_Edge_C_Data_t;

typedef union
{
	uint8 raw[8];
	u_Sdc_Perception_Road_Edge_A_Data_t data;
} u_Sdc_Perception_Road_Edge_A_t;

typedef union
{
	uint8 raw[8];
	u_Sdc_Perception_Road_Edge_B_Data_t data;
} u_Sdc_Perception_Road_Edge_B_t;

typedef union
{
	uint8 raw[8];
	u_Sdc_Perception_Road_Edge_C_Data_t data;
} u_Sdc_Perception_Road_Edge_C_t;

typedef struct
{
	u_Sdc_Perception_Road_Edge_A_t RoadEdge_A;
	u_Sdc_Perception_Road_Edge_B_t RoadEdge_B;
	u_Sdc_Perception_Road_Edge_C_t RoadEdge_C;
} s_Sdc_Perception_Road_Edge_Data_t;

typedef union
{
	uint8 raw[sizeof(u_Sdc_Perception_Road_Edge_A_t) + sizeof(u_Sdc_Perception_Road_Edge_B_t) + sizeof(u_Sdc_Perception_Road_Edge_C_t)];
	s_Sdc_Perception_Road_Edge_Data_t data;
} u_Sdc_Perception_Road_Edge_t;

typedef struct
{
	uint8 RollingCounter_Lane;
	uint8 reserved_1;
	uint16 reserved_0;
	uint32 CRCChecksum_Lane;
} s_Sdc_Perception_LaneCRC_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_LaneCRC_Data_t data;
} u_Sdc_Perception_LaneCRC_t;

typedef struct
{
	u_Sdc_Percption_Pattern_t LanePattern;
	u_Sdc_Perception_LKA_Lane_t LKA_Left_Lane;
	u_Sdc_Perception_LKA_Lane_t LKA_Right_Lane;
	u_Sdc_Perception_LKA_Lane_t Next_Left_Lane;
	u_Sdc_Perception_LKA_Lane_t Next_Right_Lane;
	u_Sdc_Perception_LKA_Lane_t Left_Outer_Lane;
	u_Sdc_Perception_LKA_Lane_t Right_Outer_Lane;
	u_Sdc_Perception_Cone_Road_Edge_t Left_Cone_Road_Edge;
	u_Sdc_Perception_Cone_Road_Edge_t Right_Cone_Road_Edge;
	u_Sdc_Perception_Road_Edge_t Left_Road_Edge;
	u_Sdc_Perception_Road_Edge_t Right_Road_Edge;
	u_Sdc_Perception_Road_Information_t Road_Information;
	u_Sdc_Perception_LaneCRC_t Lane_CRC;
} s_Sdc_Perception_Lane_t;

// TSR
typedef struct
{
	uint16 u16_type;
	uint16 u16_priority;
} s_Sdc_TrafficSign_SortType;

typedef struct
{
	uint8 TSRObjectsNumber;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint16 reserved_0 : 12;
	uint16 RollingCounter_TSR : 4;
	uint32 CRCChecksum_TSR;
} s_Sdc_Perception_TSR_Header_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TSR_Header_Data_t data;
} u_Sdc_Perception_TSR_Header_t;

typedef struct
{
	uint8 TSR_ID : 4;
	uint8 TSR_Relevancy : 4;
	uint8 TSR_Confidence;
	uint16 TrafficSignType;
	uint8 RoadMarkType;
	uint8 TSR_Filter_Type : 4;
	uint8 TSR_Approved_Flag : 4;
	uint8 TSR_Type : 4;
	uint8 TrafficSign_ChildType : 4;
	uint8 TSR_Internal_ID;
} s_Sdc_Perception_TSR_DataA_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TSR_DataA_Data_t data;
} u_Sdc_Perception_TSR_DataA_t;

typedef struct
{
	uint16 TSR_AttrValue;
	uint16 Sign_Position_X;
	sint16 Sign_Position_Y;
	uint16 Sign_Position_Z;
} s_Sdc_Perception_TSR_DataB_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TSR_DataB_Data_t data;
} u_Sdc_Perception_TSR_DataB_t;

typedef struct
{
	u_Sdc_Perception_TSR_Header_t TSR_Header;
	u_Sdc_Perception_TSR_DataA_t TSR_DataA[16];
	u_Sdc_Perception_TSR_DataB_t TSR_DataB[16];
} s_Sdc_Perception_TSR_t;

typedef struct
{
	uint16 slblacklist[5];
	uint16 slblacklistnumber;
	uint32 slblacklist_frameID[5];
} s_Sdc_uSpeedLimitblacklistData_t;

#if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)
// TFL
typedef struct
{
	uint8 TFLObjectsNumber : 4;
	uint8 TFLMainObjectID : 4;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint16 reserved_0 : 12;
	uint16 RollingCounter_TFL : 4;
	uint32 CRCChecksum_TFL;
} s_Sdc_Perception_TFL_Header_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TFL_Header_Data_t data;
} u_Sdc_Perception_TFL_Header_t;

typedef struct
{
	uint8 TFL_Internal_ID;
	uint8 TFL_ID : 4;
	uint8 TFL_Color : 4;
	uint8 reserved;
	uint8 TFL_Confidence;
	uint16 TFL_PosX;
	sint16 TFL_PosY;
} s_Sdc_Perception_TFL_DataA_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TFL_DataA_Data_t data;
} u_Sdc_Perception_TFL_DataA_t;

typedef struct
{
	uint8 TFL_Width;
	uint8 TFL_ShapeType : 4;
	uint8 reserved_1 : 4;
	uint8 TFL_ClassificationType_1;
	uint8 is_TFL_Blinking_1 : 4;
	uint8 TFL_Bulb_Color_1 : 4;
	uint16 TFL_PosZ;
	uint16 reserved_2;
} s_Sdc_Perception_TFL_DataB_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_TFL_DataB_Data_t data;
} u_Sdc_Perception_TFL_DataB_t;

typedef struct
{
	u_Sdc_Perception_TFL_Header_t TFL_Header;
	u_Sdc_Perception_TFL_DataA_t TFL_DataA[8];
	u_Sdc_Perception_TFL_DataB_t TFL_DataB[8];
} s_Sdc_Perception_TFL_t;

typedef struct
{
	uint8 BBoxObjectsNumber : 8;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint16 reserved_0 : 12;
	uint16 RollingCounter_LM : 4;
	uint32 CRCChecksum_LM;
} s_Sdc_Perception_LM_Header_t;

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_Header_t LM_Header_Layout;
} s_Sdc_Perception_LM_Header_Uon_t;

typedef struct
{
	uint8 LM_ID;
	uint8 LM_Internal_ID;
	uint8 LM_Confidence;
	uint8 LaneMarkingType;
	uint16 LM_Position_X;
	sint16 LM_Position_Y;
} s_Sdc_Perception_LM_DataA_t;

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_DataA_t LM_DataA_Layout;
} s_Sdc_Perception_LM_DataA_Uon_t;

typedef struct
{
	uint8 StopLine_Flag : 4;
	uint8 CrossWalk_Flag : 4;
	uint8 SpeedBump_Flag : 4;
	uint8 Pole1Detected_Flag : 2; // add by yf at 22.10.13
	uint8 Pole2Detected_Flag : 2; // add by yf at 22.10.13
	uint16 StopLine_Distance;
	uint16 CrossWalk_Distance;
	uint16 SpeedBump_Distance;
} s_Sdc_Perception_LM_BBox_DataA_t;

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_BBox_DataA_t LM_BBox_DataA_Layout;
} s_Sdc_Perception_LM_BBox_DataA_Uon_t;

typedef struct
{
	uint8 StaticObj_Type : 4;
	uint8 StaticObj_EgoVehile : 4; // change by yf at 22.10.12
	uint8 StaticObj_TrackID;
	uint16 reserved_3;
	uint16 StaticObj_Position_X;
	sint16 StaticObj_Position_Y;
} s_Sdc_Perception_LM_BBox_StaticObj_Data_t;

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_BBox_StaticObj_Data_t StaticObj_Data_Layout;
} s_Sdc_Perception_LM_BBox_StaticObj_Data_Uon_t;

typedef struct
{
	float32 Pole_LiftAng;
	uint16 Pole_Dx;
	uint16 Pole_Dy;
} s_Sdc_Perception_LM_Pole_Data_t; // add by yf at 22.10.12

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_Pole_Data_t Pole_Data_Layout;
} s_Sdc_Perception_LM_Pole_Data_Uon_t; // add by yf at 22.10.12

typedef struct
{
	uint8 Pole_DataType : 4;
	uint8 reserved_1 : 4;
	uint8 reserved_2;
	uint16 reserved_3;
	float32 reserved_4;
} s_Sdc_Perception_LM_Pole_DataA_t; // add by yf at 22.10.12

typedef union
{
	uint8 data[8];
	s_Sdc_Perception_LM_Pole_DataA_t Pole_DataA_Layout;
} s_Sdc_Perception_LM_Pole_DataA_Uon_t; // add by yf at 23.1.12

typedef struct
{
	s_Sdc_Perception_LM_Header_Uon_t LM_Header_msg;
	s_Sdc_Perception_LM_DataA_Uon_t LM_DataA_Array[3u]; /*middle right left*/
	s_Sdc_Perception_LM_BBox_DataA_Uon_t LM_BBox_DataA;
	s_Sdc_Perception_LM_BBox_StaticObj_Data_Uon_t StaticObj_Data[20u];
	s_Sdc_Perception_LM_Pole_Data_Uon_t Pole_Data[2u];	 // add by yf at 22.10.12
	s_Sdc_Perception_LM_Pole_DataA_Uon_t Pole_DataA[2u]; // add by yf at 23.1.12
} s_Sdc_Perception_LM_t;

typedef struct
{
	u_Sdc_Percption_Pattern_t TSR_TFL_Pattern;
	s_Sdc_Perception_TSR_t TSR_Data;
	s_Sdc_Perception_TFL_t TFL_Data;
} s_Sdc_Perception_TSR_TFL_t;
#endif

#if (SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE == STD_ON)
// AEB Flag
typedef struct
{
	float32 AEB_Brake_Decel_Req;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint8 RollingCounter_AEB;
	uint8 reserved_0;
} s_Sdc_Perception_AEB_Header_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Header_Data_t data;
} u_Sdc_Perception_AEB_Header_t;

typedef struct
{
	uint32 FCW_Supp_Reason;
	uint32 AEB_Supp_Reason;
} s_Sdc_Perception_AEB_Supp_Reason_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Supp_Reason_Data_t data;
} u_Sdc_Perception_AEB_Supp_Reason_t;

typedef struct
{
	uint8 AEB_LatentWarn : 4;
	uint8 AEB_Obj_Type_LatentWarn : 4;
	uint8 AEB_Obj_ID_LatentWarn;
	uint16 AEB_Obj_TTC_LatentWarn;
	uint8 AEB_Obj_Type_PreWarn : 4;
	uint8 AEB_PreWarn : 4;
	uint8 AEB_Obj_ID_PreWarn;
	uint16 AEB_Obj_TTC_PreWarn;
} s_Sdc_Perception_AEB_Level_Message1_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Level_Message1_Data_t data;
} u_Sdc_Perception_AEB_Level_Message1_t;

typedef struct
{
	uint8 AEB_Prefill : 4;
	uint8 AEB_Obj_Type_Prefill : 4;
	uint8 AEB_Obj_ID_Prefill;
	uint16 AEB_Obj_TTC_Prefill;
	uint8 AEB_Jerk : 4;
	uint8 AEB_Obj_Type_Jerk : 4;
	uint8 AEB_Obj_ID_Jerk;
	uint16 AEB_Obj_TTC_Jerk;
} s_Sdc_Perception_AEB_Level_Message2_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Level_Message2_Data_t data;
} u_Sdc_Perception_AEB_Level_Message2_t;

typedef struct
{
	uint8 AEB_PartialBrake : 4;
	uint8 AEB_Obj_Type_PartialBrake : 4;
	uint8 AEB_Obj_ID_PartialBrake;
	uint16 AEB_Obj_TTC_PartialBrake;
	uint8 AEB_FullBrake : 4;
	uint8 AEB_Obj_Type_FullBrake : 4;
	uint8 AEB_Obj_ID_FullBrake;
	uint16 AEB_Obj_TTC_FullBrake;
} s_Sdc_Perception_AEB_Level_Message3_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Level_Message3_Data_t data;
} u_Sdc_Perception_AEB_Level_Message3_t;

typedef struct
{
	uint8 AEB_EBA : 4;
	uint8 AEB_Obj_Type_EBA : 4;
	uint8 AEB_Obj_ID_EBA;
	uint16 AEB_Obj_TTC_EBA;
	uint8 AEB_Hold : 4;
	uint8 AEB_Obj_Type_Hold : 4;
	uint8 AEB_Obj_ID_Hold;
	uint16 AEB_Obj_TTC_Hold;
} s_Sdc_Perception_AEB_Level_Message4_Data_t;

typedef union
{
	uint8 raw[8];
	s_Sdc_Perception_AEB_Level_Message4_Data_t data;
} u_Sdc_Perception_AEB_Level_Message4_t;

typedef struct
{
	u_Sdc_Percption_Pattern_t AEBPattern;
	u_Sdc_Perception_AEB_Header_t AEB_Header;
	u_Sdc_Perception_AEB_Supp_Reason_t AEB_Supp_Reason;
	u_Sdc_Perception_AEB_Level_Message1_t AEB_Level_Msg1;
	u_Sdc_Perception_AEB_Level_Message2_t AEB_Level_Msg2;
	u_Sdc_Perception_AEB_Level_Message3_t AEB_Level_Msg3;
	u_Sdc_Perception_AEB_Level_Message4_t AEB_Level_Msg4;
} s_Sdc_Perception_AEB_Flag_t;
#endif

// Perception Data
typedef struct
{
	uint32 id;
	uint32 reserved;
} Pattern_Data;

typedef union
{
	Pattern_Data pattern_Data;
	uint8 unused[8];
} FunctionId;
typedef struct
{
	uint8 IHBC_Decision : 4;
	uint8 ProtocolMajorVersion : 4;
	uint8 ProtocolMinorVersion : 4;
	uint8 reserved_0 : 4;
	uint16 reserved_1;
	float32 Cal_lux_up;
} IHBC_HighLowBeam;

typedef union
{
	uint8 data[8];
	IHBC_HighLowBeam IHBC_HighLowBeam_Layout;
} IHBC_HighLowBeam_Uon;

typedef struct 
{
  float32 Cal_lux;
  uint16 reserved_0;
  uint16 reserved_1;
} IHBC_HighLowBeam_01;

typedef union 
{
  uint8 data[8];
  IHBC_HighLowBeam_01 IHBC_HighLowBeam_Layout_01;
} IHBC_HighLowBeam_Uon_01;
typedef struct
{
	FunctionId IHBC_id;
	IHBC_HighLowBeam_Uon HighLowBeam_msg;
	IHBC_HighLowBeam_Uon_01 HighLowBeam_msg_01;
} s_Sdc_Perception_IHBC_t;

typedef struct
{
	u_Sdc_Perception_Sync_t Sync;
	s_Sdc_Perception_Obstacle_t Obstance;
	s_Sdc_Perception_Lane_t Lane;
#if (SDC_PERCEPTION_TSR_TFL_STRUCT_ENABLE == STD_ON)
	s_Sdc_Perception_TSR_TFL_t TSR_TFL;
	s_Sdc_Perception_LM_t LM;

#endif
	s_Sdc_Perception_IHBC_t IHBC;
#if (SDC_PERCEPTION_AEB_FLAG_STRUCT_ENABLE == STD_ON)
	s_Sdc_Perception_AEB_Flag_t AEB;
#endif
} s_Sdc_Perception_Data_t;

#endif /* _SDC_PERCEPTION_TYPE_H_ */
