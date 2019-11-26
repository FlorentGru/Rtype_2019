//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP

#include "ICollideEntity.hpp"

class Player : public ICollideEntity
{
public:
    //herited function:
    //IEntity
    std::vector<IComponent> getComponents();
    std::type_index getType();

    //ICollideEntity
    Collider getCollider();
    void move(double x, double y);

    //personnal function
    fireEntity fire();
    bool hitBy(ICollideEntity);
};

#endif //CPP_RTYPE_2019_PLAYER_HPP
