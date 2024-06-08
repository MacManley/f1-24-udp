// File: PacketEventData.h
#ifndef PACKETEVENTDATA_H
#define PACKETEVENTDATA_H

#include "PHeader.h"
#include <cstring>
// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
#pragma pack(push, 1)

union EventDataDetails
{

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of car achieving fastest lap
        float lapTime; // Lap time is in seconds
    } FastestLap;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of car retiring
    } Retirement;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of team mate
    } TeamMateInPits;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the race winner
    } RaceWinner;

    struct
    {
        uint8_t penaltyType; // Penalty type 
        uint8_t infringementType; // Infringement type 
        uint8_t vehicleIdx; // Vehicle index of the car the penalty is applied to
        uint8_t otherVehicleIdx; // Vehicle index of the other car involved
        uint8_t time; // Time gained, or time spent doing action in seconds
        uint8_t lapNum; // Lap the penalty occurred on
        uint8_t placesGained; // Number of places gained by this
    } Penalty;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle triggering speed trap
        float speed; // Top speed achieved in kilometres per hour
        uint8_t overallFastestInSession; // Overall fastest speed in session = 1, otherwise 0
        uint8_t driverFastestInSession; // Fastest speed for driver in session = 1, otherwise 0
        uint8_t fastestVehicleIdxInSession;
        float fastestSpeedInSession;
    } SpeedTrap;

    struct
    {
        uint8_t numLights; // Number of lights showing
    } StartLights;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle serving drive through
    } DriveThroughPenaltyServed;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle serving stop go
    } StopGoPenaltyServed;

    struct
    {
        uint32_t flashbackFrameIdentifier; // Frame identifier flashed back to
        float flashbackSessionTime; // Session time flashed back to
    } Flashback;

    struct
    {
        uint32_t m_buttonStatus; // Bit flags specifying which buttons are being pressed
        // currently 
    } Buttons;

    struct
    {
        uint8_t overtakingVehicleIdx; // Vehicle index of the vehicle overtaking
        uint8_t beingOvertakenVehicleIdx; // Vehicle index of the vehicle being overtaken
    } Overtake;

    struct 
    {
        uint8_t safetyCarType;  // 0 = No Safety Car, 1 = Full Safety Car
                                // 2 = Virtual Safety Car, 3 = Formation Lap Safety Car
        uint8_t eventType;      // 0 = Deployed, 1 = Returning, 2 = Returned
                                // 3 = Resume Race
    } SafetyCar;

    struct {

        uint8_t vehicle1Idx; // Vehicle index of the first vehicle involved in the collision
        uint8_t vehicle2Idx; // Vehicle index of the second vehicle involved in the collision

    } Collision;
};

class PacketEventData : public PHeader
{
public:
    PacketEventData();
    virtual ~PacketEventData();
    uint8_t m_eventStringCode(int index);
    EventDataDetails m_eventDetails(void);
    void push(char *receiveBuffer);

private:
    uint8_t m_eventStringCode_[4]; // Event string code
    EventDataDetails m_eventDetails_; // Event details - should be interpreted differently for each type
};
#pragma pack(pop)

#endif 

