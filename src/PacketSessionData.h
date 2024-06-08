// File: PacketSessionData.h
#ifndef PACKETSESSIONDATA_H
#define PACKETSESSIONDATA_H

#include "PHeader.h"
#include <inttypes.h>

#pragma pack(push, 1)

struct MarshalZone
{
    float m_zoneStart; // Fraction (0..1) of way through the lap the marshal zone starts
    int8_t m_zoneFlag; // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
};

struct WeatherForecastSample
{
    uint8_t m_sessionType; // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
    // 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
    // 12 = Time Trial
    uint8_t m_timeOffset; // Time in minutes the forecast is for
    uint8_t m_weather; // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature; // Track temp. in degrees Celsius
    int8_t m_trackTemperatureChange; // Track temp. change – 0 = up, 1 = down, 2 = no change
    int8_t m_airTemperature; // Air temp. in degrees celsius
    int8_t m_airTemperatureChange; // Air temp. change – 0 = up, 1 = down, 2 = no change
    uint8_t m_rainPercentage; // Rain percentage (0-100)
};

class PacketSessionData : public PHeader
{
public:
    PacketSessionData();
    virtual ~PacketSessionData();
    uint8_t m_weather(void); // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature(void); // Track temp. in degrees celsius
    int8_t m_airTemperature(void); // Air temp. in degrees celsius
    uint8_t m_totalLaps(void); // Total number of laps in this race
    uint16_t m_trackLength(void); // Track length in metres
    uint8_t m_sessionType(void); // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
    // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
    // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
    int8_t m_trackId(void); // -1 for unknown, 0-21 for tracks, see appendix
    uint8_t m_formula(void); // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
                            // 3 = F1 Generic, 4 = Beta, 6 = Esports
                            // 8 = F1 World, 9 = F1 Elimination 
    uint16_t m_sessionTimeLeft(void); // Time left in session in seconds
    uint16_t m_sessionDuration(void); // Session duration in seconds
    uint8_t m_pitSpeedLimit(void); // Pit speed limit in kilometres per hour
    uint8_t m_gamePaused(void); // Whether the game is paused
    uint8_t m_isSpectating(void); // Whether the player is spectating
    uint8_t m_spectatorCarIndex(void); // Index of the car being spectated
    uint8_t m_sliProNativeSupport(void); // SLI Pro support, 0 = inactive, 1 = active
    uint8_t m_numMarshalZones(void); // Number of marshal zones to follow
    MarshalZone m_marshalZones(int index); // List of marshal zones – max 21
    uint8_t m_safetyCarStatus(void); // 0 = no safety car, 1 = full
    // 2 = virtual, 3 = formation lap
    uint8_t m_networkGame(void); // 0 = offline, 1 = online
    uint8_t m_numWeatherForecastSamples(void); // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples(int index); // Array of weather forecast samples
    uint8_t m_forecastAccuracy(void); // 0 = Perfect, 1 = Approximate
    uint8_t m_aiDifficulty(void); // AI Difficulty rating – 0-110
    uint32_t m_seasonLinkIdentifier(void); // Identifier for season - persists across saves
    uint32_t m_weekendLinkIdentifier(void); // Identifier for weekend - persists across saves
    uint32_t m_sessionLinkIdentifier(void); // Identifier for session - persists across saves
    uint8_t m_pitStopWindowIdealLap(void); // Ideal lap to pit on for current strategy (player)
    uint8_t m_pitStopWindowLatestLap(void); // Latest lap to pit on for current strategy (player)
    uint8_t m_pitStopRejoinPosition(void); // Predicted position to rejoin at (player)
    uint8_t m_steeringAssist(void); // 0 = off, 1 = on
    uint8_t m_brakingAssist(void); // 0 = off, 1 = low, 2 = medium, 3 = high
    uint8_t m_gearboxAssist(void); // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8_t m_pitAssist(void); // 0 = off, 1 = on
    uint8_t m_pitReleaseAssist(void); // 0 = off, 1 = on
    uint8_t m_ERSAssist(void); // 0 = off, 1 = on
    uint8_t m_DRSAssist(void); // 0 = off, 1 = on
    uint8_t m_dynamicRacingLine(void); // 0 = off, 1 = corners only, 2 = full
    uint8_t m_dynamicRacingLineType(void); // 0 = 2D, 1 = 3D
    uint8_t m_gameMode(void);                  // Game mode id - see appendix
    uint8_t m_ruleSet(void);                   // Ruleset - see appendix
    uint32_t m_timeOfDay(void);                 // Local time of day - minutes since midnight
    uint8_t m_sessionLength(void);
    uint8_t m_speedUnitsLeadPlayer(void); // 0 = MPH, 1 = KPH
    uint8_t m_temperatureUnitsLeadPlayer(void); // 0 = Celsius, 1 = Fahrenheit
    uint8_t m_speedUnitsSecondaryPlayer(void); // 0 = MPH, 1 = KPH
    uint8_t m_temperatureUnitsSecondaryPlayer(void); // 0 = Celsius, 1 = Fahrenheit
    uint8_t m_numSafetyCarPeriods(void); // Number of safety cars called during session
    uint8_t m_numVirtualSafetyCarPeriods(void); // Number of virtual safety cars called
    uint8_t m_numRedFlagPeriods(void); // Number of red flags called during session
    uint8_t m_equalCarPerformance(void); // 0 = Off, 1 = On
    uint8_t m_recoveryMode(void); // 0 = None, 1 = Flashbacks, 2 = Auto-recovery
    uint8_t m_flashbackLimit(void); // 0 = Low, 1 = Medium, 2 = High, 3 = Unlimited
    uint8_t m_surfaceType(void); // 0 = Simplified, 1 = Realistic
    uint8_t m_lowFuelMode(void); // 0 = Easy, 1 = Hard
    uint8_t m_raceStarts(void); // 0 = Manual, 1 = Assisted
    uint8_t m_tyreTemperature(void); // 0 = Surface only, 1 = Surface & Carcass
    uint8_t m_pitLaneTyreSim(void); // 0 = On, 1 = Off
    uint8_t m_carDamage(void); // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Simulation
    uint8_t m_carDamageRate(void); // 0 = Reduced, 1 = Standard, 2 = Simulation
    uint8_t m_collisions(void); // 0 = Off, 1 = Player-to-Player Off, 2 = On
    uint8_t m_collisionsOffForFirstLapOnly(void); // 0 = Disabled, 1 = Enabled
    uint8_t m_mpUnsafePitRelease(void); // 0 = On, 1 = Off (Multiplayer)
    uint8_t m_mpOffForGriefing(void); // 0 = Disabled, 1 = Enabled (Multiplayer)
    uint8_t m_cornerCuttingStringency(void); // 0 = Regular, 1 = Strict
    uint8_t m_parcFermeRules(void); // 0 = Off, 1 = On
    uint8_t m_pitStopExperience(void); // 0 = Automatic, 1 = Broadcast, 2 = Immersive
    uint8_t m_safetyCar(void); // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Increased
    uint8_t m_safetyCarExperience(void); // 0 = Broadcast, 1 = Immersive
    uint8_t m_formationLap(void); // 0 = Off, 1 = On
    uint8_t m_formationLapExperience(void); // 0 = Broadcast, 1 = Immersive
    uint8_t m_redFlags(void); // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Increased
    uint8_t m_affectsLicenceLevelSolo(void); // 0 = Off, 1 = On
    uint8_t m_affectsLicenceLevelMP(void); // 0 = Off, 1 = On
    uint8_t m_numSessionsInWeekend(void); // Number of session in following array
    uint8_t m_weekendStructure(int index); // List of session types to show weekend
// structure - see appendix for types
    float m_sector2LapDistanceStart(void); // Distance in m around track where sector 2 starts
    float m_sector3LapDistanceStart(void); // Distance in m around track where sector 3 starts
    void push(char *receiveBuffer);

private:
    uint8_t m_weather_; // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature_; // Track temp. in degrees celsius
    int8_t m_airTemperature_; // Air temp. in degrees celsius
    uint8_t m_totalLaps_; // Total number of laps in this race
    uint16_t m_trackLength_; // Track length in metres
    uint8_t m_sessionType_; // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
    // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
    // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
    int8_t m_trackId_; // -1 for unknown, 0-21 for tracks, see appendix
    uint8_t m_formula_; // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
    // 3 = F1 Generic
    uint16_t m_sessionTimeLeft_; // Time left in session in seconds
    uint16_t m_sessionDuration_; // Session duration in seconds
    uint8_t m_pitSpeedLimit_; // Pit speed limit in kilometres per hour
    uint8_t m_gamePaused_; // Whether the game is paused
    uint8_t m_isSpectating_; // Whether the player is spectating
    uint8_t m_spectatorCarIndex_; // Index of the car being spectated
    uint8_t m_sliProNativeSupport_; // SLI Pro support, 0 = inactive, 1 = active
    uint8_t m_numMarshalZones_; // Number of marshal zones to follow
    MarshalZone m_marshalZones_[21]; // List of marshal zones – max 21
    uint8_t m_safetyCarStatus_; // 0 = no safety car, 1 = full
    // 2 = virtual, 3 = formation lap
    uint8_t m_networkGame_; // 0 = offline, 1 = online
    uint8_t m_numWeatherForecastSamples_; // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples_[64]; // Array of weather forecast samples
    uint8_t m_forecastAccuracy_; // 0 = Perfect, 1 = Approximate
    uint8_t m_aiDifficulty_; // AI Difficulty rating – 0-110
    uint32_t m_seasonLinkIdentifier_; // Identifier for season - persists across saves
    uint32_t m_weekendLinkIdentifier_; // Identifier for weekend - persists across saves
    uint32_t m_sessionLinkIdentifier_; // Identifier for session - persists across saves
    uint8_t m_pitStopWindowIdealLap_; // Ideal lap to pit on for current strategy (player)
    uint8_t m_pitStopWindowLatestLap_; // Latest lap to pit on for current strategy (player)
    uint8_t m_pitStopRejoinPosition_; // Predicted position to rejoin at (player)
    uint8_t m_steeringAssist_; // 0 = off, 1 = on
    uint8_t m_brakingAssist_; // 0 = off, 1 = low, 2 = medium, 3 = high
    uint8_t m_gearboxAssist_; // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8_t m_pitAssist_; // 0 = off, 1 = on
    uint8_t m_pitReleaseAssist_; // 0 = off, 1 = on
    uint8_t m_ERSAssist_; // 0 = off, 1 = on
    uint8_t m_DRSAssist_; // 0 = off, 1 = on
    uint8_t m_dynamicRacingLine_; // 0 = off, 1 = corners only, 2 = full
    uint8_t m_dynamicRacingLineType_; // 0 = 2D, 1 = 3D
    uint8_t m_gameMode_;        // Game mode id - see appendix
    uint8_t m_ruleSet_;         // Ruleset - see appendix
    uint32_t m_timeOfDay_;      // Local time of day - minutes since midnight
    uint8_t m_sessionLength_; // 0 = None, 2 = Very Short, 3 = Short, 4 = Medium
    // 5 = Medium Long, 6 = Long, 7 = Full
    uint8_t m_speedUnitsLeadPlayer_; // 0 = MPH, 1 = KPH
    uint8_t m_temperatureUnitsLeadPlayer_; // 0 = Celsius, 1 = Fahrenheit
    uint8_t m_speedUnitsSecondaryPlayer_; // 0 = MPH, 1 = KPH
    uint8_t m_temperatureUnitsSecondaryPlayer_; // 0 = Celsius, 1 = Fahrenheit
    uint8_t m_numSafetyCarPeriods_; // Number of safety cars called during session
    uint8_t m_numVirtualSafetyCarPeriods_; // Number of virtual safety cars called
    uint8_t m_numRedFlagPeriods_; // Number of red flags called during session
    uint8_t m_equalCarPerformance_; // 0 = Off, 1 = On
    uint8_t m_recoveryMode_; // 0 = None, 1 = Flashbacks, 2 = Auto-recovery
    uint8_t m_flashbackLimit_; // 0 = Low, 1 = Medium, 2 = High, 3 = Unlimited
    uint8_t m_surfaceType_; // 0 = Simplified, 1 = Realistic
    uint8_t m_lowFuelMode_; // 0 = Easy, 1 = Hard
    uint8_t m_raceStarts_; // 0 = Manual, 1 = Assisted
    uint8_t m_tyreTemperature_; // 0 = Surface only, 1 = Surface & Carcass
    uint8_t m_pitLaneTyreSim_; // 0 = On, 1 = Off
    uint8_t m_carDamage_; // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Simulation
    uint8_t m_carDamageRate_; // 0 = Reduced, 1 = Standard, 2 = Simulation
    uint8_t m_collisions_; // 0 = Off, 1 = Player-to-Player Off, 2 = On
    uint8_t m_collisionsOffForFirstLapOnly_; // 0 = Disabled, 1 = Enabled
    uint8_t m_mpUnsafePitRelease_; // 0 = On, 1 = Off (Multiplayer)
    uint8_t m_mpOffForGriefing_; // 0 = Disabled, 1 = Enabled (Multiplayer)
    uint8_t m_cornerCuttingStringency_; // 0 = Regular, 1 = Strict
    uint8_t m_parcFermeRules_; // 0 = Off, 1 = On
    uint8_t m_pitStopExperience_; // 0 = Automatic, 1 = Broadcast, 2 = Immersive
    uint8_t m_safetyCar_; // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Increased
    uint8_t m_safetyCarExperience_; // 0 = Broadcast, 1 = Immersive
    uint8_t m_formationLap_; // 0 = Off, 1 = On
    uint8_t m_formationLapExperience_; // 0 = Broadcast, 1 = Immersive
    uint8_t m_redFlags_; // 0 = Off, 1 = Reduced, 2 = Standard, 3 = Increased
    uint8_t m_affectsLicenceLevelSolo_; // 0 = Off, 1 = On
    uint8_t m_affectsLicenceLevelMP_; // 0 = Off, 1 = On
    uint8_t m_numSessionsInWeekend_; // Number of session in following array
    uint8_t m_weekendStructure_[12]; // List of session types to show weekend
// structure - see appendix for types
    float m_sector2LapDistanceStart_; // Distance in m around track where sector 2 starts
    float m_sector3LapDistanceStart_; // Distance in m around track where sector 3 starts
};
#pragma pack(pop)

#endif 

