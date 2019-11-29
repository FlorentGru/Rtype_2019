//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IENTITY_HPP
#define CPP_RTYPE_2019_IENTITY_HPP

#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "Position.hpp"


class IEntity
{
public:
    enum Type {
        PLAYER,
        FIRE,
        ENEMY,
        DESTRUCTIBLE
    };

    virtual std::shared_ptr<Position> getPosition() = 0;

    virtual std::vector<std::shared_ptr<IComponent>> getComponents() = 0;

    virtual Type getType() = 0;

    virtual int getId() = 0;
};

#endif //CPP_RTYPE_2019_IENTITY_HPP
