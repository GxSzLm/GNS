#pragma once

#include "PublicDefine.h"

#include <string>
#include <vector>

class GNS_Scenario;

class GNS_Event;

class GNS_Model
{
public:
    GNS_Model() = default;
    GNS_Model(GNS_Scenario *cur_scn);
    ~GNS_Model();

    // Mid: Model id
    mid_t Mid;

    // Events this model could handle
    std::vector<eid_t> Events;
    
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
    void check_mid_overflow();
    void model_init();
};