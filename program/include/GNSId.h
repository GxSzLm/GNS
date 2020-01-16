#pragma once

#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;

// type of id in GNS
enum GNS_id_type{
    EVENT = 0,
    MODEL, 
    PACKET
};

// use 32-bit, unsigned number
using gns_id_t = unsigned int;
using eid_t = gns_id_t;
using mid_t = gns_id_t;
using pkid_t = gns_id_t;
const int GNS_ID32_max = 0xffffffff;
const int GNS_ID32_min = 0x1;
const int GNS_ID32_init = 0x0;
inline bool isGNSId(int id) {
    return id >= GNS_ID32_min && id <= GNS_ID32_max;
}

class GNS_IdAllocator
{
public:
    GNS_IdAllocator() {
        next_id = getNewId();
    }

    template <typename _id_t>
    _id_t getNewId(GNS_id_type type) {
        if (idGNSId32(next_id + 1)) {
            return next_id;
        }
        cout << "ID ALLOC ERROR. OVERFLOW." << endl;
        return (_id_t)-1;  // questionable
    };

private:
    eid_t next_eid;
    mid_t next_mid;
    pkid_t next_pkid;

    std::list<eid_t> eid_list;
    std::list<mid_t> mid_list;
    std::list<pkid_t> pkid_list;
};