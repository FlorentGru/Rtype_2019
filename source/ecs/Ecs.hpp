//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_ECS_HPP
#define RTYPE_ECS_HPP

#include "AbstractEcs.hpp"

using namespace std;

class Ecs : public AbstractEcs
{
public:
    bool run(Events events) override ;


};


#endif //RTYPE_ECS_HPP
