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

    while (true) {
        events = this->network.getEvents("Player 1");
        entities = this->engine.run(events);
        this->network.sendEntitiesToPlayer("Player 1", entities);
    }

    return true;
}