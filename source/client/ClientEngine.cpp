//
// Created by tfian on 26/11/2019.
//

#include "ClientEngine.hpp"

bool ClientEngine::draw(vector<shared_ptr<IRenderEntity>> entities)
{
        des.run(entities, getEvents());
}