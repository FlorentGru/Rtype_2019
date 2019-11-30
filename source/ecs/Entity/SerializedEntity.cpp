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

IEntity::Type SerializedEntity::getType() const {
    return _type;
}

void SerializedEntity::setType(IEntity::Type type) {
    _type = type;
}

int SerializedEntity::getId() const {
    return _id;
}

void SerializedEntity::setId(int id) {
    _id = id;
}

float SerializedEntity::getX() const {
    return _x;
}

void SerializedEntity::setX(float x) {
    _x = x;
}

float SerializedEntity::getY() const {
    return _y;
}

void SerializedEntity::setY(float y) {
    _y = y;
}

float SerializedEntity::getZ() const {
    return _z;
}

void SerializedEntity::setZ(float z) {
    _z = z;
}
