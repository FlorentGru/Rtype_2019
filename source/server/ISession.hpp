/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** ISession.cpp
*/

#ifndef _ISESSION_HPP_
#define _ISESSION_HPP_

#include "Packet.hpp"

class ISession
{
public:
    ISession() {};
    virtual char *getPacketData() = 0;
    virtual void taskManager(std::string) = 0;
protected:
    Protocol::Packet packet_;
};

#endif