//
// Created by fabien on 29/11/2019.
//

#ifndef RTYPE_IUDPSERVER_HPP
#define RTYPE_IUDPSERVER_HPP

#include <string>
#include <vector>
#include "RawData.hpp"

/**
 * Interface to perform UDP network operations as server with clients
*/
class IUdpServer
{
public:

    /**
     * Start the server, now listening for incoming connections
     */
    virtual void openServer() = 0;

    /**
     * Sends a packet
     *
     * @param data raw data for the packet
     * @param size size of the packet in bytes
     *
     * @return returns true for success
     */
    virtual bool send(const char *data, size_t size) = 0;

    /**
     * Sends a packet to a client asynchronously
     *
     * @param data raw data for the packet
     * @param size size of the packet in bytes
     * @param userId Id of the client
     *
     */
    virtual void sendAsync(const char *data, size_t size, std::string userId) = 0;

    /**
     * Receive the packets from particular user
     *
     * @param userAddress Id of the client
     *
     * @return List of packets in raw data with size
     */
    virtual std::vector<RawData> receiveUserPackets(std::string userAddress) = 0;
};

#endif //RTYPE_IUDPSERVER_HPP
