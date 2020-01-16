#pragma once

#include "GNSId.h"

#include <list>

class GNS_Event;
class GNS_Scenario;

class eid_table_t
{
public:
    eid_table_t() { 
        next_eid = GNS_ID32_min; 
    }
    //
    struct eidTableEntry
    {
        eid_t eid;
    };

    // apply for a new eid
    eid_t NewEid() {
        eid_t new_eid = next_eid++;
        if (!isGNSId(next_eid)) {
            cout << "error: id overflow." << endl;
            exit(0);
        }

        return new_eid;
    }

    // return the model's type (a stack or not)
    // ModelType getMidType(mid_t mid);

private:
    eid_t next_eid;
    std::vector<eidTableEntry> e_table;
};

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
    eid_table_t eidTable;
};