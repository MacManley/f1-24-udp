// File: PHeader.h
#ifndef PHEADER_H
#define PHEADER_H

#include <inttypes.h>

#pragma pack(push, 1)

struct PacketHeader
{
    uint16_t m_packetFormat; // 2024
    uint8_t m_gameYear; // 2024
    uint8_t m_gameMajorVersion; // Game major version - "X.00"
    uint8_t m_gameMinorVersion; // Game minor version - "1.XX"
    uint8_t m_packetVersion; // Version of this packet type, all start from 1
    uint8_t m_packetId; // Identifier for the packet type, see below
    uint64_t m_sessionUID; // Unique identifier for the session
    float m_sessionTime; // Session timestamp
    uint32_t m_frameIdentifier; // Identifier for the frame the data was retrieved on
    uint32_t m_overallframeIdentifier; // Identifier for the frame the data was retrieved on
    uint8_t m_playerCarIndex; // Index of player's car in the array
    uint8_t m_secondaryPlayerCarIndex; // Index of secondary player's car in the array (splitscreen)
    // 255 if no second player
};

using namespace std;

class PHeader
{
public:
    PHeader();
    virtual ~PHeader();
    uint16_t m_packetFormat(void); // 2024
    uint8_t m_gameYear(void); // Game year - last two digits e.g. 24
    uint8_t m_gameMajorVersion(void); // Game major version - "X.00"
    uint8_t m_gameMinorVersion(void); // Game minor version - "1.XX"
    uint8_t m_packetVersion(void); // Version of this packet type, all start from 1
    uint8_t m_packetId(void); // Identifier for the packet type, see below
    uint64_t m_sessionUID(void); // Unique identifier for the session
    float m_sessionTime(void); // Session timestamp
    uint32_t m_frameIdentifier(void); // Identifier for the frame the data was retrieved on
    uint32_t m_overallframeIdentifier(void); // Identifier for the frame the data was retrieved on
    uint8_t m_playerCarIndex(void); // Index of player's car in the array
    uint8_t m_secondaryPlayerCarIndex(void); // Index of secondary player's car in the array (splitscreen) (255 if no second player)
    void push(char *receiveBuffer);

protected:
    PacketHeader m_header;
    uint16_t* firstElementPointer();
};

#pragma pack(pop)

#endif

