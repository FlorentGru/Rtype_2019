//
// Created by $0QU000-PL44DU4VI3C9 on 01/12/2019.
//

#include "Rendering.hpp"
#include "RenderEnemy.hpp"

RenderEnemy::RenderEnemy(int id, std::shared_ptr<Position> position)
{
    _id = id;
    Rendering render("enemy.png", "", 0);
    _component.clear();
    _component.push_back(std::make_shared<Rendering>(render));
    _component.push_back(position);
}

IEntity::Type RenderEnemy::getType()
{
    return (IEntity::ENEMY);
}

std::vector<std::shared_ptr<IComponent>> RenderEnemy::getComponents()
{
    return _component;
}

int RenderEnemy::getId()
{
    return  _id;
}

std::string RenderEnemy::getTexture()
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Rendering)) && i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Rendering>(_component[i])->getTexture());
}

std::shared_ptr<Position> RenderEnemy::getPosition()
{
    size_t i = 0;

    for (; _component[i]->getId() != std::type_index(typeid(Position)) && i < _component.size(); ++i);
    return (std::dynamic_pointer_cast<Position>(_component[i]));
}