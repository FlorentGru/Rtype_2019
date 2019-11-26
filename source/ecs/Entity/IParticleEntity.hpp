//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_EENTITY_HPP
#define CPP_RTYPE_2019_EENTITY_HPP

#include "IEntity.hpp"

class IParticleEntity : public IEntity
{
    virtual LifeTime getLifeTime() = 0;
};

#endif //CPP_RTYPE_2019_EENTITY_HPP
