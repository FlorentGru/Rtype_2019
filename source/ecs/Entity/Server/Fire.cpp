//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "Fire.hpp"
#include "Timer.hpp"

Fire::Fire(int id, double x, double y, bool isPlayer = false, double z = 0)
{
    _id = id;
    Position position(x, y, z);
    Timer timer;
    _isPlayer = isPlayer;
    _component.clear();
    _component.push_back(std::make_shared<Position>(position));
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
}

void Fire::move(double x, double y, double z)
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Timer)); ++i);
    if (std::dynamic_pointer_cast<Timer>(_component[i])->restart("moveClock", 0.033)) {
        for (i = 0; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
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
    int i = 0;
    float x = 0;
    float y = 0;
    float z = 0;

    for (i = 0; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
    x = std::dynamic_pointer_cast<Position>(_component[i])->getX();
    y = std::dynamic_pointer_cast<Position>(_component[i])->getY();
    z = std::dynamic_pointer_cast<Position>(_component[i])->getZ();
    SerializedEntity res(IEntity::FIRE, _id, x, y, z);
    return res;
}