//
// Created by $0QU000-PL44DU4VI3C9 on 28/11/2019.
//

#include "Rendering.hpp"
#include "RenderFire.hpp"

RenderFire::RenderFire(int id, std::shared_ptr<Position> position)
{
    _id = id;
    Rendering rendering("fire.png", "piew_piew.mp3", 0);
    _component.clear();
    _component.push_back(std::make_shared<Rendering>(rendering));
    _component.push_back(position);
}

IEntity::Type RenderFire::getType()
{
    return (IEntity::FIRE);
}

std::vector<std::shared_ptr<IComponent>> RenderFire::getComponents()
{
    return _component;
}

int RenderFire::getId()
{
    return  _id;
}

std::string RenderFire::getTexture()
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Rendering)); ++i);
    return (std::dynamic_pointer_cast<Rendering>(_component[i])->getTexture());
}

std::shared_ptr<Position> RenderFire::getPosition()
{
    int i = 0;

    for (; _component[i]->getId() == std::type_index(typeid(Position)); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}