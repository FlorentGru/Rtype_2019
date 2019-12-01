//
// Created by $0QU000-PL44DU4VI3C9 on 19/11/2019.
//

#ifndef CPP_RTYPE_2019_VECTOR_HPP
#define CPP_RTYPE_2019_VECTOR_HPP

#include "IComponent.hpp"

class Vector : public IComponent
{
private:
    float _z;
    float _y;
    float _x;

public:
    Vector(float x, float y, float z = 0);
    Vector();

    void setX(float);
    void setY(float);
    void setZ(float);

    float getX() const;
    float getY() const;
    float getZ() const;
};

#endif //CPP_RTYPE_2019_VECTOR_HPP
