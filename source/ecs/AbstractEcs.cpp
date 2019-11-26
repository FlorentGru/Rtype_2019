//
// Created by tfian on 25/11/2019.
//

#include "AbstractEcs.hpp"

/*const vector<shared_ptr<IRenderEntity>> &AbstractEcs::getRenderEntities() {
    return this->entities;
}*/

bool AbstractEcs::addEntity(shared_ptr<IEntity> entity) {
    this->entities.emplace_back(entity);
    return true;
}

bool AbstractEcs::addEntities(const vector<shared_ptr<IEntity>> &entities) {

    for (auto &entity : entities) {
        this->entities.emplace_back(entity);
    }
    return true;
}

bool AbstractEcs::removeAllEntities() {
    this->entities.clear();
    return true;
}

bool AbstractEcs::addSystem(shared_ptr<ISystem> system) {
    this->systems.emplace_back(system);
    return true;
}

bool AbstractEcs::destroy() {
    return false;
}
