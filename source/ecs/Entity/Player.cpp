//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#include <Position.hpp>
#include "Player.hpp"
#include "Rendering.hpp"
#include "Timer.hpp"

Player::Player(int pv, double x, double y, double z = 0)
{
    Rendering rendering("player.png", "");
    Timer timer;
    Position position(x, y , z);
    timer.create_clock("moveClock");
    _component.clear();
    _component.push_back(std::make_shared<Rendering>(rendering));
    _component.push_back(std::make_shared<Timer>(timer));
    _component.push_back(std::make_shared<Position>(position));
    _pv = pv;
}

std::vector<std::shared_ptr<IComponent>> Player::getComponents()
{
    return _component;
}

std::type_index Player::getType()
{
    return (std::type_index(typeid(Player)));
}

void Player::move(double x, double y) {
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Timer)); ++i);
    if (std::dynamic_pointer_cast<Timer>(_component[i])->restart("moveClock", 0.033)) {
        for (i = 0; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
        std::dynamic_pointer_cast<Position>(_component[i])->setX(x);
        std::dynamic_pointer_cast<Position>(_component[i])->setY(y);
    }
}