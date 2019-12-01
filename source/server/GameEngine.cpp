//
// Created by tfian on 25/11/2019.
//

#include "GameEngine.hpp"
#include "UpdateEntitySystem.hpp"
#include "Enemy.hpp"
#include "CollideSystem.hpp"

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
    std::shared_ptr<Position> position = make_shared<Position>(200, 500);
    std::shared_ptr<Position> posEnemy = make_shared<Position>(2000, 300);


    this->ecs.addSystem(std::make_shared<UpdateEntitySystem>());

    this->ecs.addSystem(std::make_shared<CollideSystem>());

    this->ecs.addEntity(std::make_shared<Player>(3, 1, position));

    this->ecs.addEntity(std::make_shared<Enemy>(1, 2, posEnemy));
}

