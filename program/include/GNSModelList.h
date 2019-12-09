#pragma once

#include "GNSModel.h"
#include "GNSModelStack.h"

#include <vector>
// #include <list>

enum ModelType {
    MODEL_TYPE_ERROR = -1,
    MODEL,
    MODEL_STACK
};

// TODO: make the full use of the whole id pool
// mid_table_t keeps the record of mid use.
// it ensures that every model inserted into modellist
// has a unique mid, and keeps track of whether the model
// is a model stack.
class mid_table_t
{
public:
    mid_table_t() { next_mid = GNS_ID32_min; }
    //
    struct midTableEntry
    {
        mid_t mid;
        ModelType type;
    };

    // apply for a new mid
    mid_t newMID(ModelType type = MODEL);

    // return the model's type (a stack or not)
    ModelType getMidType(mid_t mid);

private:
    mid_t next_mid;
    std::vector<midTableEntry> m_table;
};

// A ModelList stores all the models and model stacks 
// in a scenario. 
class GNS_ModelList final
{
public:
    GNS_ModelList();
    ~GNS_ModelList();

    // Get Model by model id
    // return nullptr if the model/stack id is invalid
    GNS_Model *GetModel(mid_t model_id);
    GNS_ModelStack *GetStack(mid_t stack_id);
    GNS_ModelStack *GetNode(mid_t stack_id) { return GetStack(stack_id); }

    // Add new model/modelstack to ModelList
    int AddModel(GNS_Model *new_model);
    int AddModelStack(GNS_ModelStack *new_stack);
    int AddModelToStack(GNS_Model *new_model, mid_t stack_id);

private:
    // mid manager
    mid_table_t midTable;

    struct ModelListEntry
    {
        mid_t model_id = 0;
        mid_t stack_id = 0;
        GNS_Model * model = nullptr;
    };

    struct ModelStackListEntry
    {
        mid_t stack_id = 0;
        GNS_ModelStack * model_stack = nullptr;
    };

    std::vector<ModelListEntry> AllModelList;
    std::vector<ModelStackListEntry> AllStackList;
};

