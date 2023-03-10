//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP
#define CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP

#include <memory>
#include <iostream>
#include "ISystem.hpp"
#include "Player.hpp"
#include "Fire.hpp"
#include "Timer.hpp"

/**
 * Class UpdateEntitySystem inherited the ISystem. Move and update all the entities in the ecs
 */

class UpdateEntitySystem : public ISystem {
public:
    /**
    * Constructor of the class who create the clock "fire" and the window lenght, height
    */
    UpdateEntitySystem();

    /**
    * Funtion run call all the function to move and update the player or the fire
    * 
    * @Param entities: Took all the entities to know what to update or create
    * @Param events: Took the event to know in wich direction the player need to move
    * 
    * @return a bool to return if the function work well and return true
    */
    bool run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events) override;

private:

    enum Direction {
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    bool _isSucceed = true;

    std::shared_ptr<Fire> createFire(std::shared_ptr<Player> &player, bool isPlayer, std::vector<std::shared_ptr<IEntity>> &entities);

    void move(std::shared_ptr<IMovingEntity>, Direction direction);

    void manageShip(std::shared_ptr<Player> &player, Events event);

    void destroyEntity(std::vector<std::shared_ptr<IEntity>> &entities);

    float _windowLength;
    float _windowHeight;
    Timer _timer;
};

#endif //CPP_RTYPE_2019_UPDATEENTITYSYSTEM_HPP
