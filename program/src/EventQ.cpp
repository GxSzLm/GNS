#include "EventQ.h"

#include "GNSEvent.h"
#include "GNSScenario.h"

EventQ::EventQ(GNS_Scenario * scn) {
    myScn = scn;
}

EventQ::~EventQ() {

}

GNS_Event * EventQ::retrieveNextEvent() {
    if (event_num == 0) {
        return nullptr;
    }
    GNS_Event * ret = e_queue.front();
    e_queue.pop_front();
    --event_num;
    return ret;
}

int EventQ::AddEvent(GNS_Event * new_event) {
    new_event->expireTime = myScn->SimClock() + new_event->trigDelay;
    auto iter = e_queue.begin();
    for (; iter != e_queue.end(); ++iter) {
        if ((*iter)->expireTime >= new_event->expireTime) {
            break;
        }
    }
    --iter;
    e_queue.insert(iter, new_event);
    ++event_num;

    return 0;
}

int EventQ::RemoveEvent() {
    return 0;
}

