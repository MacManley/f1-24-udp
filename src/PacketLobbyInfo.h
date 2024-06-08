// File: PacketLobbyInfo.h
#ifndef PACKETLOBBYINFO_H
#define PACKETLOBBYINFO_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct LobbyInfoData
{
    uint8_t m_aiControlled; // Whether the vehicle is AI (1) or Human (0) controlled
    uint8_t m_teamId; // Team id - see appendix (255 if no team currently selected)
    uint8_t m_nationality; // Nationality of the driver
    uint8_t m_platform; // 1 = Steam, 3 = PlayStation, 4 = Xbox, 6 = Origin, 255 = unknown
    char m_name[48]; // Name of participant in UTF-8 format – null terminated
    // Will be truncated with ... (U+2026) if too long
    uint8_t m_carNumber; // Car number of the player
    uint8_t m_yourTelemetry; // The player's UDP setting, 0 = restricted, 1 = public
    uint8_t m_showOnlineNames; // The player's show online names setting, 0 = off, 1 = on
    uint16_t m_techLevel; // F1 World tech level
    uint8_t m_readyStatus; // 0 = not ready, 1 = ready, 2 = spectating
};


class PacketLobbyInfo : public PHeader
{
public:
    PacketLobbyInfo();
    virtual ~PacketLobbyInfo();
    uint8_t m_numofCars(void); // Number of cars in the final classification
    LobbyInfoData m_lobbyPlayers(int index);
    void push(char *receiveBuffer);

private:
    uint8_t m_numofCars_; // Number of cars in the final classification
    LobbyInfoData m_lobbyPlayers_[22];
};
#pragma pack(pop)

#endif 