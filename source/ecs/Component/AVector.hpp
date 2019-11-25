//
// Created by $0QU000-PL44DU4VI3C9 on 19/11/2019.
//

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

#include "IComponent.hpp"

class AVector : public IComponent
{
    double _z = 0;

    double _y;

    double _x;

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX();
    double getY();
    double getZ();
};

#endif //CPP_RTYPE_2019_POSITION_HPP
