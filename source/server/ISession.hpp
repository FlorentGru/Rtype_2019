/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** ISession.cpp
*/

#ifndef _ISESSION_HPP_
#define _ISESSION_HPP_

#include "PacketManager.hpp"

class ISession
{
public:
    ISession() {};
    virtual std::vector<RawData> getPacketData() = 0;
    virtual bool addEventPacket(RawData entity) = 0;
};

#endif