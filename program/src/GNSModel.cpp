#include "GNSModel.h"
#include "GNSScenario.h"
#include "GNSEvent.h"

#include <iostream>

GNS_Model::GNS_Model(GNS_Scenario *cur_scn) {
    MyScn = cur_scn;
    model_init();
}

GNS_Model::~GNS_Model() {

}

void GNS_Model::HandleEvent(GNS_Event * event) {
    std::cout << "Model " << mid << ": Event received." << std::endl;
}

void GNS_Model::model_init() {
    mid = -1;
    Params = nullptr;
    Name = "UNAMED_MODEL";
    isAStack  = false;
}

