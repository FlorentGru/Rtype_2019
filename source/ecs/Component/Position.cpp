//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Position.hpp"

Position::Position(double x, double y, double z): Vector(x, y, z)
{}

std::type_index Position::getId()
{
    return (std::type_index(typeid(Position)));
}

Position::Position(const Position &position) : Vector(position.getX(), position.getY(), position.getZ())
{

}