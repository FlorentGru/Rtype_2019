//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP
#define CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP

#include <memory>
#include "ISystem.hpp"

class UpdateEntitySystem : public ISystem {
public:
    void run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events);

private:
    void createFire();

    void moveLeft(std::shared_ptr<IEntity>);

    void manageShip();
};

#endif //CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP