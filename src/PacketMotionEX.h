// File: PacketMotionEX.h
#ifndef PACKETMOTIONEX_H
#define PACKETMOTIONEX_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct MotionEXData {
    float m_suspensionPosition[4]; // Note: All wheel arrays have the following order:
    float m_suspensionVelocity[4]; // RL, RR, FL, FR
    float m_suspensionAcceleration[4]; // RL, RR, FL, FR
    float m_wheelSpeed[4]; // Speed of each wheel
    float m_wheelSlipRatio[4]; // Slip ratio for each wheel
    float m_wheelSlipAngle[4]; // Slip angles for each wheel
    float m_wheelLatForce[4]; // Lateral forces for each wheel
    float m_wheelLongForce[4]; // Longitudal forces for each wheel
    float m_heightOfCOGAboveGround; // Height of Centre of Gravity above the ground
    float m_localVelocityX; // Velocity in local space - m/s
    float m_localVelocityY; // Velocity in local space - m/s
    float m_localVelocityZ; // Velocity in local space - m/s
    float m_angularVelocityX; // Angular velocity x-component - rad/s
    float m_angularVelocityY; // Angular velocity y-component - rad/s
    float m_angularVelocityZ; // Angular velocity z-component - rad/s
    float m_angularAccelerationX; // Angular velocity x-component - rad/s
    float m_angularAccelerationY; // Angular velocity y-component - rad/s
    float m_angularAccelerationZ; // Angular velocity z-component - rad/s
    float m_frontWheelsAngle; // Current front wheels angle - rad/s
    float m_wheelVertForce[4]; // Vertical forces for each wheel
    float m_frontAeroHeight;
    float m_rearAeroHeight;
    float m_frontRollAngle;
    float m_rearRollAngle;
    float chassisYaw;
};

class PacketMotionEXData : public PHeader
{
public:
    PacketMotionEXData();
    virtual ~PacketMotionEXData();
    MotionEXData m_carMotionEXData();
    void push(char *receiveBuffer);

private:
    MotionEXData m_carMotionEXData_; //Players car only
};
#pragma pack(pop)

#endif