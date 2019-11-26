//
// Created by $0QU000-PL44DU4VI3C9 on 19/11/2019.
//

#ifndef CPP_RTYPE_2019_AVECTOR_HPP
#define CPP_RTYPE_2019_AVECTOR_HPP

#include "IComponent.hpp"

class AVector : public IComponent
{
private:
    double _z;
    double _y;
    double _x;

public:
    AVector(double x, double y, double z);

    void setX(double);
    void setY(double);
    void setZ(double);

    double getX();
    double getY();
    double getZ();
};

#endif //CPP_RTYPE_2019_AVECTOR_HPP
