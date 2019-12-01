//
// Created by $0QU000-PL44DU4VI3C9 on 01/12/2019.
//

#include "Timer.hpp"
#include "Enemy.hpp"

Enemy::Enemy(size_t pv, int id, std::shared_ptr<Position> position)
{
    Timer timer;
    timer.create_clock("moveClock");
    _pv = pv;
    _id = id;
    _component.push_back(position);
    _component.push_back(std::make_shared<Timer>(timer));
}

std::vector<std::shared_ptr<IComponent>> Enemy::getComponents()
{
    return _component;
}

IEntity::Type Enemy::getType()
{
    return (IEntity::ENEMY);
}

int Enemy::getId()
{
    return _id;
}

void Enemy::move(double x, double y, double z)
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Timer)) && i < _component.size(); ++i);
    if (std::dynamic_pointer_cast<Timer>(_component[i])->restart("moveClock", 0.02)) {
        for (i = 0; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
        std::dynamic_pointer_cast<Position>(_component[i])->setX(x);
        std::dynamic_pointer_cast<Position>(_component[i])->setY(y);
        std::dynamic_pointer_cast<Position>(_component[i])->setZ(z);
    }
}

SerializedEntity Enemy::serialize()
{
    size_t i = 0;
    float x = 0;
    float y = 0;
    float z = 0;

    for (i = 0; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    x = std::dynamic_pointer_cast<Position>(_component[i])->getX();
    y = std::dynamic_pointer_cast<Position>(_component[i])->getY();
    z = std::dynamic_pointer_cast<Position>(_component[i])->getZ();
    SerializedEntity res(IEntity::PLAYER, _id, x, y, z);
    return res;
}

std::shared_ptr<Position> Enemy::getPosition()
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}

std::shared_ptr<Hitbox> Enemy::getHitbox() const
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Hitbox)); ++i);
    return (std::dynamic_pointer_cast<Hitbox>(_component[i]));
}

int Enemy::getPv() const
{
    return _pv;
}

void Enemy::setPv(int pv)
{
    _pv = pv;
}