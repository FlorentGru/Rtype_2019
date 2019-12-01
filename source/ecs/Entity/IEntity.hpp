//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IENTITY_HPP
#define CPP_RTYPE_2019_IENTITY_HPP

#include <vector>
#include <memory>
#include "IComponent.hpp"
#include "Position.hpp"

/**
 * Interface of any entity meant to be used by the ECS
*/
class IEntity
{
public:
    enum Type {
        PLAYER,
        FIRE,
        ENEMY,
        DESTRUCTIBLE
    };

    /**
    * Gets the position component of the entity
    *
    * @return shared pointer of position component
    */
    virtual std::shared_ptr<Position> getPosition() = 0;

    /**
    * Gets the list of components inside the entity
    *
    * @return List of pointers toward any component
    */
    virtual std::vector<std::shared_ptr<IComponent>> getComponents() = 0;

    /**
    * Gets the type of the entity
    *
    * @return enum of entity type
    */
    virtual Type getType() = 0;

    /**
    * Gets the id of the entity
    *
    * @return integer representing the entity id
    */
    virtual int getId() = 0;
};

#endif //CPP_RTYPE_2019_IENTITY_HPP
