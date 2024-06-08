// File: PacketCarStatusData.cpp
#include "PacketCarStatusData.h"
#include <cstring>

const int CARSTATUS_BUFFER_SIZE = 1239;

PacketCarStatusData::PacketCarStatusData()
: PHeader()
{
}

PacketCarStatusData::~PacketCarStatusData()
{
}

void PacketCarStatusData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, CARSTATUS_BUFFER_SIZE);
}

CarStatusData PacketCarStatusData::m_carStatusData(int index)
{
    if (index >= 0 && index < 22)
        return m_carStatusData_[index];
    else return CarStatusData{};
}

