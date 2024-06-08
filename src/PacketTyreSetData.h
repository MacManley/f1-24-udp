// File: PacketTyreSetData.h
#ifndef PACKETTYRESETDATA_H
#define PACKETTYRESETDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct TyreSetData {
    uint8_t m_actualTyreCompound; // Actual tyre compound used
    uint8_t m_VisualTyreCompound; // Visual tyre compound used
    uint8_t m_wear; // Tyre wear (percentage)
    uint8_t m_available; // Whether this set is currently available
    uint8_t m_recommendedSession; // Recommended session for tyre set
    uint8_t m_lifeSpan; // Laps left in this tyre set
    uint8_t m_useableLife; // Max number of laps recommended for this compound
    int16_t m_lapDeltaTime; // Lap delta time in milliseconds compared to fitted set
    uint8_t m_fitted; // Whether the set is fitted or not
};

class PacketTyreSetData : public PHeader
{
public:
    PacketTyreSetData();
    virtual ~PacketTyreSetData();
    uint8_t m_carIdx(void);
    TyreSetData m_tyresetData(int index);
    uint8_t m_fittedIdx(void);
    void push(char *receiveBuffer);

private:
    uint8_t m_carIdx_; // Index of the car this lap data relates to
    TyreSetData m_tyresetData_[20]; // 13 (dry) + 7 (wet)
    uint8_t m_fittedIdx_; // Index into array of fitted tyre

};
#pragma pack(pop)

#endif