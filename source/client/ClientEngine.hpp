//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTENGINE_HPP
#define RTYPE_CLIENTENGINE_HPP

#include "ClientEcs.hpp"
#include "DrawEntitySystem.hpp"
#include "SerializedEntity.hpp"
#include "Events.hpp"
#include "RenderPlayer.hpp"
#include "Position.hpp"
#include "RenderFire.hpp"
#include <iostream>

namespace Client_engine {
    enum Scene {
        MENU,
        GAME
    };
}

class ClientEngine
{
public:
    ClientEngine() = default;
    bool run(vector<SerializedEntity> entities, Events &events);
    shared_ptr<IEntity> deserializedEntity(SerializedEntity entities);

    bool setScene(Client_engine::Scene scene);
private:
    ClientEcs ecs;
    Client_engine::Scene scene;
};

#endif //RTYPE_CLIENTENGINE_HPP
