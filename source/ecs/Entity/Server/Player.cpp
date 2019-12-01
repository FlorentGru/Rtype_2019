//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#include "Position.hpp"
#include "Player.hpp"
#include "Rendering.hpp"
#include "Timer.hpp"

Player::Player(size_t pv, int id, std::shared_ptr<Position> position)
{
    Timer timer;
    timer.create_clock("moveClock");
    _component.clear();
    _component.push_back(std::make_shared<Timer>(timer));
    _component.push_back(position);
    _pv = pv;
    _id = id;
}

std::vector<std::shared_ptr<IComponent>> Player::getComponents()
{
    return _component;
}

IEntity::Type Player::getType()
{
    return (IEntity::PLAYER);
}

int Player::getId()
{
    return  _id;
}

void Player::move(double x, double y, double z)
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Timer)) && i < _component.size(); ++i);
    if (std::dynamic_pointer_cast<Timer>(_component[i])->restart("moveClock", 0.033)) {
        for (i = 0; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
        std::dynamic_pointer_cast<Position>(_component[i])->setX(x);
        std::dynamic_pointer_cast<Position>(_component[i])->setY(y);
        std::dynamic_pointer_cast<Position>(_component[i])->setZ(z);
    }
}

SerializedEntity Player::serialize()
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

std::shared_ptr<Position> Player::getPosition()
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}

std::shared_ptr<Hitbox> Player::getHitbox() const
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Hitbox)); ++i);
    return (std::dynamic_pointer_cast<Hitbox>(_component[i]));
}

int Player::getPv() const
{
    return _pv;
}

void Player::setPv(int pv)
{
    _pv = pv;
}