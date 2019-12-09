#pragma once

#include "PublicDefine.h"

#include <string>

using NodeId = int;
using ModelId = int;

class GNS_Event
{
public:
    GNS_Event(mid_t src, mid_t dst);
    ~GNS_Event();

    eid_t Eid;

    clocktype trigDelay;
    clocktype expireTime;
    bool isExpired = false;

    std::string Name;
    int EventType;

    mid_t srcNode;
    mid_t dstNode;

private:
    static eid_t next_eid;
    static eid_t max_eid;

    void set_next_eid();
};

GNS_Event *GenerateNewEvent(mid_t srcModel, mid_t dstModel, clocktype trig_delay);