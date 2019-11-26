//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IRENDERENTITY_HPP
#define CPP_RTYPE_2019_IRENDERENTITY_HPP

#include "IEntity.hpp"

class IRenderEntity : public IEntity
{
    virtual RenderComponent getRenderComponent() = 0;
};

#endif //CPP_RTYPE_2019_IRENDERENTITY_HPP
