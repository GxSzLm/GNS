#pragma once

#include "GNSId.h"
#include "PublicDefine.h"

#include <string>

typedef enum eventType {
    GNS_UNKNOWN, 
    GNS_TIMER_NEW,
    GNS_TIMER_EXPIRE,
    GNS_PACKET_SEND,
    GNS_PACKET_RECV, 
    GNS_TEST,
    GNS_BUILD_TEST,
} event_t;

class GNS_Event
{
public:
    GNS_Event(mid_t src, mid_t dst);
    ~GNS_Event();

    eid_t eid;

    clocktype trigDelay;
    clocktype expireTime;
    bool isExpired = false;

    std::string Name;
    event_t EventType;

    mid_t srcNode;
    mid_t dstNode;

private:

};

GNS_Event *GenerateNewEvent(mid_t srcModel, mid_t dstModel, clocktype trig_delay);