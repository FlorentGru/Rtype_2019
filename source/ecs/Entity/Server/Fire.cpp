//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "Fire.hpp"
#include "Timer.hpp"

Fire::Fire(int id, std::shared_ptr<Position> position, bool isPlayer = false)
{
    _id = id;
    Timer timer;
    Hitbox hitbox(100, 50);
    _isPlayer = isPlayer;
    _component.clear();
    _component.push_back(position);
    timer.create_clock("moveClock");
    _component.push_back(std::make_shared<Timer>(timer));
    if (_isPlayer) {
        Velocity velocity(1, 0);
        _component.push_back(std::make_shared<Velocity>(velocity));
    }
    else {
        Velocity velocity(-1, 0);
        _component.push_back(std::make_shared<Velocity>(velocity));
    }
    _component.push_back(std::make_shared<Hitbox>(hitbox));

}

void Fire::move(double x, double y, double z)
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

std::vector<std::shared_ptr<IComponent>> Fire::getComponents()
{
    return _component;
}

IEntity::Type Fire::getType()
{
    return (IEntity::FIRE);
}

int Fire::getId()
{
    return _id;
}

SerializedEntity Fire::serialize()
{
    size_t i = 0;
    float x = 0;
    float y = 0;
    float z = 0;

    for (i = 0; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    x = std::dynamic_pointer_cast<Position>(_component[i])->getX();
    y = std::dynamic_pointer_cast<Position>(_component[i])->getY();
    z = std::dynamic_pointer_cast<Position>(_component[i])->getZ();
    SerializedEntity res(IEntity::FIRE, _id, x, y, z);
    return res;
}

std::shared_ptr<Position> Fire::getPosition()
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}

bool Fire::isPlayer() const
{
    return _isPlayer;
}

std::shared_ptr<Hitbox> Fire::getHitbox() const
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Hitbox))&&  i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Hitbox>(_component[i]));
}

int Fire::getPv() const
{
    return _pv;
}

void Fire::setPv(int pv)
{
    _pv = pv;
}