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
    std::cout << "Model " << Mid << ": Event received." << std::endl;
}

void GNS_Model::check_mid_overflow() {
    // if (next_mid > max_mid) {
    //     std::cout << "MID about to overflow" << std::endl;
    // }
    // else if (next_mid > max_mid + 1) {
    //     std::cout << "MID overflow" << std::endl;
    //     exit(-1);
    //     // throw an exception maybe
    // }
}

void GNS_Model::model_init() {
    Mid = -1;
    Params = nullptr;
    Name = "UNAMED_MODEL";
    isAStack  = false;
}

