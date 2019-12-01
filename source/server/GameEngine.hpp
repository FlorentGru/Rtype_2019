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
    /**
     * Create Entities and Systems used by ECS
     */
    GameEngine();
    /**
     * Run the game
     * @param events is a packet with information about what key has been pressed by the player
     * @return several packets of actualised Entity to the client
     */
    vector<SerializedEntity> run(Events &events);
private:
    ServerEcs ecs;
    bool setScene();
};


#endif //RTYPE_GAMEENGINE_HPP
