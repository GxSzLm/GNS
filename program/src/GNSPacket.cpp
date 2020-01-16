#include "GNSPacket.h"

GNS_Packet::GNS_Packet() {

}

GNS_Packet::~GNS_Packet() {
    
}

GNS_Packet *GNS_Packet::copy() {
    return nullptr;
}

void * const GNS_Packet::peekHeader() {
    if (headerNum <= 0) {
        return nullptr;
    }
    return headerList.back().headerContent;
}

void GNS_Packet::popHeader() {
    if (headerNum > 0) {
        free(headerList.back().headerContent);
        headerList.pop_back();
        --headerNum;
    }
}

void GNS_Packet::newHeader(void *hdr, int hdrsize, 
                           std::string &lname, std::string &pname) {
    packet_header_t newhdr = { lname, pname, hdr, hdrsize };
    headerList.push_back(newhdr);
}

void *GNS_Packet::getPayload() {
    return packetContent;
}