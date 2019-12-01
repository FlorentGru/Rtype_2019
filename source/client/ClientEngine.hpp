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

/**
 *  Class ClientEngine the engine on the side of the client, for took the entity and set the scene
 */

class ClientEngine
{
public:
    ClientEngine() = default;
    /**
    * The run function who remove all the entities but mostly add them after deserialized
    * 
    * @Param entities: Took all the entities to serialized them
    *        events: just here cause the function is in the interface and need to get it
    * 
    * @return a bool to return if the function work well and return true at the end or false if ecs equals false
    */
    bool run(vector<SerializedEntity> entities, Events &events);
    /**
    * Funtion run call all the function to move and update the player or the fire
    * 
    * @Param entities: Took the entity serialized to know which one is it
    * 
    * @return the shared_ptr<IEntity> to get the good one entity like Plyaer or Fire
    */
    shared_ptr<IEntity> deserializedEntity(SerializedEntity entities);

    /**
    * the cuntion setScene is for know which scene the system need to draw
    * 
    * @Param scene_: just to know in the enum what scene is called
    * 
    * @return check if the function go to the end for return true
    */
    bool setScene(Client_engine::Scene scene);
private:
    ClientEcs ecs;
    Client_engine::Scene scene;
};

#endif //RTYPE_CLIENTENGINE_HPP
