//
// Created by $0QU000-PL44DU4VI3C9 on 01/12/2019.
//

#ifndef RTYPE_ENEMY_HPP
#define RTYPE_ENEMY_HPP


#include <IMovingEntity.hpp>

class Enemy : public IMovingEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    size_t _pv;
    int _id;

public:
    Enemy(size_t pv, int id, std::shared_ptr<Position> position);
    std::vector<std::shared_ptr<IComponent>> getComponents() override;
    Type getType() override;
    int getId() override;
    void move(double x, double y, double z) override;
    SerializedEntity serialize() override;
    std::shared_ptr<Position> getPosition() override;
    std::shared_ptr<Hitbox> getHitbox() const override;
    int getPv() const override;
    void setPv(int pv) override;

};


#endif //RTYPE_ENEMY_HPP
