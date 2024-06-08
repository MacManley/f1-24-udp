// File: F1_24_UDP.cpp
#include <stdio.h>

#include "F1_24_UDP.h"
#include <WiFiUdp.h>
#include "PacketMotionData.h"
#include "PacketSessionData.h"
#include "PacketLapData.h"
#include "PacketEventData.h"
#include "PacketParticipantData.h"
#include "PacketCarSetupData.h"
#include "PacketCarTelemetryData.h"
#include "PacketCarStatusData.h"
#include "PacketFinalClassificationData.h"
#include "PacketLobbyInfo.h"
#include "PacketCarDamageData.h"
#include "PacketSessionHistoryData.h"
#include "PacketMotionEX.h"
#include "PacketTyreSetData.h"
#include "PacketTimeTrialData.h"

constexpr unsigned int localPort = 20777;

WiFiUDP Udp;

F1_24_Parser::F1_24_Parser()
{
    packetMotionData_ = new PacketMotionData();
    packetSessionData_ = new PacketSessionData();
    packetLapData_ = new PacketLapData();
    packetEventData_ = new PacketEventData();
    packetParticipantData_ = new PacketParticipantData();
    packetCarSetupData_ = new PacketCarSetupData();
    packetCarTelemetryData_ = new PacketCarTelemetryData();
    packetCarStatusData_ = new PacketCarStatusData();
    packetFinalClassificationData_ = new PacketFinalClassificationData();
    packetLobbyData_ = new PacketLobbyInfo();
    packetCarDamageData_ = new PacketCarDamageData();
    packetSessionHistoryData_ = new PacketSessionHistoryData();
    packetTyreSetData_ = new PacketTyreSetData();
    packetMotionEXData_ = new PacketMotionEXData();
    packetTimeTrialData_ = new PacketTimeTrialData();
}

F1_24_Parser::~F1_24_Parser()
{
    delete packetMotionData_;
    delete packetSessionData_;
    delete packetLapData_;
    delete packetEventData_;
    delete packetParticipantData_;
    delete packetCarSetupData_;
    delete packetCarTelemetryData_;
    delete packetCarStatusData_;
    delete packetFinalClassificationData_;
    delete packetLobbyData_;
    delete packetCarDamageData_;
    delete packetSessionHistoryData_;
    delete packetTyreSetData_;
    delete packetMotionEXData_;
    delete packetTimeTrialData_;
}

void F1_24_Parser::begin(void) {
    Udp.begin(localPort);
}

void F1_24_Parser::read(void) {
    int packetSize = Udp.parsePacket(); 
    if (packetSize) {
        char packetBuffer[packetSize];
        while(Udp.available())
       {
        Udp.read(packetBuffer, packetSize);
       }
       push(packetBuffer);
    }
}

void F1_24_Parser::push(char * rcvBuffer)
{
    PHeader* P = new PHeader();
    P->push(rcvBuffer);
    switch (P->m_packetId())
    {
        case 0: packetMotionData_->push(rcvBuffer);
            break;
        case 1: packetSessionData_->push(rcvBuffer);
            break;
        case 2: packetLapData_->push(rcvBuffer);
            break;
        case 3: packetEventData_->push(rcvBuffer);
            break;
        case 4: packetParticipantData_->push(rcvBuffer);
            break;
        case 5: packetCarSetupData_->push(rcvBuffer);
            break;
        case 6: packetCarTelemetryData_->push(rcvBuffer);
            break;
        case 7: packetCarStatusData_->push(rcvBuffer);
            break;
        case 8: packetFinalClassificationData_->push(rcvBuffer);
            break;
        case 9: packetLobbyData_->push(rcvBuffer);
            break;
        case 10: packetCarDamageData_->push(rcvBuffer);
            break;
        case 11: packetSessionHistoryData_->push(rcvBuffer);
            break;
        case 12: packetTyreSetData_->push(rcvBuffer);
            break;
        case 13: packetMotionEXData_->push(rcvBuffer);
            break;
        case 14: packetTimeTrialData_->push(rcvBuffer);
            break;
        default:;
    }
    delete P;
}

PacketMotionData* F1_24_Parser::packetMotionData(void)
{
    return packetMotionData_;
}

PacketSessionData* F1_24_Parser::packetSessionData(void)
{
    return packetSessionData_;
}

PacketLapData* F1_24_Parser::packetLapData(void)
{
    return packetLapData_;
}

PacketEventData* F1_24_Parser::packetEventData(void)
{
    return packetEventData_;
}

PacketParticipantData* F1_24_Parser::packetParticipantData(void)
{
    return packetParticipantData_;
}

PacketCarSetupData* F1_24_Parser::packetCarSetupData(void)
{
    return packetCarSetupData_;
}

PacketCarTelemetryData* F1_24_Parser::packetCarTelemetryData(void)
{
    return packetCarTelemetryData_;
}

PacketCarStatusData* F1_24_Parser::packetCarStatusData(void)
{
    return packetCarStatusData_;
}

PacketFinalClassificationData* F1_24_Parser::packetFinalClassificationData(void)
{
    return packetFinalClassificationData_;
}

PacketLobbyInfo* F1_24_Parser::packetLobbyData(void)
{
    return packetLobbyData_;
}

PacketCarDamageData* F1_24_Parser::packetCarDamageData(void)
{
    return packetCarDamageData_;
}

PacketSessionHistoryData* F1_24_Parser::packetSessionHistoryData(void)
{
    return packetSessionHistoryData_;
}

PacketTyreSetData* F1_24_Parser::packetTyreSetData(void)
{
    return packetTyreSetData_;
}

PacketMotionEXData* F1_24_Parser::packetMotionEXData(void)
{
    return packetMotionEXData_;
}

PacketTimeTrialData* F1_24_Parser::packetTimeTrialData(void)
{
    return packetTimeTrialData_;
}