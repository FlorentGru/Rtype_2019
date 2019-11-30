/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include <iostream>
#include <PacketManager.hpp>
#include "ServerNetwork.hpp"

using boost::asio::ip::udp;

ServerNetwork::ServerNetwork(short port)
{
    udpServer = std::make_shared<BoostUdpServer>(port);
}

bool ServerNetwork::connect(){
    this->udpServer->openServer();
    return true;
}

bool ServerNetwork::sendEntitiesToPlayer(const std::string &userId, std::vector<SerializedEntity> entities)
{
    std::vector<RawData> data = this->packetManager.entity(entities);

    for (auto &packet : data) {
        this->udpServer->sendAsync(packet.data, packet.size, userId);
    }
    return true;
}

Events ServerNetwork::getEvents(const std::string &userId)
{
    Events event;
    std::vector<RawData> data = this->udpServer->receiveUserPackets(userId);
    Protocol::PacketManager::EventsPacket packet;

    if (data.empty()) {
       // std::cout << "no events received" << std::endl;
        return (event);
    }

    if (!this->packetManager.isValidEvents(data.back().data, data.back().size))
        return(event);

    this->packetManager.setEvents(data.back().data, data.back().size);
    packet = this->packetManager.getEventPacket();

    event.setEnter(packet.data.enter);
    event.setZKey(packet.data.zKey);
    event.setAKey(packet.data.aKey);
    event.setEKey(packet.data.eKey);
    event.setQKey(packet.data.qKey);
    event.setSKey(packet.data.sKey);
    event.setDKey(packet.data.dKey);
    event.setUpArrow(packet.data.upArrow);
    event.setDownArrow(packet.data.downArrow);
    event.setRightArrow(packet.data.rightArrow);
    event.setLeftArrow(packet.data.leftArrow);
    return(event);
}