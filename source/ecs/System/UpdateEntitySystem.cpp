//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "UpdateEntitySystem.hpp"

UpdateEntitySystem::UpdateEntitySystem()
{
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
            if (events.isEnter()) {
                Fire fire = createFire(player, true);
                entities.push_back(std::make_shared<Fire>(fire));
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
    return _isSucceed;
}

Fire UpdateEntitySystem::createFire(std::shared_ptr<Player> &player, bool isPlayer)
{

    Fire fire(player->getId(), player->getPosition(), isPlayer);
    return fire;
}

void UpdateEntitySystem::move(std::shared_ptr<IMovingEntity> entity, Direction direction)
{
    if (direction == LEFT && entity->getPosition()->getX() > 0)
        entity->move(entity->getPosition()->getX() - 1, entity->getPosition()->getY(), entity->getPosition()->getZ());
    if (direction == RIGHT && entity->getPosition()->getX() < _windowLength)
        entity->move(entity->getPosition()->getX() + 1, entity->getPosition()->getY(), entity->getPosition()->getZ());
    if (direction == UP && entity->getPosition()->getY() > 0)
        entity->move(entity->getPosition()->getX(), entity->getPosition()->getY() - 1, entity->getPosition()->getZ());
    if (direction == DOWN && entity->getPosition()->getY() < _windowHeight)
        entity->move(entity->getPosition()->getX(), entity->getPosition()->getY() + 1, entity->getPosition()->getZ());

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