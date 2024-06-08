// File: PacketTyreSetData.cpp
#include "PacketTyreSetData.h"
#include <inttypes.h>
#include <cstring>

const int TYRESET_BUFFER_SIZE = 231;

PacketTyreSetData::PacketTyreSetData()
: PHeader()
{
}

PacketTyreSetData::~PacketTyreSetData()
{
}

void PacketTyreSetData::push(char *receiveBuffer)
{
    std::memcpy(PHeader::firstElementPointer(), receiveBuffer, TYRESET_BUFFER_SIZE);
}

uint8_t PacketTyreSetData::m_carIdx(void)
{
    return m_carIdx_;
}

TyreSetData PacketTyreSetData::m_tyresetData(int index)
{
    if (index >= 0 && index < 20)
        return m_tyresetData_[index];
    else return TyreSetData{};
}

uint8_t PacketTyreSetData::m_fittedIdx(void)
{
    return m_fittedIdx_;
}