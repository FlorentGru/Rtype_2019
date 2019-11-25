//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#ifndef CPP_RTYPE_2019_FIRE_HPP
#define CPP_RTYPE_2019_FIRE_HPP

#include "ICollideEntity.hpp"

class Fire : public ICollideEntity
{
private:
    int _damages;

public:
    //herited function:
    //IEntity
    std::vector<IComponent> getComponents();
    std::type_index getType();

    //ICollideEntity
    Collider getCollider();
    void move(double x, double y);

    //personnal function
    int getDamages();
    bool hit(ICollideEntity);
};

#endif //CPP_RTYPE_2019_FIRE_HPP
