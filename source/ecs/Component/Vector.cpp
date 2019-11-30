//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "Vector.hpp"

Vector::Vector(double x, double y, double z)
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

double Vector::getX() const
{
    return _x;
}

double Vector::getY() const
{
    return _y;
}

double Vector::getZ() const
{
    return _z;
}

void Vector::setX(double x)
{
    _x = x;
}

void Vector::setY(double y)
{
    _y = y;
}

void Vector::setZ(double z)
{
    _z = z;
}