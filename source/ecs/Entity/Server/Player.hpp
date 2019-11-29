//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP

#include "IMovingEntity.hpp"

class Player : public IMovingEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    size_t _pv;
    int _id;

public:
    Player(size_t pv, int id,std::shared_ptr<Position> position);
    std::vector<std::shared_ptr<IComponent>> getComponents() override;
    Type getType() override;
    int getId() override;
    void move(double x, double y, double z) override;
    SerializedEntity serialize() override;
    std::shared_ptr<Position> getPosition() override;
};

#endif //CPP_RTYPE_2019_PLAYER_HPP
