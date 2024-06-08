// File: PacketMotionData.h
#ifndef PACKETMOTIONDATA_H
#define PACKETMOTIONDATA_H

#include "PHeader.h"

#pragma pack(push, 1)

struct CarMotionData
{
    float m_worldPositionX; // World space X position
    float m_worldPositionY; // World space Y position
    float m_worldPositionZ; // World space Z position
    float m_worldVelocityX; // Velocity in world space X
    float m_worldVelocityY; // Velocity in world space Y
    float m_worldVelocityZ; // Velocity in world space Z
    int16_t m_worldForwardDirX; // World space forward X direction (normalised)
    int16_t m_worldForwardDirY; // World space forward Y direction (normalised)
    int16_t m_worldForwardDirZ; // World space forward Z direction (normalised)
    int16_t m_worldRightDirX; // World space right X direction (normalised)
    int16_t m_worldRightDirY; // World space right Y direction (normalised)
    int16_t m_worldRightDirZ; // World space right Z direction (normalised)
    float m_gForceLateral; // Lateral G-Force component
    float m_gForceLongitudinal; // Longitudinal G-Force component
    float m_gForceVertical; // Vertical G-Force component
    float m_yaw; // Yaw angle in radians
    float m_pitch; // Pitch angle in radians
    float m_roll; // Roll angle in radians
};

class PacketMotionData : public PHeader
{
public:
    PacketMotionData();
    virtual ~PacketMotionData();
    CarMotionData m_carMotionData(int index);
    void push(char *receiveBuffer);

private:
    CarMotionData m_carMotionData_[22]; //22 elements
};
#pragma pack(pop)

#endif /* PACKETMOTIONDATA_H */

