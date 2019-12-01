//
// Created by $0QU000-PL44DU4VI3C9 on 21/11/2019.
//

#ifndef CPP_RTYPE_2019_IMOVINGENTITY_HPP
#define CPP_RTYPE_2019_IMOVINGENTITY_HPP

#include "IEntity.hpp"
#include "SerializedEntity.hpp"
#include "Hitbox.hpp"

/**
 * Entity type thats is influenced
*/
class IMovingEntity : public IEntity
{
public:
    /**
    * Update the position of an entity
    *
    * @param x position on x axis
    * @param y position on y axis
    * @param z position on z axis
    */
    virtual void move(double x, double y, double z) = 0;

    /**
    * Constructs a serialized entity
    *
    * @return the entity serialized
    */
    virtual SerializedEntity serialize() = 0;

    /**
    * Constructs a serialized entity
    *
    * @return a pointer on the hitbox of the entity
    */
    virtual std::shared_ptr<Hitbox> getHitbox() const = 0;


    virtual int getPv() const = 0;

    virtual void setPv(int pv) = 0;
};

#endif //CPP_RTYPE_2019_IMOVINGENTITY_HPP
