//
// Created by tfian on 25/11/2019.
//

#include "AbstractEcs.hpp"

bool AbstractEcs::addEntity(shared_ptr<IEntity> entity) {
    this->_entities.emplace_back(entity);
    return true;
}

bool AbstractEcs::addEntities(const vector<shared_ptr<IEntity>> &entities_) {

    for (auto &entity : entities_) {
        this->_entities.emplace_back(entity);
    }
    return true;
}

bool AbstractEcs::removeAllEntities() {
    this->_entities.clear();
    return true;
}

bool AbstractEcs::addSystem(shared_ptr<ISystem> system)
{
    this->_systems.emplace_back(system);
    return true;
}

bool AbstractEcs::destroy()
{
    return false;
}

vector<SerializedEntity> AbstractEcs::getEntities()
{
    vector<SerializedEntity> res;

    for (shared_ptr<IEntity> &entity : _entities) {
        res.emplace_back(std::dynamic_pointer_cast<IMovingEntity>(entity)->serialize());
    }
    return res;
}
