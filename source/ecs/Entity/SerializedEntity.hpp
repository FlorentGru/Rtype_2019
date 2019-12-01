//
// Created by $0QU000-PL44DU4VI3C9 on 28/11/2019.
//

#ifndef RTYPE_SERIALIZEDENTITY_HPP
#define RTYPE_SERIALIZEDENTITY_HPP

#include "Position.hpp"
#include "IEntity.hpp"

/**
 * Simplified form of any entity so it can be sent into a UDP packet, then interpreted by the
*/
class SerializedEntity
{
public:

    /**
     * Constructs a serialized entity
     *
     * @param type entity type
     * @param id entity id
     * @param x position on x axis
     * @param y position on y axis
     * @param z position on z axis
     */
    SerializedEntity(IEntity::Type type, int id, float x, float y, float z = 0);

    IEntity::Type getType() const;
    void setType(IEntity::Type type);
    int getId() const;
    void setId(int id);
    float getX() const;
    void setX(float x);
    float getY() const;
    void setY(float y);
    float getZ() const;
    void setZ(float z);

private:
    IEntity::Type _type;
    int _id;
    float _x;
    float _y;
    float _z;
};

#endif //RTYPE_SERIALIZEDENTITY_HPP
