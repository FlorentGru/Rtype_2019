/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** ISession.cpp
*/

#ifndef _ICLIENTDATA_HPP_
#define _ICLIENTDATA_HPP_

#include "Packet.hpp"

class IClientData
{
public:
    IClientData() {};
    virtual char *getPacketData() = 0;
    virtual void createRequest(std::string) = 0;
    virtual void manageReceivedData(std::string request, size_t size) = 0;
    virtual bool inDisconnection() = 0;
protected:
    Protocol::Packet packet_;
    bool disconnection;
};

#endif