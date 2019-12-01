//
// Created by tfian on 21/11/2019.
//

#ifndef RTYPE_IUDPCLIENT_HPP
#define RTYPE_IUDPCLIENT_HPP

#include <string>
#include <vector>
#include "RawData.hpp"

/**
 * Interface to perform UDP network operations as client with the server
*/
class IUdpClient
{
public:
    /**
     * Connects to the server, performs handshake
     *
     * @param address IPv4 address of the server in plain text
     * @param port port of the server in plain text
     *
     * @return returns true for success
     */
    virtual bool doConnect(const std::string &address, const std::string &port) = 0;

    /**
     * Start thread to receive the server packets asynchronously
     */
    virtual void startListening() = 0;

    /**
     * Sends a packet asynchronously to the server
     *
     * @param data raw data for the packet
     * @param size size of the packet in bytes
     *
     * @return returns true for success
     */
    virtual bool sendData(const char *data, size_t size) = 0;

    /**
     * Sends a packet then waits for the server answer and treat the packet
     *
     * Used to sends commands
     *
     * @param data raw data for the packet
     * @param size size of the packet in bytes
     *
     * @return returns true for success
     */
    virtual bool sendAndReceiveNext(const char *data, size_t size) = 0;

    /**
     * Receive the packets sent by the server
     *
     * @return List of packets packet in raw data with size
     */
    virtual std::vector<RawData> receiveAll() = 0;

    /**
     * Sends a packet asynchronously to the server
     *
     * @param data raw data for the packet
     * @param size size of the packet in bytes
     *
     * @return packet in raw data with size
     */
    virtual RawData receiveNext() = 0;

    /**
     * Disconnect client from the server, sends disconnect command
     *
     * @return returns true for success
     */
    virtual bool disconnect() = 0;
};

#endif //RTYPE_IUDPCLIENT_HPP