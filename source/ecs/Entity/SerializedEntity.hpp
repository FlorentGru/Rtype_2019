//
// Created by $0QU000-PL44DU4VI3C9 on 28/11/2019.
//

#ifndef RTYPE_SERIALIZEDENTITY_HPP
#define RTYPE_SERIALIZEDENTITY_HPP

#include "Position.hpp"
#include "IEntity.hpp"

class SerializedEntity
{
private:
    IEntity::Type _type;
    int _id;
    float _x;
    float _y;
    float _z;

public:
    SerializedEntity(IEntity::Type type, int id, float x, float y, float z = 0);
};

#endif //RTYPE_SERIALIZEDENTITY_HPP
