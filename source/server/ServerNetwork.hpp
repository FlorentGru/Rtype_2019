/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** server/server.hpp
*/

#ifndef _NETWORKSERVER_HPP_
#define _NETWORKSERVER_HPP_

#include "BoostUdpServer.hpp"
#include "SerializedEntity.hpp"
#include "Events.hpp"

using boost::asio::ip::udp;

class ServerNetwork
{
public:
    ServerNetwork(short port);
    bool connect();

    bool sendEntitiesToPlayer(const std::string &userId, std::vector<SerializedEntity> entities);
    Events getEvents(const std::string &userId);

private:
    std::shared_ptr<IUdpServer> udpServer;

    Protocol::PacketManager packetManager;
};

#endif