#pragma once

#include "GNSModel.h"

class GNS_Scenario;

class GNS_ModelStack : public GNS_Model
{
public:
    GNS_ModelStack(GNS_Scenario *cur_scn);
    ~GNS_ModelStack();

    std::vector<GNS_Model *> ModelList;
    
    void AddModel(GNS_Model * new_model);

private:
    void modelstack_init();
};