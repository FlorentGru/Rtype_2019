//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_ABSTRACTECS_HPP
#define RTYPE_ABSTRACTECS_HPP

#include <vector>
#include <memory>

#include "Entity/IRenderEntity.hpp"
#include "System/ISystem.hpp"
#include "System/Events.hpp"

using namespace std;

class AbstractEcs
{
public:
    virtual bool run(Events events) = 0;

    const vector<shared_ptr<IRenderEntity>> &getRenderEntities();

    bool addEntity(shared_ptr<IEntity> entity);
    bool addEntities(vector<shared_ptr<IEntity>> entities);

    bool removeAllEntities();

    bool addSystem(shared_ptr<ISystem> system);

    bool destroy();
private:
    vector<shared_ptr<IEntity>> entities;
    vector<shared_ptr<ISystem>> systems;
};


#endif //RTYPE_ABSTRACTECS_HPP
