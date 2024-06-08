// File: PacketLapData.h
#ifndef PACKETLAPDATA_H
#define PACKETLAPDATA_H

#include "PHeader.h"

#pragma pack(push, 1)

struct LapData
{
    uint32_t m_lastLapTimeInMS; // Last lap time in milliseconds
    uint32_t m_currentLapTimeInMS; // Current time around the lap in milliseconds
    uint16_t m_sector1TimeInMSPart; // Sector 1 time in milliseconds part
    uint8_t m_sector1TimeMinutesPart; // Sector 1 time whole minutes part
    uint16_t m_sector2TimeInMSPart; // Sector 2 time in milliseconds part
    uint8_t m_sector2TimeMinutesPart; // Sector 2 time whole minutes part
    uint16_t m_deltaToCarInFrontInMSPart; // Delta to car ahead in milliseconds part
    uint8_t m_deltaToCarInFrontInMinutesPart; // Time delta to car in front whole minute part
    uint16_t m_deltaToRaceLeaderInMSPart; // Delta to race leader in milliseconds part
    uint8_t m_deltaToRaceLeaderInMinutesPart; // Time delta to race leader whole minute part
    float m_lapDistance; // Distance vehicle is around current lap in metres – could
    // be negative if line hasn’t been crossed yet
    float m_totalDistance; // Total distance travelled in session in metres – could
    // be negative if line hasn’t been crossed yet
    float m_safetyCarDelta; // Delta in seconds for safety car
    uint8_t m_carPosition; // Car race position
    uint8_t m_currentLapNum; // Current lap number
    uint8_t m_pitStatus; // 0 = none, 1 = pitting, 2 = in pit area
    uint8_t m_numPitStops; // Number of pit stops taken in this race
    uint8_t m_sector; // 0 = sector1, 1 = sector2, 2 = sector3
    uint8_t m_currentLapInvalid; // Current lap invalid - 0 = valid, 1 = invalid
    uint8_t m_penalties; // Accumulated time penalties in seconds to be added
    uint8_t m_totalWarnings; // Accumulated number of warnings issued
    uint8_t m_cornerCuttingWarnings;
    uint8_t m_numUnservedDriveThroughPens; // Num drive through pens left to serve
    uint8_t m_numUnservedStopGoPens; // Num stop go pens left to serve
    uint8_t m_gridPosition; // Grid position the vehicle started the race in
    uint8_t m_driverStatus; // Status of driver - 0 = in garage, 1 = flying lap
    // 2 = in lap, 3 = out lap, 4 = on track
    uint8_t m_resultStatus; // Result status - 0 = invalid, 1 = inactive, 2 = active
    // 3 = finished, 4 = didnotfinish, 5 = disqualified
    // 6 = not classified, 7 = retired
    uint8_t m_pitLaneTimerActive; // Pit lane timing, 0 = inactive, 1 = active
    uint16_t m_pitLaneTimeInLaneInMS; // If active, the current time spent in the pit lane in ms
    uint16_t m_pitStopTimerInMS; // Time of the actual pit stop in ms
    uint8_t m_pitStopShouldServePen; // Whether the car should serve a penalty at this stop
    float m_speedTrapFastestSpeed; // Fastest speed through speed trap for this car in kmph
    uint8_t m_speedTrapFastestLap; // Lap no the fastest speed was achieved, 255 = not set
};

class PacketLapData : public PHeader
{
public:
    PacketLapData();
    virtual ~PacketLapData();
    LapData m_lapData(int index);
    uint8_t m_timeTrialPBCarIdx(void);
    uint8_t m_timeTrialRivalCarIdx(void);
    void push(char *receiveBuffer);


private:
    LapData m_lapData_[22]; // Lap data for all cars on track
    uint8_t m_timeTrialPBCarIdx_; // Index of Personal Best car in time trial (255 if invalid)
    uint8_t m_timeTrialRivalCarIdx_; // Index of Rival car in time trial (255 if invalid)
};
#pragma pack(pop)

#endif

