//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTECS_HPP
#define RTYPE_CLIENTECS_HPP

#include "AbstractEcs.hpp"
#include <iostream>

class ClientEcs : public AbstractEcs
{
public:
    bool run(Events &_events) override ;

private:
};


#endif //RTYPE_CLIENTECS_HPP
