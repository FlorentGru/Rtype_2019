//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_ICOLLIDEENTITY_HPP
#define CPP_RTYPE_2019_ICOLLIDEENTITY_HPP

#include "IEntity.hpp"

class IMovingEntity : public IEntity
{
    virtual void move(double x, double y, double z) = 0;
};

#endif //CPP_RTYPE_2019_ICOLLIDEENTITY_HPP
