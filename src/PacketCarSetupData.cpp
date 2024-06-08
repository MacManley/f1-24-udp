// File: PacketCarSetupData.cpp
#include "PacketCarSetupData.h"
#include <cstring>

const int CARSETUP_BUFFER_SIZE = 1133;

PacketCarSetupData::PacketCarSetupData()
: PHeader()
{
}

PacketCarSetupData::~PacketCarSetupData()
{
}

void PacketCarSetupData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, CARSETUP_BUFFER_SIZE);
}

CarSetupData PacketCarSetupData::m_carSetups(int index)
{
    if (index >= 0 && index < 22)
        return m_carSetups_[index];
    else return CarSetupData{};
}

float PacketCarSetupData::m_nextFrontWingValue(void) {
    return m_nextFrontWingValue_;
}
