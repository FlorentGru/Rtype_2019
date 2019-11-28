//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP
#define CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP

#include <memory>
#include "ISystem.hpp"
#include "server/Player.hpp"

class UpdateEntitySystem : public ISystem {
public:
    UpdateEntitySystem() = default;
    bool run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events) override;

private:
    bool _isSucceed = true;

    void createFire();

    void moveLeft(std::shared_ptr<IEntity>);

    void manageShip(std::shared_ptr<IEntity> player);
};

#endif //CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP
