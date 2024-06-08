// File: PacketLobbyInfo.cpp
#include "PacketLobbyInfo.h"
#include <inttypes.h>
#include <cstring>

const int LOBBYINFO_BUFFER_SIZE = 1306;

PacketLobbyInfo::PacketLobbyInfo()
: PHeader()
{}

PacketLobbyInfo::~PacketLobbyInfo()
{}

void PacketLobbyInfo::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, LOBBYINFO_BUFFER_SIZE);
}

uint8_t PacketLobbyInfo::m_numofCars(void)
{
    return m_numofCars_;
}

LobbyInfoData PacketLobbyInfo::m_lobbyPlayers(int index)
{
    if (index >= 0 && index < 22)
        return m_lobbyPlayers_[index];
    else return LobbyInfoData{};
}