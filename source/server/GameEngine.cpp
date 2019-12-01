//
// Created by tfian on 25/11/2019.
//

#include "GameEngine.hpp"
#include "UpdateEntitySystem.hpp"

vector<SerializedEntity> GameEngine::run(Events &events)
{
    vector<SerializedEntity> res;

    res.clear();
    if (!ecs.run(events))
        return res;
    return this->ecs.getEntities();
}

GameEngine::GameEngine()
{
    std::shared_ptr<Position> position = make_shared<Position>(500, 200);

    this->ecs.addSystem(std::make_shared<UpdateEntitySystem>());

    this->ecs.addEntity(std::make_shared<Player>(3, 1, position));
}

