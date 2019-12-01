//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_GAMEENGINE_HPP
#define RTYPE_GAMEENGINE_HPP

#include "../ecs/ServerEcs.hpp"

using namespace std;

class GameEngine
{
public:
    GameEngine();

    vector<SerializedEntity> run(Events &events);
private:
    ServerEcs ecs;
    bool setScene();
};


#endif //RTYPE_GAMEENGINE_HPP
