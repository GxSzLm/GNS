#pragma once

#include "GNSId.h"

#include <string>
#include <vector>

class GNS_Scenario;
class GNS_Event;

using mid_t = gns_id_t;

class GNS_Model
{
public:
    GNS_Model(GNS_Scenario *cur_scn);
    ~GNS_Model();

    // Mid: Model id
    mid_t mid;

    // Event type this model could handle
    std::vector<int> EventType;
    
    // model name string
    std::string Name;

    // stack flag
    bool isAStack;
    
    // pointer to a parameter struct
    void * Params;

    // pointer to the scenario the model belongs to
    GNS_Scenario *MyScn;

    // process the expired event
    virtual void HandleEvent(GNS_Event * event);

private:
    void model_init();
};