//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Velocity.hpp"

Velocity::Velocity(float x, float y, float z): Vector(x, y, z)
{}

std::type_index Velocity::getId()
{
    return (std::type_index(typeid(Velocity)));
}