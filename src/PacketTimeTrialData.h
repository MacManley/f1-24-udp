// File: PacketTimeTrialData.h
#ifndef PACKETTIMETRIALDATA_H
#define PACKETTIMETRIALDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct TimeTrialDataSet {
    uint8_t m_carIdx; // Index of the car this data relates to
    uint8_t m_teamId; // Team id - see appendix
    uint32_t m_lapTimeInMS; // Lap time in milliseconds
    uint32_t m_sector1TimeInMS; // Sector 1 time in milliseconds
    uint32_t m_sector2TimeInMS; // Sector 2 time in milliseconds
    uint32_t m_sector3TimeInMS; // Sector 3 time in milliseconds
    uint8_t m_tractionControl; // 0 = off, 1 = medium, 2 = full
    uint8_t m_gearboxAssist; // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8_t m_antiLockBrakes; // 0 (off) - 1 (on)
    uint8_t m_equalCarPerformance; // 0 = Realistic, 1 = Equal
    uint8_t m_customSetup; // 0 = No, 1 = Yes
    uint8_t m_valid; // 0 = invalid, 1 = valid
};

class PacketTimeTrialData : public PHeader
{
public:
    PacketTimeTrialData();
    virtual ~PacketTimeTrialData();
    TimeTrialDataSet m_playerSessionBestDataSet(void);
    TimeTrialDataSet m_personalBestDataSet(void);
    TimeTrialDataSet m_rivalDataSet(void);
    void push(char *receiveBuffer);

private:
    TimeTrialDataSet m_playerSessionBestDataSet_; // Player session best data set
    TimeTrialDataSet m_personalBestDataSet_; // Personal best data set
    TimeTrialDataSet m_rivalDataSet_; // Rival data set
};

#pragma pack(pop)

#endif