//
// Created by tfian on 25/11/2019.
//

#ifndef RTYPE_SERVERECS_HPP
#define RTYPE_SERVERECS_HPP

#include "AbstractEcs.hpp"

using namespace std;

class ServerEcs : public AbstractEcs
{
public:
    ServerEcs() = default;
    bool run(Events &events) override;
};

#endif //RTYPE_SERVERECS_HPP
