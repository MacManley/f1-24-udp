// File: PacketSessionHistoryData.cpp
#include "PacketSessionHistoryData.h"
#include <inttypes.h>
#include <cstring>

const int SESSIONHISTORY_BUFFER_SIZE = 1460;

PacketSessionHistoryData::PacketSessionHistoryData()
: PHeader()
{}

PacketSessionHistoryData::~PacketSessionHistoryData()
{}

void PacketSessionHistoryData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, SESSIONHISTORY_BUFFER_SIZE);
}

uint8_t PacketSessionHistoryData::m_carIdx(void)
{
    return m_carIdx_;
}

uint8_t PacketSessionHistoryData::m_numLaps(void)
{
    return m_numLaps_;
}

uint8_t PacketSessionHistoryData::m_numTyreStints(void)
{
    return m_numTyreStints_;
}

uint8_t PacketSessionHistoryData::m_bestLapTimeLapNum(void)
{
    return m_bestLapTimeLapNum_;
}

uint8_t PacketSessionHistoryData::m_bestSector1LapNum(void)
{
    return m_bestSector1LapNum_;
}

uint8_t PacketSessionHistoryData::m_bestSector2LapNum(void)
{
    return m_bestSector2LapNum_;
}

uint8_t PacketSessionHistoryData::m_bestSector3LapNum(void)
{
    return m_bestSector3LapNum_;
}

LapHistoryData PacketSessionHistoryData::m_lapHistoryData(char index)
{
    if (index >= 0 && index < 100)
        return m_lapHistoryData_[index];
    else return LapHistoryData{};
}

TyreStintHistoryData PacketSessionHistoryData::m_tyreStintsHistoryData(char index)
{
    if (index >= 0 && index < 8)
        return m_tyreStintsHistoryData_[index];
    else return TyreStintHistoryData{};
}