//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#include "CollideSystem.hpp"
#include "Fire.hpp"
#include <iostream>

bool CollideSystem::run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events)
{
    events.setBKey(false);
    for (size_t i = 0; i < entities.size(); ++i)
        collide(entities, i);
    destroyEntity(entities);
    return true;
}

void CollideSystem::collide(std::vector<std::shared_ptr<IEntity>> &entities, size_t ite)
{
    for (size_t i = ite + 1; i < entities.size(); i++) {
        if (isInRect(std::dynamic_pointer_cast<IMovingEntity>(entities[ite]), std::dynamic_pointer_cast<IMovingEntity>(entities[i]))) {
            if ((entities[ite]->getType() == IEntity::FIRE) && (std::dynamic_pointer_cast<Fire>(entities[ite])->getPlayerId() == entities[i]->getId())) {
                return;
            } else {
                std::dynamic_pointer_cast<IMovingEntity>(entities[ite])->setPv(
                std::dynamic_pointer_cast<IMovingEntity>(entities[ite])->getPv() - 1);
                std::dynamic_pointer_cast<IMovingEntity>(entities[i])->setPv(
                std::dynamic_pointer_cast<IMovingEntity>(entities[i])->getPv() - 1);
            }
            return;
        }
        if (isInRect(std::dynamic_pointer_cast<IMovingEntity>(entities[i]), std::dynamic_pointer_cast<IMovingEntity>(entities[ite]))) {
            if ((entities[i]->getType() == IEntity::FIRE) && (std::dynamic_pointer_cast<Fire>(entities[i])->getPlayerId() == entities[ite]->getId())) {
                return;
            } else {
                std::dynamic_pointer_cast<IMovingEntity>(entities[ite])->setPv(
                std::dynamic_pointer_cast<IMovingEntity>(entities[ite])->getPv() - 1);
                std::dynamic_pointer_cast<IMovingEntity>(entities[i])->setPv(
                std::dynamic_pointer_cast<IMovingEntity>(entities[i])->getPv() - 1);
            }
        }
    }
}

void CollideSystem::destroyEntity(std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (size_t i = 0; i < entities.size(); ++i) {
        if (std::dynamic_pointer_cast<IMovingEntity>(entities[i])->getPv() <= 0)
            entities.erase(entities.begin() + i);
    }
}

bool CollideSystem::isInRect(std::shared_ptr<IMovingEntity> first, std::shared_ptr<IMovingEntity> snd)
{

    float x1 = first->getPosition()->getX();
    float y1 = first->getPosition()->getY();
    float length1 = first->getHitbox()->getLength();
    float heigh1 = first->getHitbox()->getHeigh();

    float x2 = snd->getPosition()->getX();
    float y2 = snd->getPosition()->getY();
    float length2 = snd->getHitbox()->getLength();
    float heigh2 = snd->getHitbox()->getHeigh();


    if ((x2 <= x1 && x1 <= x2 + length2) && (y2 <= y1 && y1 <= y2 + heigh2))
        return true;
    if ((x2 <= x1 + length1 && x1 + length1 <= x2 + length2) && (y2 <= y1 && y1 <= y2 + heigh2))
        return true;
    if ((x2 <= x1 && x1 <= x2 + length2) && (y2 <= y1 + heigh1 && y1 + heigh1 <= y2 + heigh2))
        return true;
    return  (x2 <= x1 + length1 && x1 + length1 <= x2 + length2) && (y2 <= y1 +heigh1 && y1 + heigh1 <= y2 + heigh2);
}
