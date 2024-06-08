// File: PacketCarStatusData.h
#ifndef PACKETCARSTATUSDATA_H
#define PACKETCARSTATUSDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct CarStatusData
{
    uint8_t m_tractionControl; // Traction control - 0 = off, 1 = medium, 2 = full
    uint8_t m_antiLockBrakes; // 0 (off) - 1 (on)
    uint8_t m_fuelMix; // Fuel mix - 0 = lean, 1 = standard, 2 = rich, 3 = max
    uint8_t m_frontBrakeBias; // Front brake bias (percentage)
    uint8_t m_pitLimiterStatus; // Pit limiter status - 0 = off, 1 = on
    float m_fuelInTank; // Current fuel mass
    float m_fuelCapacity; // Fuel capacity
    float m_fuelRemainingLaps; // Fuel remaining in terms of laps (value on MFD)
    uint16_t m_maxRPM; // Cars max RPM, point of rev limiter
    uint16_t m_idleRPM; // Cars idle RPM
    uint8_t m_maxGears; // Maximum number of gears
    uint8_t m_drsAllowed; // 0 = not allowed, 1 = allowed
    uint16_t m_drsActivationDistance; // 0 = DRS not available, non-zero - DRS will be available 
    //in [X] metres
    uint8_t m_actualTyreCompound; // F1 Modern - 16 = C5, 17 = C4, 18 = C3, 19 = C2, 20 = C1
    // 7 = inter, 8 = wet
    // F1 Classic - 9 = dry, 10 = wet
    // F2 – 11 = super soft, 12 = soft, 13 = medium, 14 = hard
    // 15 = wet
    uint8_t m_visualTyreCompound; // F1 visual (can be different from actual compound)
    // 16 = soft, 17 = medium, 18 = hard, 7 = inter, 8 = wet
    // F1 Classic – same as above
    // F2 ‘19, 15 = wet, 19 – super soft, 20 = soft
    // 21 = medium , 22 = hard
    uint8_t m_tyresAgeLaps; // Age in laps of the current set of tyres
    int8_t m_vehicleFiaFlags; // -1 = invalid/unknown, 0 = none, 1 = green
    // 2 = blue, 3 = yellow, 4 = red
    float m_engine_power_ice;
    float m_engine_power_mguk;
    float m_ersStoreEnergy; // ERS energy store in Joules
    uint8_t m_ersDeployMode; // ERS deployment mode, 0 = none, 1 = medium
    // 2 = hotlap, 3 = overtake
    float m_ersHarvestedThisLapMGUK; // ERS energy harvested this lap by MGU-K
    float m_ersHarvestedThisLapMGUH; // ERS energy harvested this lap by MGU-H
    float m_ersDeployedThisLap; // ERS energy deployed this lap
    uint8_t m_networkPaused; // Whether the car is paused in a network game
};

class PacketCarStatusData : public PHeader
{
public:
    PacketCarStatusData();
    virtual ~PacketCarStatusData();
    CarStatusData m_carStatusData(int index);
    void push(char *receiveBuffer);


private:
    CarStatusData m_carStatusData_[22];
};
#pragma pack(pop)

#endif 

