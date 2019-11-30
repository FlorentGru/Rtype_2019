//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#include "CollideSystem.hpp"

bool CollideSystem::run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events)
{
    std::vector<std::shared_ptr<IMovingEntity>> save;
    save.clear();
    for (auto &entity : entities) {
        collide(std::dynamic_pointer_cast<IMovingEntity>(entity), entities);
        save.push_back(std::dynamic_pointer_cast<IMovingEntity>(entity));
    }
    destroyEntity(save);
    return true;
}

void CollideSystem::collide(std::shared_ptr<IMovingEntity> collide, std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (auto &entity : entities) {
        if (entity->getPosition()->getX() < collide->getPosition()->getX()
        || entity->getPosition()->getX() > collide->getPosition()->getX() + collide->getHitbox()->getLength())
            return;
        if (entity->getPosition()->getY() < collide->getPosition()->getY()
        || entity->getPosition()->getY() > collide->getPosition()->getY() + collide->getHitbox()->getHeigh())
            return;
        if (entity->getId() == collide->getId())
            return;
        collide->setPv(collide->getPv() - 1);
    }
}

void CollideSystem::destroyEntity(std::vector<std::shared_ptr<IMovingEntity>> &entities)
{
    for (size_t i = 0; i < entities.size(); ++i) {
        if (entities[i]->getPv() <= 0)
            entities.erase(entities.begin() + i);
    }
}