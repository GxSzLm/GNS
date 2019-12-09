#pragma once
#include "PublicDefine.h"

#include <vector>

class GNS_ModelList;
class EventQ; 
class GNS_Event;

class GNS_Scenario
{
public:
    GNS_Scenario();
    ~GNS_Scenario();

    int SimInit();
    int SimRun();
    int SimStop();

    int NewEvent(GNS_Event * event);

    clocktype SimClock() { return CurSimTime; }

private:
    EventQ *e_queue;
    GNS_ModelList *modelList;

    void nodes_init();
    void scn_models_init();

    clocktype CurSimTime;
};