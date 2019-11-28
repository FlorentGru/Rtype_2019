//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#ifndef RTYPE_FIRE_HPP
#define RTYPE_FIRE_HPP


#include "IMovingEntity.hpp"
#include "Velocity.hpp"
#include "Position.hpp"

class Fire : public IMovingEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    size_t _id;
    bool _isPlayer;

public:
    Fire(int id, double x, double y, bool isPlayer, double z);

    void move(double x, double y, double z) override;
    std::vector<std::shared_ptr<IComponent>> getComponents() override;
    Type getType() override;
    int getId() override;
};


#endif //RTYPE_FIRE_HPP
