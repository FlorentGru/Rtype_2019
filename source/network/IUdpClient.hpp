//
// Created by tfian on 21/11/2019.
//

#ifndef RTYPE_IUDPCLIENT_HPP
#define RTYPE_IUDPCLIENT_HPP

#include <string>
#include <vector>
#include "RawData.hpp"

class IUdpClient
{
public:
    virtual bool doConnect(const std::string &address, const std::string &port) = 0;

    virtual bool sendData(const char *data, size_t size) = 0;

    virtual std::vector<RawData> receiveAll() = 0;

    virtual RawData receiveNext() = 0;

    virtual bool disconnect() = 0;
};

#endif //RTYPE_IUDPCLIENT_HPP