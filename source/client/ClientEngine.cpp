//
// Created by tfian on 26/11/2019.
//

#include "ClientEngine.hpp"

bool ClientEngine::run(vector<SerializedEntity> entities, Events &events)
{
    this->ecs.removeAllEntities();
    for (auto &entity : entities) {
        this->ecs.addEntity(deserializedEntity(entity));
    }
    if (this->ecs.run(events) == false)
        return false;
    return (true);
}

shared_ptr<IEntity> ClientEngine::deserializedEntity(SerializedEntity entities)
{
    Position pos(entities.getX(), entities.getY(), entities.getZ());
    shared_ptr<Position> position = std::make_shared<Position>(pos);

    if (entities.getType() == IEntity::PLAYER) {
        return std::make_shared<RenderPlayer>(RenderPlayer(3, entities.getId(), position));

    }
    if (entities.getType() == IEntity::ENEMY) {
        return std::make_shared<RenderEnemy>(RenderEnemy(entities.getId(), position));
    }
    return std::make_shared<RenderFire>(RenderFire(entities.getId(), position));
}

bool ClientEngine::setScene(Client_engine::Scene scene_)
{

    this->scene = scene_;
    if (scene_ == Client_engine::GAME) {
        this->ecs.addSystem(std::make_shared<DrawEntitySystem>());
    }

    return true;
}
