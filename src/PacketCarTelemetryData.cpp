// File: PacketCarTelemetryData.cpp
#include "PacketCarTelemetryData.h"
#include <inttypes.h>
#include <cstring>

const int CARTELEMETRY_BUFFER_SIZE = 1352;

PacketCarTelemetryData::PacketCarTelemetryData()
: PHeader()
{}

PacketCarTelemetryData::~PacketCarTelemetryData()
{}

void PacketCarTelemetryData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, CARTELEMETRY_BUFFER_SIZE);
}


CarTelemetryData PacketCarTelemetryData::m_carTelemetryData(int index)
{
    if (index >= 0 && index < 22)
        return m_carTelemetryData_[index];
    else return CarTelemetryData{};
}

uint8_t PacketCarTelemetryData::m_mfdPanelIndex(void)
{
    return m_mfdPanelIndex_;
}

uint8_t PacketCarTelemetryData::m_mfdPanelIndexSecondaryPlayer(void)
{
    return m_mfdPanelIndexSecondaryPlayer_;
}

int8_t PacketCarTelemetryData::m_suggestedGear(void)
{
    return m_suggestedGear_;
}