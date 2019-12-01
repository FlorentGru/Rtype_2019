//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Vector.hpp"

Vector::Vector(float x, float y, float z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vector::Vector()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

float Vector::getX() const
{
    return _x;
}

float Vector::getY() const
{
    return _y;
}

float Vector::getZ() const
{
    return _z;
}

void Vector::setX(float x)
{
    _x = x;
}

void Vector::setY(float y)
{
    _y = y;
}

void Vector::setZ(float z)
{
    _z = z;
}