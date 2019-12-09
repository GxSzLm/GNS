#include "GNSEvent.h"

#include <iostream>

eid_t GNS_Event::next_eid = GNS_ID32_min;
eid_t GNS_Event::max_eid = GNS_ID32_max;

GNS_Event::GNS_Event(int src, int dst) : srcNode(src), dstNode(dst) {
    Eid = next_eid;
    set_next_eid();
    EventType = 0;
}

GNS_Event::~GNS_Event() {

}

void GNS_Event::set_next_eid() {
    if (++next_eid <= max_eid) {
        return;
    }
    else {
        std::cout << "EID alloc error." << std::endl;
        return;
    }
}

GNS_Event *GenerateNewEvent(mid_t srcModel, mid_t dstModel, clocktype trig_delay) {
    auto new_event = new GNS_Event(srcModel, dstModel);
    new_event->Name = "Timer";
    new_event->EventType = 2;
    new_event->trigDelay = trig_delay;

    return new_event;
}