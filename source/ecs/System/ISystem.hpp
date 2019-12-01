//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_ISYSTEM_HPP
#define CPP_RTYPE_2019_ISYSTEM_HPP

#include <vector>
#include <Server/IMovingEntity.hpp>
#include "IEntity.hpp"
#include "Events.hpp"

using namespace std;

/**
 * Interface ISystem to override the funtion run for all the system
 */

class ISystem {

public:
    virtual bool run(vector<shared_ptr<IEntity>> &entities, Events &events) = 0;
};

#endif //CPP_RTYPE_2019_ISYSTEM_HPP
