#pragma once
#include "PublicDefine.h"

#include <vector>

class GNS_IdAllocator 
{
public:
    struct id_pool {
        std::string name;
        gns_id_t next_id;
    };

    GNS_IdAllocator() {
        id_pool midpool = { "mid", GNS_ID32_min };
        id_pool eidpool = { "eid", GNS_ID32_min };
        id_pool pkidpool = { "pkid", GNS_ID32_min };
        idPools.push_back(midpool);
        idPools.push_back(eidpool);
        idPools.push_back(pkidpool);
    }

    gns_id_t getNextId(std::string poolname) {
        for (auto &c : idPools) {
            if (c.name == poolname) {
                return c.next_id++;
            }
            // assert here maybe
            std::cout << "ERROR: Wrong id pool name" << std::endl;
        }
    };

private:
    std::vector<id_pool> idPools;
};