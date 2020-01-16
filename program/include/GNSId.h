#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using gns_id_t = int;
using eid_t = gns_id_t;
using mid_t = gns_id_t;
using pkid_t = gns_id_t;
const int GNS_ID32_max = 0x7fffffff;
const int GNS_ID32_min = 0x0;
const int GNS_ID32_init = 0xffffffff;
inline bool idGNSId32(int id) {
    return id >= GNS_ID32_min && id <= GNS_ID32_max;
}

template <typename _id_t>
class GNS_IdAllocator
{
public:
    GNS_IdAllocator() {
        next_id = GNS_ID32_min;
    }

    _id_t getNewId() {
        if (idGNSId32(next_id + 1)) {
            return next_id;
        }
        cout << "ID ALLOC ERROR. OVERFLOW." << endl;
        return (_id_t)-1;  // questionable
    };

private:
    _id_t next_id;
};