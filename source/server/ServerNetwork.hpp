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
    /**
     * Initialise the connection by calling the abstract network class
     * @param port is the opened port
     */
    ServerNetwork(short port);

    /**
     * Open the server for clients
     * @return true
     * @return false
     */
    bool connect();

    /**
     * Send Entities to the player
     * @param userId is the Id of the client to send Entities
     * @param entities is a list of entities sent from the server to convert into packet for the client
     * @return true
     * @return false
     */
    bool sendEntitiesToPlayer(const std::string &userId, std::vector<SerializedEntity> entities);

    /**
     * Get the events from the client
     * @param userId is the Id of the client
     * @return an events packet where every pressed key are set
     */
    Events getEvents(const std::string &userId);

private:
    std::shared_ptr<IUdpServer> udpServer;

    Protocol::PacketManager packetManager;
};

#endif