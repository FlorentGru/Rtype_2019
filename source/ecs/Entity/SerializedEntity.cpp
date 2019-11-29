//
// Created by $0QU000-PL44DU4VI3C9 on 28/11/2019.
//

#include "SerializedEntity.hpp"

SerializedEntity::SerializedEntity(IEntity::Type type, int id, float x, float y, float z)
{
    _type = type;
    _id = id;
    _x = x;
    _y = y;
    _z = z;
}