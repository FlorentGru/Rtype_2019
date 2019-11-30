//
// Created by tfian on 28/11/2019.
//

#include "Client.hpp"

bool Client::run(const std::string &host, const std::string &port)
{
    Events events;

    if (!this->network.connect(host, port)) {
        return false;
    }

    while ("forever") {
        //this->engine.getEvents();
        this->network.sendEvents(events);
        auto entities = this->network.getEntities();
        //this->engine.draw(entities);
    }
    return true;
}