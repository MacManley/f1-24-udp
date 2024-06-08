// File: PHeader.cpp
#include "PHeader.h"
#include <inttypes.h>
#include <cstdio>
#include <cstring>

const int HEADER_BUFFER_SIZE = 29;

using namespace std;

PHeader::PHeader()
{
    
}

PHeader::~PHeader()
{
}

void PHeader::push(char *receiveBuffer)
{
    std::memcpy(&m_header, receiveBuffer, HEADER_BUFFER_SIZE);

}

uint16_t PHeader::m_packetFormat(void)
{
    return m_header.m_packetFormat;
}

uint8_t PHeader::m_gameYear(void)
{
    return m_header.m_gameYear;
}

uint8_t PHeader::m_gameMajorVersion(void)
{
    return m_header.m_gameMajorVersion;
}

uint8_t PHeader::m_gameMinorVersion(void)
{
    return m_header.m_gameMinorVersion;
}

uint8_t PHeader::m_packetVersion(void)
{
    return m_header.m_packetVersion;
}

uint8_t PHeader::m_packetId(void)
{
    return m_header.m_packetId;
}

uint64_t PHeader::m_sessionUID(void)
{
    return m_header.m_sessionUID;
}

float PHeader::m_sessionTime(void)
{
    return m_header.m_sessionTime;
}

uint32_t PHeader::m_frameIdentifier(void)
{
    return m_header.m_frameIdentifier;
}

uint32_t PHeader::m_overallframeIdentifier(void)
{
    return m_header.m_overallframeIdentifier;
}

uint8_t PHeader::m_playerCarIndex(void)
{
    return m_header.m_playerCarIndex;
}

uint8_t PHeader::m_secondaryPlayerCarIndex(void)
{
    return m_header.m_secondaryPlayerCarIndex;
}

uint16_t* PHeader::firstElementPointer(void)
{
    return &m_header.m_packetFormat;
}
