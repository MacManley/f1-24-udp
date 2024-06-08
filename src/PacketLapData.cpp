// File: PacketLapData.cpp
#include "PacketLapData.h"
#include <inttypes.h>
#include <cstring>

const int LAPDATA_BUFFER_SIZE = 1285;

PacketLapData::PacketLapData()
: PHeader()
{}

PacketLapData::~PacketLapData()
{}

void PacketLapData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, LAPDATA_BUFFER_SIZE);
}

uint8_t PacketLapData::m_timeTrialPBCarIdx(void)
{
    return m_timeTrialPBCarIdx_;
}

uint8_t PacketLapData::m_timeTrialRivalCarIdx(void)
{
    return m_timeTrialRivalCarIdx_;
}

LapData PacketLapData::m_lapData(int index)
{
    if (index >= 0 && index < 22)
        return m_lapData_[index];
    else return LapData{};
}
