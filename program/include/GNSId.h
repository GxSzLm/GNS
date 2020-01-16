#pragma once

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;

// use 32-bit, unsigned number
using gns_id_t = unsigned int;
using eid_t = gns_id_t;
using mid_t = gns_id_t;
using pkid_t = gns_id_t;
const gns_id_t GNS_ID32_max = 0xffffffff;
const gns_id_t GNS_ID32_min = 0x1;
const gns_id_t GNS_ID32_init = 0x0;
inline bool isGNSId(gns_id_t id) {
    return id >= GNS_ID32_min && id <= GNS_ID32_max;
}