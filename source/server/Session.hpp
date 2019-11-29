/*
** EPITECH PROJECT, 2019
** r_type
** File description:
** session.cpp
*/

#ifndef _SESSION_HPP_
#define _SESSION_HPP_

#include <vector>
#include "ISession.hpp"

class Session : public ISession
{
public:
    Session(std::string pseudo);
    std::vector<RawData> getPacketData() override;
    bool addEventPacket(RawData entity) override;
private:
    Protocol::PacketManager packetManager;

    std::string pseudo_;
    std::vector<RawData> packets;
};

#endif