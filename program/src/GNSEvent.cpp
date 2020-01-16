#include "GNSEvent.h"

#include <iostream>

GNS_Event::GNS_Event(mid_t src, mid_t dst) : srcNode(src), dstNode(dst) {
    eid = GNS_ID32_init;
    EventType = GNS_UNKNOWN;
}

GNS_Event::~GNS_Event() {

}

GNS_Event *GenerateNewEvent(mid_t srcModel, mid_t dstModel, clocktype trig_delay) {
    auto new_event = new GNS_Event(srcModel, dstModel);
    new_event->Name = "Timer";
    new_event->EventType = GNS_TIMER_NEW;
    new_event->trigDelay = trig_delay;

    return new_event;
}