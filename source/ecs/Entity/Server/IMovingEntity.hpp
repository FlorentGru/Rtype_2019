//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IMOVINGENTITY_HPP
#define CPP_RTYPE_2019_IMOVINGENTITY_HPP

#include "IEntity.hpp"
#include "SerializedEntity.hpp"

class IMovingEntity : public IEntity
{
public:
    virtual void move(double x, double y, double z) = 0;

    virtual SerializedEntity serialize() = 0;
};

#endif //CPP_RTYPE_2019_IMOVINGENTITY_HPP
