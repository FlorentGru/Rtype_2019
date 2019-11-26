//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#include "AVector.hpp"

AVector::AVector(double x, double y, double z = 0)
{
    _x = x;
    _y = y;
    _z = z;
}

double AVector::getX()
{
    return _x;
}

double AVector::getY()
{
    return _y;
}

double AVector::getZ()
{
    return _z;
}

void AVector::setX(double x)
{
    _x = x;
}

void AVector::setY(double y)
{
    _y = y;
}

void AVector::setZ(double z)
{
    _z = z;
}