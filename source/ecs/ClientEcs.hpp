//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_CLIENTECS_HPP
#define RTYPE_CLIENTECS_HPP

#include "AbstractEcs.hpp"

class ClientEcs : public AbstractEcs
{
public:
    bool run(Events _events) override ;

    const Events &getEvents() const ;

private:
    Events events;
};


#endif //RTYPE_CLIENTECS_HPP
