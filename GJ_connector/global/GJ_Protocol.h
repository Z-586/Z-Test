#ifndef GJ_PROTOCOL_H
#define GJ_PROTOCOL_H
#include <QObject>
#include "constant.h"

//结构体数据的补齐
#pragma pack(push, 1)
typedef union Flag_Data
{
    struct
    {
       uint8_t GNSS_Pos_enable:1;
       uint8_t GNSS_Vel_enable:1;
       uint8_t GNSS_Heading_enable:1;
       uint8_t GNSS_Wheel_enable:1;
       uint8_t GNSS_NHC_enable:1;
       uint8_t GNSS_ZUPT_enable:1;
       uint8_t GNSS_Install_flag:1;
       uint8_t GNSS_Static_flag:1;
    }b;
    uint8_t byte;
}Flag_Data_t;

typedef union GNSS_Flag
{
    struct
    {
       uint8_t GNSS_VelPosTime_Sign:1;
       uint8_t GNSS_HeadingPosTime_Sign:1;
       uint8_t GNSS_PosValid:1;
       uint8_t GNSS_VelValid:1;
       uint8_t GNSS_HeadingValid:1;
       uint8_t Reserved:3;
    }b;
    uint8_t byte;
}GNSS_Flag_t;

typedef union WheelSpdDir_Flag
{
    struct
    {
        uint8_t FL_Dir:2;
        uint8_t FR_Dir:2;
        uint8_t RL_Dir:2;
        uint8_t RR_Dir:2;
    }b;
    uint8_t byte;
}WheelSpdDir_Flag_t;

typedef union ChassisDir_Flag
{
    struct
    {
        uint8_t VehicleSpd_Dir:2;
        uint8_t SteerAng_Dir:2;
        uint8_t SteerVel_Dir:2;
        uint8_t Torque_Dir:2;
    }b;
    uint8_t byte;
}ChassisDir_Flag_t;

typedef union ChassisValid_Flag
{
    struct
    {
        uint8_t WheelSpd_FL_Ava:1;
        uint8_t WheelSpd_FR_Ava:1;
        uint8_t WheelSpd_RL_Ava:1;
        uint8_t WheelSpd_RR_Ava:1;
        uint8_t VehicleSpd_Ava:1;
        uint8_t SteerAng_Ava:1;
        uint8_t SteerVel_Ava:1;
        uint8_t Torque_Ava:1;
    }b;
    uint8_t byte;
}ChassisValid_Flag_t;

typedef union ChassisValid2_Flag
{
    struct
    {
        uint8_t Pedal_Valid:2;
        uint8_t Reserved:6;
    }b;
    uint8_t byte;
}ChassisValid2_Flag_t;



typedef struct GJDeVice_Msg
{
    /*** start of user segment ***/
    uint8_t Header[4];
    int32_t Latitude;
    int32_t Longitude;
    int32_t Height;
    int16_t VE;
    int16_t VN;
    int16_t VU;
    int16_t Pitch;
    int16_t Roll;
    int16_t Yaw;
    uint8_t INS_Status;
    uint16_t GNSS_Week;
    uint32_t GNSS_Ms;
    uint8_t GNSS_PosStatus;
    uint8_t GNSS_Antenna;
    uint8_t GNSS_Antenna2;
    int16_t ALG_Accl_X;
    int16_t ALG_Accl_Y;
    int16_t ALG_Accl_Z;
    int16_t ALG_Gyro_X;
    int16_t ALG_Gyro_Y;
    int16_t ALG_Gyro_Z;
    int16_t ALG_IMU_Temp;
    uint16_t Lever_Pos_Sigma;
    uint16_t Height_Sigma;
    uint16_t Lever_Vel_Sigma;
    uint16_t VU_Sigma;
    uint16_t Lever_angel_Sigma;
    uint16_t Yaw_Sigma;
    uint8_t UserCRC;
    /*** end of user segment ***/
    int16_t Temp;
    int16_t Accl_X;
    int16_t Accl_Y;
    int16_t Accl_Z;
    int16_t Gyro_X;
    int16_t Gyro_Y;
    int16_t Gyro_Z;
    uint32_t PpsCount;
    uint8_t reserved;
    uint16_t Longitude_Sigma;
    uint16_t VE_Sigma;
    uint16_t Pitch_Sigma;
    Flag_Data_t Flag_Data;
    uint8_t PollIndex;
    uint8_t PollData_u8[8];
    uint32_t MCU_10msCount;
    float GNSS_Latitude_Int;
    float GNSS_Latitude_Dec;
    float GNSS_Longitude_Int;
    float GNSS_Longitude_Dec;
    int32_t GNSS_Height;
    int16_t GNSS_VE;
    int16_t GNSS_VN;
    int16_t GNSS_VU;
    int16_t GNSS_Heading;
    int16_t GNSS_Course;
    uint16_t GNSS_Latitude_Rms;
    uint16_t GNSS_Longitude_Rms;
    uint16_t GNSS_Height_Rms;
    uint16_t GNSS_Heading_Rms;
    uint8_t GNSS_PosDelay;
    uint8_t GNSS_VelDelay;
    uint8_t GNSS_HeadingDelay;
    uint32_t GNSS_PosTime_ms;
    uint8_t GNSS_VelPosTime;
    uint8_t GNSS_HeadingPosTime;
    GNSS_Flag_t GNSS_Flag;
    uint16_t WheelSpd_FL;
    uint16_t WheelSpd_FR;
    uint16_t WheelSpd_RL;
    uint16_t WheelSpd_RR;
    uint16_t VehicleSpd;
    uint16_t SteerAng;
    uint16_t SteerVel;
    uint8_t PedalPos;
    WheelSpdDir_Flag_t WheelSpdDir_Flag;
    ChassisDir_Flag_t ChassisDir_Flag;
    ChassisValid_Flag_t ChassisValid_Flag;
    ChassisValid2_Flag_t ChassisValid2_Flag;
    uint8_t AuthCRC;
    /*** end of author segment ***/
}GJDeVice_Msg_920Vertion;

