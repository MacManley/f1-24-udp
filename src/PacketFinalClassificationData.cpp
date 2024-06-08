// File: PacketFinalClassificationData.cpp
#include "PacketFinalClassificationData.h"
#include <inttypes.h>
#include <cstring>

const int FINALCLASSIFICATION_BUFFER_SIZE = 1020;

PacketFinalClassificationData::PacketFinalClassificationData()
: PHeader()
{}

PacketFinalClassificationData::~PacketFinalClassificationData()
{}

void PacketFinalClassificationData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, FINALCLASSIFICATION_BUFFER_SIZE);
}

uint8_t PacketFinalClassificationData::m_numCars(void)
{
    return m_numCars_;
}

FinalClassificationData PacketFinalClassificationData::m_classificationData(int index)
{
    if (index >= 0 && index < 22)
        return m_classificationData_[index];
    else return FinalClassificationData{};
}