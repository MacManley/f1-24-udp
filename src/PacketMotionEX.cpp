// File: PacketMotionEX.cpp
#include "PacketMotionEX.h"
#include <cstring>

const int MOTIONEX_BUFFER_SIZE = 237;

PacketMotionEXData::PacketMotionEXData()
: PHeader()
{}

PacketMotionEXData::~PacketMotionEXData()
{}

void PacketMotionEXData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, MOTIONEX_BUFFER_SIZE);
}

MotionEXData PacketMotionEXData::m_carMotionEXData()
{
        return m_carMotionEXData_;

}