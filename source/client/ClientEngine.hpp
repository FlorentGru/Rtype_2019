//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTENGINE_HPP
#define RTYPE_CLIENTENGINE_HPP

#include "ClientEcs.hpp"

namespace Client {
    enum Scene {
        MENU,
        GAME
    };
}

class ClientEngine
{
public:
    const Events &getEvents();
    bool draw(vector<shared_ptr<IRenderEntity>> entities);

    bool setScene(Client::Scene scene);
private:
    ClientEcs ecs;
    Client::Scene scene;
};


#endif //RTYPE_CLIENTENGINE_HPP
