#include "GNSModelStack.h"
#include "GNSModel.h"
#include "GNSScenario.h"

GNS_ModelStack::GNS_ModelStack(GNS_Scenario *cur_scn) : GNS_Model(cur_scn) {
    modelstack_init();
}

GNS_ModelStack::~GNS_ModelStack() {

}

void GNS_ModelStack::AddModel(GNS_Model * new_model) {
    if (new_model != nullptr) {
        ModelList.push_back(new_model);
    }
}

void GNS_ModelStack::modelstack_init() {
    isAStack = true;
}