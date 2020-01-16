#include "GNSScenario.h"

#include "PublicDefine.h"

#include "GNSModel.h"
#include "GNSModelStack.h"
#include "GNSModelList.h"
#include "EventQ.h"
#include "GNSEvent.h"

#include "GNSTestRepeater.h"

GNS_Scenario::GNS_Scenario() {
    e_queue = new EventQ(this);
    modelList = new GNS_ModelList();
    CurSimTime = 0;
}

GNS_Scenario::~GNS_Scenario() {

}

int GNS_Scenario::SimInit() {
    nodes_init();
    scn_models_init();2/ 
}

int GNS_Scenario::SimRun() {
    while (e_queue->GetEventNum() > 0) {
        auto event = e_queue->retrieveNextEvent();
        CurSimTime = event->expireTime;

        mid_t exec_model_id = event->dstNode;
        auto exec_model = modelList->GetModel(exec_model_id);
        if (exec_model != nullptr) {
            exec_model->HandleEvent(event);
        }
        delete event;
        event = nullptr;
    }
}

int GNS_Scenario::SimStop() {
    
}

int GNS_Scenario::NewEvent(GNS_Event * event) {
    return e_queue->AddEvent(event);
}

void GNS_Scenario::nodes_init() {
    auto r1 = new TestRepeater(this);
    modelList->AddModel(r1);
    auto r2 = new TestRepeater(this);
    modelList->AddModel(r2);

    auto trig = GenerateNewEvent(r1->mid, r2->mid, 0);
    e_queue->AddEvent(trig);
}

void GNS_Scenario::scn_models_init() {

}