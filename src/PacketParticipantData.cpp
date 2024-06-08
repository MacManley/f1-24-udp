// File: PacketParticipantData.cpp
#include "PacketParticipantData.h"
#include <inttypes.h>
#include <cstring>

const int PARTICIPANT_BUFFER_SIZE = 1350;

PacketParticipantData::PacketParticipantData()
: PHeader()
{}

PacketParticipantData::~PacketParticipantData()
{}

void PacketParticipantData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, PARTICIPANT_BUFFER_SIZE);
}

uint8_t PacketParticipantData::m_numActiveCars(void)
{
    return m_numActiveCars_;
}

ParticipantData PacketParticipantData::m_participants(int index)
{
    if (index >= 0 && index < 22)
        return m_participants_[index];
    else return ParticipantData{};
}