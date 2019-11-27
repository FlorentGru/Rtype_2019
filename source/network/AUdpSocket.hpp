//
// Created by tfian on 21/11/2019.
//

#ifndef RTYPE_AUDPSOCKET_HPP
#define RTYPE_AUDPSOCKET_HPP

#include <string>
#include <vector>

struct RawData {
    RawData(const char *, size_t size);

    size_t size;
    char data[512];
};

class AbstractSocket
{
public:
    virtual bool doConnect(const std::string &address, int port) = 0;

    virtual bool sendData(const char *data, size_t size) = 0;

    virtual const std::vector<RawData> &receiveAll() = 0;

    virtual const RawData receiveNext() = 0;

    virtual bool disconnect() = 0;
};

#endif //RTYPE_AUDPSOCKET_HPP