#pragma once

#include <iostream>

using mid_t = int;
using eid_t = int;
using clocktype = long long;

const int GNS_ID32_max = 0x7fffffff;
const int GNS_ID32_min = 0x0;
inline int idGNSId32(int id) {
    return id >= GNS_ID32_min && id <= GNS_ID32_max;
}

const int TRACE_SYSTEM_CORE = 1;