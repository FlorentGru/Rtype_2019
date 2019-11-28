//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Rendering.hpp"

Rendering::Rendering(const std::string &texture, const std::string &soundEffect, size_t pv)
{
    _texture = texture;
    _soundEffect = soundEffect;
    _pv = pv;
    _scaleX = 1;
    _scaleY = 1;
}

std::type_index Rendering::getId()
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

size_t Rendering::getPv()
{
    return _pv;
}

float Rendering::getScaleX()
{
    return _scaleX;
}

float Rendering::getScaleY()
{
    return _scaleY;
}

void Rendering::setSoundEffect(const std::string &soundEffect)
{
    _soundEffect = soundEffect;
}

void Rendering::setTexture(const std::string &texture)
{
    _texture = texture;
}

void Rendering::setPv(size_t pv)
{
    _pv = pv;
}

void Rendering::setScaleX(float scaleX)
{
    _scaleX = scaleX;
}

void Rendering::setScaleY(float scaleY)
{
    _scaleY = scaleY;
}