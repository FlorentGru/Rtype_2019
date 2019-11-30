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
    events.setAKey(true);
    std::cout << "connection success" << std::endl;
    for (int i = 0; i < 10; i++) {
        this->network.sendEvents(events);
        auto entities = this->network.getEntities();

        std::cout << "{" << std::endl << "    \"entities\": [" << std::endl;
        for (auto &entity : entities) {
            std::cout << "    {" << std::endl;
            std::cout << "        \"type\": " << entity.getType() << std::endl;
            std::cout << "        \"id\": " << entity.getId() << std::endl;
            std::cout << "        \"x\": " << entity.getX() << std::endl;
            std::cout << "    }," << std::endl;
        }
        std::cout << "    ]" << std::endl << "}" << std::endl;
        //this->engine.run(entities, events);
    }
    return true;
}