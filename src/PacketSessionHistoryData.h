// File: PacketSessionHistoryData.h
#ifndef PACKETSESSIONHISTORYDATA_H
#define PACKETSESSIONHISTORYDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct LapHistoryData
{
    uint32_t m_lapTimeInMS; // Lap time in milliseconds
    uint16_t m_sector1TimeInMS; // Sector 1 time in milliseconds
    uint8_t m_sector1TimeMinutes; // Sector 1 time in minutes
    uint16_t m_sector2TimeInMS; // Sector 2 time in milliseconds
    uint8_t m_sector2TimeMinutes; // Sector 2 time in minutes
    uint16_t m_sector3TimeInMS; // Sector 3 time in milliseconds
    uint8_t m_sector3TimeMinutes; // Sector 3 time in minutes
    uint8_t m_lapValidBitFlags; // 0x01 bit set-lap valid,      0x02 bit set-sector 1 valid
    // 0x04 bit set-sector 2 valid, 0x08 bit set-sector 3 valid
};

struct TyreStintHistoryData
{
    uint8_t m_endLap; // Lap the tyre usage ends on (255 of current tyre)
    uint8_t m_tyreActualCompound; // Actual tyres used by this driver
    uint8_t m_tyreVisualCompound; // Visual tyres used by this driver
};

class PacketSessionHistoryData : public PHeader
{
public:
    PacketSessionHistoryData();
    virtual ~PacketSessionHistoryData();
    uint8_t m_carIdx(void);
    uint8_t m_numLaps(void);
    uint8_t m_numTyreStints(void);
    uint8_t m_bestLapTimeLapNum(void);
    uint8_t m_bestSector1LapNum(void);
    uint8_t m_bestSector2LapNum(void);
    uint8_t m_bestSector3LapNum(void);
    LapHistoryData m_lapHistoryData(char index);
    TyreStintHistoryData m_tyreStintsHistoryData(char index);
    void push(char *receiveBuffer);

private:
    uint8_t m_carIdx_; // Index of the car this lap data relates to
    uint8_t m_numLaps_; // Num laps in the data (including current partial lap)
    uint8_t m_numTyreStints_; // Number of tyre stints in the data

    uint8_t m_bestLapTimeLapNum_; // Lap the best lap time was achieved on
    uint8_t m_bestSector1LapNum_; // Lap the best Sector 1 time was achieved on
    uint8_t m_bestSector2LapNum_; // Lap the best Sector 2 time was achieved on
    uint8_t m_bestSector3LapNum_; // Lap the best Sector 3 time was achieved on

    LapHistoryData m_lapHistoryData_[100]; // 100 laps of data max
    TyreStintHistoryData m_tyreStintsHistoryData_[8]; // Stint history

};
#pragma pack(pop)

#endif 

