//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_GAMEENGINE_HPP
#define RTYPE_GAMEENGINE_HPP

#include "ServerEcs.hpp"

using namespace std;

class GameEngine
{
public:
    vector<shared_ptr<IRenderEntity>> run(Events events);
private:
    ServerEcs ecs;
};


#endif //RTYPE_GAMEENGINE_HPP
