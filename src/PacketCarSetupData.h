// File: PacketCarSetupData.h
#ifndef PACKETCARSETUPDATA_H
#define PACKETCARSETUPDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct CarSetupData
{
    uint8_t m_frontWing; // Front wing aero
    uint8_t m_rearWing; // Rear wing aero
    uint8_t m_onThrottle; // Differential adjustment on throttle (percentage)
    uint8_t m_offThrottle; // Differential adjustment off throttle (percentage)
    float m_frontCamber; // Front camber angle (suspension geometry)
    float m_rearCamber; // Rear camber angle (suspension geometry)
    float m_frontToe; // Front toe angle (suspension geometry)
    float m_rearToe; // Rear toe angle (suspension geometry)
    uint8_t m_frontSuspension; // Front suspension
    uint8_t m_rearSuspension; // Rear suspension
    uint8_t m_frontAntiRollBar; // Front anti-roll bar
    uint8_t m_rearAntiRollBar; // Front anti-roll bar
    uint8_t m_frontSuspensionHeight; // Front ride height
    uint8_t m_rearSuspensionHeight; // Rear ride height
    uint8_t m_brakePressure; // Brake pressure (percentage)
    uint8_t m_brakeBias; // Brake bias (percentage)
    uint8_t m_engineBraking; // Engine braking (percentage)
    float m_rearLeftTyrePressure; // (PSI)
    float m_rearRightTyrePressure; // (PSI)
    float m_frontLeftTyrePressure; // PSI)
    float m_frontRightTyrePressure; // (PSI)
    uint8_t m_ballast; // Ballast
    float m_fuelLoad; // Fuel load
};

class PacketCarSetupData : public PHeader
{
public:
    PacketCarSetupData();
    virtual ~PacketCarSetupData();
    CarSetupData m_carSetups(int index);
    float m_nextFrontWingValue(void);
    void push(char *receiveBuffer);

private:
    CarSetupData m_carSetups_[22];
    float m_nextFrontWingValue_;
};
#pragma pack(pop)

#endif 