typedef union GJDeVice_MsgBuf
{
    GJDeVice_Msg_920Vertion GJDeVice_Msg;
    uint8_t bytes[receive_GJProtocol_length] = {0};
}GJDeVice_MsgBuf_920Vertion;



// vsms 1000
typedef struct GJDeVice_Msg_1000
  {
      /*** start of user segment ***/
      uint8_t Header[4];
      int32_t Latitude;
      int32_t Longitude;
      int32_t Height;
      int16_t VE;
      int16_t VN;
      int16_t VU;
      int16_t Pitch;
      int16_t Roll;
      int16_t Yaw;
      uint8_t INS_Status;
      uint16_t GNSS_Week;
      uint32_t GNSS_Ms;
      uint8_t GNSS_PosStatus;
      uint8_t GNSS_Antenna;
      uint8_t GNSS_Antenna2;
      int16_t ALG_Accl_X;
      int16_t ALG_Accl_Y;
      int16_t ALG_Accl_Z;
      int16_t ALG_Gyro_X;
      int16_t ALG_Gyro_Y;
      int16_t ALG_Gyro_Z;
      int16_t ALG_IMU_Temp;
      uint16_t Lever_Pos_Sigma;
      uint16_t Height_Sigma;
      uint16_t Lever_Vel_Sigma;
      uint16_t VU_Sigma;
      uint16_t Lever_angel_Sigma;
      uint16_t Yaw_Sigma;
      int16_t INS_Vehicle_longitudinal;
      int16_t INS_Vehicle_lateral;
      int16_t INS_Vehicle_vertical;
      int16_t INS_Vehicle_Sideslipangle;
      uint8_t UserCRC;
      /*** end of user segment ***/

      int16_t reserved[3];
      uint32_t Pps_count;
      uint8_t _1s_PPS_fix_ErrorCount;
      uint16_t Longitude_Sigma;
      uint16_t VE_Sigma;
      uint16_t Pitch_Sigma;
      Flag_Data_t Flag_Data;
      uint8_t PollIndex;
      uint8_t PollData_u8[8];
      uint32_t MCU_10msCount;
      float GNSS_Latitude_Int;
      float GNSS_Latitude_Dec;
      float GNSS_Longitude_Int;
      float GNSS_Longitude_Dec;
      int32_t GNSS_Height;
      int16_t GNSS_VE;
      int16_t GNSS_VN;
      int16_t GNSS_VU;
      int16_t GNSS_Heading;
      int16_t GNSS_Course;
      uint16_t GNSS_Latitude_Rms;
      uint16_t GNSS_Longitude_Rms;
      uint16_t GNSS_Height_Rms;
      uint16_t GNSS_Heading_Rms;
      uint8_t GNSS_PosDelay;
      uint8_t GNSS_VelDelay;
      uint8_t GNSS_HeadingDelay;
      uint32_t GNSS_PosTime_ms;
      uint8_t GNSS_VelPosTime;
      uint8_t GNSS_HeadingPosTime;
      GNSS_Flag_t GNSS_Flag;
      uint16_t WheelSpd_FL;
      uint16_t WheelSpd_FR;
      uint16_t WheelSpd_RL;
      uint16_t WheelSpd_RR;
      uint16_t VehicleSpd;
      uint16_t SteerAng;
      uint16_t SteerVel;
      uint8_t PedalPos;
      WheelSpdDir_Flag_t WheelSpdDir_Flag;
      ChassisDir_Flag_t ChassisDir_Flag;
      ChassisValid_Flag_t ChassisValid_Flag;
      ChassisValid2_Flag_t ChassisValid2_Flag;
      uint8_t AuthCRC;
      /*** end of author segment ***/
}GJDeVice_Msg_1000Vertion;

typedef union GJDeVice_MsgBuf_1000
{
  GJDeVice_Msg_1000Vertion GJDeVice_Msg;
  uint8_t bytes[receive_GJProtocol_length] = {0};
}GJDeVice_MsgBuf_1000Vertion;


// vsms100
typedef struct GJDeVice_Dynamic_Msg
{
    uint8_t head[8];
    int16_t Level[3];
    int16_t AngGNSS2Vehicle[3];
    int16_t AngIMU2Vehicle[3];
    uint8_t CRC;
}GJDeVice_Dynamic_Msg_t;

typedef union GJDeVice_Dynamic_MsgBuf
{
    GJDeVice_Dynamic_Msg_t GJDeVice_Dynamic_Msg;
    uint8_t bytes[receive_Calibration_DynamicSuccess_length] = {0};
}GJDeVice_Dynamic_MsgBuf_t;


#pragma pack(pop)



#endif // GJ_PROTOCOL_H
