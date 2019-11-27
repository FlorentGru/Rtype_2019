//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IENTITY_HPP
#define CPP_RTYPE_2019_IENTITY_HPP

#include <vector>
#include "IComponent.hpp"

class IEntity
{
public:
    virtual std::vector<std::shared_ptr<IComponent>> getComponents() = 0;

    virtual std::type_index getType() = 0;
};

#endif //CPP_RTYPE_2019_IENTITY_HPP
