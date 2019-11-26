//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_ISYSTEM_HPP
#define CPP_RTYPE_2019_ISYSTEM_HPP

#include <vector>
#include "Entity/IEntity.hpp"
#include "System/Events.hpp"

using namespace std;

class ISystem {

public:
    virtual bool run(vector<shared_ptr<IEntity>> &entities, Events &events) = 0;
};

#endif //CPP_RTYPE_2019_ISYSTEM_HPP
