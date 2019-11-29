/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include <iostream>
#include "ServerNetwork.hpp"

using boost::asio::ip::udp;

ServerNetwork::ServerNetwork(short port)
{
    udpServer = std::make_shared<BoostUdpServer>(port);
}

bool ServerNetwork::connect(){
    if (!this->udpServer->openServer()) {
        return false;
    }

    return true;
}

bool ServerNetwork::sendEntities(const std::string &userId)
{
    return true;
}

void ServerNetwork::getEvents(const std::string &userId)
{
    std::vector<RawData> packets = this->udpServer->receiveUserPackets(userId);
}