//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#include "Hitbox.hpp"

Hitbox::Hitbox(size_t length, size_t heigh)
{
    _length = length;
    _heigh = heigh;
}

size_t Hitbox::getLength() const
{
    return _length;
}

size_t Hitbox::getHeigh() const
{
    return _heigh;
}

std::type_index Hitbox::getId()
{
    return (std::type_index(typeid(Hitbox)));
}

void Hitbox::setLength(size_t length)
{
    _length = length;
}

void Hitbox::setHeigh(size_t heigh)
{
    _heigh = heigh;
}