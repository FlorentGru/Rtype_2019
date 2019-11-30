//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTENGINE_HPP
#define RTYPE_CLIENTENGINE_HPP

#include "ClientEcs.hpp"
#include "DrawEntitySystem.hpp"

namespace Client {
    enum Scene {
        MENU,
        GAME
    };
}

class ClientEngine
{
public:
    ClientEngine();
    const Events &getEvents();
    bool draw(vector<shared_ptr<IRenderEntity>> entities);

    bool setScene(Client::Scene scene);
private:
    DrawEntitySystem des;
    ClientEcs ecs;
    Client::Scene scene;
};


#endif //RTYPE_CLIENTENGINE_HPP
