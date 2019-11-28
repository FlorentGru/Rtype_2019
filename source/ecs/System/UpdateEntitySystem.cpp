//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "UpdateEntitySystem.hpp"


bool UpdateEntitySystem::run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events)
{
    for (auto & entity : entities) {
        if (entity->getType() == IEntity::PLAYER)
            manageShip(entity);
        else if (entity->getType() == IEntity::FIRE)
            createFire();
        else
            moveLeft(entity);
    }
    return _isSucceed;
}

void UpdateEntitySystem::createFire()
{

}

void UpdateEntitySystem::moveLeft(std::shared_ptr<IEntity>)
{

}

void UpdateEntitySystem::manageShip(std::shared_ptr<IEntity> player)
{

}