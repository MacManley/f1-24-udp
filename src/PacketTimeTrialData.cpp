// File: PacketTimeTrialData.cpp
#include "PacketTimeTrialData.h"
#include <cstring>

const int TIMETRIAL_BUFFER_SIZE = 101;

PacketTimeTrialData::PacketTimeTrialData()
: PHeader()
{}

PacketTimeTrialData::~PacketTimeTrialData()
{}

void PacketTimeTrialData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, TIMETRIAL_BUFFER_SIZE);
}

TimeTrialDataSet PacketTimeTrialData::m_playerSessionBestDataSet(void)
{
        return m_playerSessionBestDataSet_;
}

TimeTrialDataSet PacketTimeTrialData::m_personalBestDataSet(void)
{
        return m_personalBestDataSet_;
}

TimeTrialDataSet PacketTimeTrialData::m_rivalDataSet(void)
{
        return m_rivalDataSet_;
}