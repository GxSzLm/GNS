#pragma once

#include <list>

class GNS_Event;
class GNS_Scenario;

class EventQ final
{
public:
    EventQ(GNS_Scenario * scn);
    ~EventQ();

    // scenario
    GNS_Scenario * myScn;

    // return the event number in the event queue
    int GetEventNum() { return event_num; }

    // retrieve next event in the event queue
    GNS_Event * retrieveNextEvent();

    // Insert new event to the event queue
    int AddEvent(GNS_Event * new_event);

    // TODO: add remove function
    int RemoveEvent();
    
private:
    int q_size;
    int event_num;

    std::list<GNS_Event *> e_queue;
};