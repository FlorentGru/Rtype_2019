//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_ABSTRACTECS_HPP
#define RTYPE_ABSTRACTECS_HPP

#include <vector>
#include <memory>

#include "IRenderEntity.hpp"
#include "ISystem.hpp"
#include "Events.hpp"

using namespace std;

class AbstractEcs
{
public:
    virtual bool run(Events &events) = 0;

    vector<SerializedEntity> getEntities();

    bool addEntity(shared_ptr<IEntity> entity);
    bool addEntities(const vector<shared_ptr<IEntity>> &entities);

    bool removeAllEntities();

    bool addSystem(shared_ptr<ISystem> system);

    bool destroy();
protected:
    vector<shared_ptr<IEntity>> _entities;
    vector<shared_ptr<ISystem>> _systems;
};


#endif //RTYPE_ABSTRACTECS_HPP
