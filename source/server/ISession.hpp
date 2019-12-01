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
    /**
     * Get a list of received data packet
     * @return a list of binary packet
     */
    virtual std::vector<RawData> getPacketData() = 0;
    /**
     * Add an Event Packet
     * @param entity is an entity packet sent by the server
     * @return true
     * @return false
     */
    virtual bool addEventPacket(RawData entity) = 0;
};

#endif