//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Rendering.hpp"

type_index Rendering::getId()
{
    return (std::type_index(typeid(Rendering)));
}

std::string Rendering::getSoundEffect()
{
    return _soundEffect;
}

std::string Rendering::getTexture()
{
    return _texture;
}

void Rendering::setSoundEffect(std::string soundEffect)
{
    _soundEffect = soundEffect;
}

void Rendering::setTexture(std::string texture)
{
    _texture = texture;
}