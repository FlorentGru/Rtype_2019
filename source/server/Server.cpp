/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include "Server.hpp"

using boost::asio::ip::udp;

Server::Server(short port) : network(port)
{
}

bool Server::run()
{
    Events events;

    std::vector<SerializedEntity> entities;

    if (!this->network.connect()) {
        return false;
    }

    entities.emplace_back(SerializedEntity(IEntity::PLAYER, 1, 0, 0));

    std::cout << "thread success" << std::endl;
    while (1) {
        this->network.sendEntitiesToPlayer("Player 1", entities);
        events = this->network.getEvents("Player 1");
        if (events.isAKey()) {
            std::cout << "events: " << std::endl;
            std::cout << "    A: " << events.isAKey() << std::endl;
            std::cout << "    Z: " << events.isZKey() << std::endl;
            std::cout << "    E: " << events.isEKey() << std::endl;
            std::cout << "    Q: " << events.isQKey() << std::endl;
            std::cout << "    S: " << events.isSKey() << std::endl;
            std::cout << "    D: " << events.isDKey() << std::endl;
        }
    }

    return true;
}