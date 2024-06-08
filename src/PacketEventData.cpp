// File: PacketEventData.cpp
#include "PacketEventData.h"
#include <inttypes.h>
#include <cstring>

const int EVENT_BUFFER_SIZE = 45;

PacketEventData::PacketEventData()
: PHeader()
{}

PacketEventData::~PacketEventData()
{}

void PacketEventData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, EVENT_BUFFER_SIZE);
}

uint8_t PacketEventData::m_eventStringCode(int index)
{
    if (index >= 0 && index < 4)
        return m_eventStringCode_[index];
    else return {0};
}

EventDataDetails PacketEventData::m_eventDetails(void)
{
    return m_eventDetails_;
}