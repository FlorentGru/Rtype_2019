//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "UpdateEntitySystem.hpp"
#include "Events.hpp"


UpdateEntitySystem::UpdateEntitySystem()
{
    _timer.create_clock("fire");
    _windowLength = 1280;
    _windowHeight = 920;
}

bool UpdateEntitySystem::run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events)
{
    std::vector<std::shared_ptr<IMovingEntity>> moving;
    moving.clear();
    for (auto & entity : entities)
        moving.push_back(std::dynamic_pointer_cast<IMovingEntity>(entity));
    for (auto & mover : moving) {
        if (mover->getType() == IEntity::PLAYER) {
            std::shared_ptr<Player> player = std::dynamic_pointer_cast<Player>(mover);
            manageShip(player, events);
            if (events.isEnter() && _timer.restart("fire", 1)) {
                std::shared_ptr<Fire> fire = createFire(player, true, entities);
                entities.push_back(fire);
            }
        }
        else if (mover->getType() == IEntity::FIRE)
            if (std::dynamic_pointer_cast<Fire>(mover)->isPlayer())
                move(mover, UpdateEntitySystem::RIGHT);
            else
                move(mover, UpdateEntitySystem::LEFT);
        else
            move(mover, UpdateEntitySystem::LEFT);
    }
    destroyEntity(entities);
    return _isSucceed;
}

std::shared_ptr<Fire> UpdateEntitySystem::createFire(std::shared_ptr<Player> &player, bool isPlayer, std::vector<std::shared_ptr<IEntity>> &entities)
{
    Position firePosition(player->getPosition()->getX(), player->getPosition()->getY());
    firePosition.setX(firePosition.getX() + 100);
    firePosition.setY(firePosition.getY() + 50);

    Fire fire(entities.size() + 15 ,player->getId(), std::make_shared<Position>(firePosition), isPlayer);
    return std::make_shared<Fire>(fire);
}

void UpdateEntitySystem::move(std::shared_ptr<IMovingEntity> entity, Direction direction)
{
    if (direction == LEFT && entity->getPosition()->getX() > 0)
        entity->move(entity->getPosition()->getX() - 10, entity->getPosition()->getY(), entity->getPosition()->getZ());
    if (direction == RIGHT && entity->getPosition()->getX() < _windowLength - 300)
        entity->move(entity->getPosition()->getX() + 10, entity->getPosition()->getY(), entity->getPosition()->getZ());
    if (direction == UP && entity->getPosition()->getY() > 0)
        entity->move(entity->getPosition()->getX(), entity->getPosition()->getY() - 7, entity->getPosition()->getZ());
    if (direction == DOWN && entity->getPosition()->getY() < _windowHeight - 130)
        entity->move(entity->getPosition()->getX(), entity->getPosition()->getY() + 7, entity->getPosition()->getZ());

}

void UpdateEntitySystem::manageShip(std::shared_ptr<Player> &player, Events events)
{
    if (events.isZKey())
        move(std::dynamic_pointer_cast<IMovingEntity>(player), UP);
    if (events.isSKey())
        move(std::dynamic_pointer_cast<IMovingEntity>(player), DOWN);
    if (events.isQKey())
        move(std::dynamic_pointer_cast<IMovingEntity>(player), LEFT);
    if (events.isDKey())
        move(std::dynamic_pointer_cast<IMovingEntity>(player), RIGHT);
}

void UpdateEntitySystem::destroyEntity(std::vector<std::shared_ptr<IEntity>> &entities)
{
    for (size_t i = 0; i < entities.size(); ++i) {
        if (entities[i]->getType() == IEntity::FIRE
        && (entities[i]->getPosition()->getX() >= _windowLength - 300
        || entities[i]->getPosition()->getX() <= 0)) {
            entities.erase(entities.begin() + i);
            continue;
        }
        if (!(entities[i]->getType() == IEntity::PLAYER)
        && entities[i]->getPosition()->getX() <= 50)
            entities.erase(entities.begin() + 1);
    }
}