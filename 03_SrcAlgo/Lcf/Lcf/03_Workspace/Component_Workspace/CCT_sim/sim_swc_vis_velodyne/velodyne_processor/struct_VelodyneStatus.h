#pragma pack(push, 1)
struct SUDExDataPackage_VelodyneStatus
{
	unsigned __int8 VelodyneStatus_MetaInfo_SourceIPAddress[4];
	unsigned __int32 VelodyneStatus_MetaInfo_SourcePort;
	unsigned __int8 VelodyneStatus_MetaInfo_DestinationIPAddress[4];
	unsigned __int32 VelodyneStatus_MetaInfo_DestinationPort;
	unsigned __int32 VelodyneStatus_MetaInfo_TotalPacketCount;
	float VelodyneStatus_Status_GPS_time_at_the_top_of_the_hour;
	unsigned __int8 VelodyneStatus_Status_Hours;
	unsigned __int8 VelodyneStatus_Status_Minutes;
	unsigned __int8 VelodyneStatus_Status_Seconds;
	unsigned __int8 VelodyneStatus_Status_Date;
	unsigned __int8 VelodyneStatus_Status_Month;
	unsigned __int8 VelodyneStatus_Status_Year_since_2000;
	unsigned __int8 VelodyneStatus_Status_GPS_reception_status_ID;
	unsigned __int8 VelodyneStatus_Status_Temperature_at_sensor_head;
	unsigned __int8 VelodyneStatus_Status_Firmware_version;
};
#pragma pack(pop)
