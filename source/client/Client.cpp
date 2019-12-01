//
// Created by tfian on 28/11/2019.
//

#include "Client.hpp"

bool Client::run(const std::string &host, const std::string &port)
{
    Events events;
    std::vector<SerializedEntity> entities;

    if (!this->network.connect(host, port)) {
        return false;
    }
    std::cout << "connection success" << std::endl;

    this->engine.setScene(Client_engine::GAME);

    while (true) {
        if (!events.thirtyOneConditions()) {
            this->network.sendEvents(events);
        }
        events.resetEvent();

        entities = this->network.getEntities();

        if (!this->engine.run(entities, events)) {
            break;
        }
    }
    return true;
}