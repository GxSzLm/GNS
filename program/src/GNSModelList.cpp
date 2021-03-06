#include "GNSModelList.h"
#include "GNSModelStack.h"
#include "GNSModel.h"

GNS_ModelList::GNS_ModelList() {
    
}

GNS_ModelList::~GNS_ModelList() {
    // free the models
    for (auto &e : AllModelList) {
        delete e.model;
    }
    for (auto &e : AllStackList) {
        delete e.model_stack;
    }
}

GNS_Model *GNS_ModelList::GetModel(mid_t model_id) {
    if (idGNSId32(model_id)) {
        for (auto &e : AllModelList) {
            if (e.model_id == model_id) {
                return e.model;
            }
        }
        // no such model
        return nullptr;
    } else {
        // illegal model id
        std::cout << "ILLEGAL MODEL ID: " << model_id << std::endl;
        return nullptr;
    }
}

GNS_ModelStack *GNS_ModelList::GetStack(mid_t stack_id) {
    if (idGNSId32(stack_id)) {
        for (auto &e : AllStackList) {
            if (e.stack_id == stack_id) {
                return e.model_stack;
            }
        }
        // no such model stack
        return nullptr;
    } else {
        // illegal model stack id
        std::cout << "ILLEGAL MODEL STACK ID: " << stack_id << std::endl;
        return nullptr;
    }
}

int GNS_ModelList::AddModelStack(GNS_ModelStack *new_stack) {
    if (new_stack == nullptr) {
        return -1;
    }
    // make sure it's a model stack
    // throw a warning message if it seems to be a pure model
    if (!new_stack->isAStack) {
        std::cout << "WARNING: THIS MODEL STACK SEEMS TO BE A PURE MODEL" << std::endl;
    }
    // get mid for stack
    new_stack->Mid = midTable.newMID(MODEL_STACK);
    // insert into model list
    ModelStackListEntry new_entry;
    new_entry.stack_id = new_stack->Mid;
    new_entry.model_stack = new_stack;
    AllStackList.push_back(new_entry);
    return 0;
}

int GNS_ModelList::AddModelToStack(GNS_Model *new_model, mid_t stack_id) {
    if (new_model == nullptr) {
        return -1;
    }
    // make sure it's a model (not a model stack)
    // throw a warning message if it seems to be a stack
    if (new_model->isAStack) {
        std::cout << "WARNING: THIS MODEL SEEMS TO BE A MODEL STACK" << std::endl;
    }
    // get mid for model
    new_model->Mid = midTable.newMID(MODEL);
    // insert into the stack in the stack list
    auto st = GetStack(stack_id);
    if (st == nullptr) {
        std::cout << "INVALID STACK ID." << std::endl;
        return -1;
    }
    st->AddModel(new_model);
    // insert into model list
    ModelListEntry new_entry;
    new_entry.model_id = new_model->Mid;
    new_entry.stack_id = stack_id;
    new_entry.model = new_model;
    
    AllModelList.push_back(new_entry);
    return 0;
}

int GNS_ModelList::AddModel(GNS_Model *new_model) {
    if (new_model == nullptr) {
        return -1;
    }
    // make sure it's a model stack
    // throw a warning message if it seems to be a pure model
    if (new_model->isAStack) {
        std::cout << "WARNING: THIS MODEL SEEMS TO BE A MODEL STACK" << std::endl;
    }
    // get mid for model
    new_model->Mid = midTable.newMID(MODEL);
    // insert into model list
    ModelListEntry new_entry;
    new_entry.model_id = new_model->Mid;
    new_entry.stack_id = 0;
    new_entry.model = new_model;
    
    AllModelList.push_back(new_entry);
    return 0;
}

mid_t mid_table_t::newMID(ModelType type) {
    if (next_mid <= GNS_ID32_max) {
        int mid = next_mid++;
        midTableEntry entry;
        entry.mid = mid;
        entry.type = type;
        m_table.push_back(entry);

        return mid;
    }
    else {
        std::cout << "MODEL ID OVERFLOW" << std::endl;
        exit(-1);
        return -1;
    }
}

ModelType mid_table_t::getMidType(mid_t mid) {
    for (auto &e : m_table) {
        if (e.mid == mid) {
            return e.type;
        }
    }
    return MODEL_TYPE_ERROR;
}