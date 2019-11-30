//
// Created by fabien on 29/11/2019.
//

#ifndef RTYPE_IUDPSERVER_HPP
#define RTYPE_IUDPSERVER_HPP

#include <string>
#include <vector>
#include "RawData.hpp"

class IUdpServer
{
public:
    virtual void openServer() = 0;

    virtual bool send(const char *data, size_t size) = 0;

    virtual void sendAsync(const char *data, size_t size, std::string) = 0;

    virtual std::vector<RawData> receiveUserPackets(std::string userAddress) = 0;
};

#endif //RTYPE_IUDPSERVER_HPP
