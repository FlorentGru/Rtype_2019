//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#ifndef CPP_RTYPE_2019_ENEMY_HPP
#define CPP_RTYPE_2019_ENEMY_HPP

class Enemy : public ICollideEntity
{
private:

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
    bool hitBy(FireEntity);
    bool lootBonus();
};

#endif //CPP_RTYPE_2019_ENEMY_HPP
