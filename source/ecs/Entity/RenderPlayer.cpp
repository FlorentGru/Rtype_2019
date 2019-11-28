//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#include "RenderPlayer.hpp"
#include "Rendering.hpp"
#include "Position.hpp"
#include "Vector.hpp"

RenderPlayer::RenderPlayer(int pv, double x, double y, double z = 0)
{
    Rendering rendering("player.png", "", pv);
    Position position(x, y, z);
    _pv = pv;
    _component.clear();
    _component.push_back(std::make_shared<Rendering>(rendering));
    _component.push_back(std::make_shared<Position>(position));
}

IEntity::Type RenderPlayer::getType()
{
    return (IEntity::PLAYER);
}

std::vector<std::shared_ptr<IComponent>> RenderPlayer::getComponents()
{
    return _component;
}

std::string RenderPlayer::getTexture()
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Rendering)); ++i);
    return (std::dynamic_pointer_cast<Rendering>(_component[i])->getTexture());
}

std::shared_ptr<Position> RenderPlayer::getPosition()
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}

size_t RenderPlayer::getPv()
{
    return _pv;
}