//
// Created by tfian on 25/11/2019.
//

#include "GameEngine.hpp"

vector<SerializedEntity> GameEngine::run(Events &events)
{
    vector<SerializedEntity> res;

    res.clear();
    if (!ecs.run(events))
        return res;
    return this->ecs.getEntities();
}
