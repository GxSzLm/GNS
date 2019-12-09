#pragma once

using Address = int;
using Index = int;

class GNS_Packet 
{
public:
    struct PacketInfo
    {
        Address srcAddr;
        Address dstAddr;
    };

public:
    GNS_Packet();
    ~GNS_Packet();

    

private:
    // the entire packet to be transmitted in a network
    void * packetContent = nullptr;

    // extra packet information. can be used to simulate 
    // ip layer behavior even there's not one.
    PacketInfo info;

};