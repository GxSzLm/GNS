#pragma once
#include "PublicDefine.h"
#include "GNSId.h"

#include <string>
#include <vector>

using pkid_t = gns_id_t;

class GNS_Packet 
{
public:
    GNS_Packet();
    ~GNS_Packet();

    pkid_t pkid;

    // extra packet information. can be used to simulate 
    // ip layer behavior even when there's not one.
    void * packetInfo = nullptr;

    // copy function. very common in protocol processing
    // use copy constructor maybe?
    GNS_Packet *copy();

    // header list operations
    // the header list is actually a header heap
    // used to get some information
    void * const peekHeader();
    // remove the top header
    void popHeader();
    // push a new header into the heap
    void newHeader(void *hdr, int hdrsize, std::string &lname, std::string &pname);

    // content operation
    void *getPayload();


private:
    // the entire packet to be transmitted in a network
    void * packetContent = nullptr;
    int payloadSize = 0;

    // header management for packets could be useful. 
    // store headers' pointer in an array maybe.
    struct packet_header_t {
        // use strings for now
        std::string layerName;
        std::string protocolName;
        // header
        void *headerContent;
        int size;
    };
    
    // notice: headers must be organized in order.
    std::vector<packet_header_t> headerList;
    int headerNum = 0;
};