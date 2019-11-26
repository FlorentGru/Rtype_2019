//
// Created by tfian on 27/11/2019.
//

#ifndef RTYPE_IEVENTSSYSTEM_HPP
#define RTYPE_IEVENTSSYSTEM_HPP

#include <memory>
#include "ISystem.hpp"

class IEventsSystem : public ISystem
{
public:
    bool run(vector<shared_ptr<IEntity>> &entities, Events &events) override = 0;
protected:
    virtual bool getEvents(Events &events) = 0;
};


#endif //RTYPE_IEVENTSSYSTEM_HPP
