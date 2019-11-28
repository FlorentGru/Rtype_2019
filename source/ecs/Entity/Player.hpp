//
// Created by $0QU000-PL44DU4VI3C9 on 22/11/2019.
//

#ifndef CPP_RTYPE_2019_PLAYER_HPP
#define CPP_RTYPE_2019_PLAYER_HPP

#include <memory>
#include "IMovingEntity.hpp"

class Player : public IMovingEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    size_t _pv;

public:
    Player(size_t pv, double x, double y, double z);
    std::vector<std::shared_ptr<IComponent>> getComponents() override;
    Type getType() override;

    void move(double x, double y) override;

};

#endif //CPP_RTYPE_2019_PLAYER_HPP
