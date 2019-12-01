//
// Created by $0QU000-PL44DU4VI3C9 on 29/11/2019.
//

#ifndef RTYPE_FIRE_HPP
#define RTYPE_FIRE_HPP

#include "IMovingEntity.hpp"
#include "Velocity.hpp"

class Fire : public IMovingEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    int _id;
    int _playerId;
    bool _isPlayer;
    int _pv;

public:

    /**
    * Constructs a fire entity
    *
     * @param id entity id
     * @param playerId id player who fired
     * @param position entity position
     * @param isPlayer to know if the fire is link with a player
    */
    Fire(int id, int playerId, std::shared_ptr<Position> position, bool isPlayer);

    std::shared_ptr<Position> getPosition() override;
    int getPlayerId() const;
    void move(float x, float y, float z) override;
    std::vector<std::shared_ptr<IComponent>> getComponents() override;
    Type getType() override;
    int getId() override;
    bool isPlayer() const;
    SerializedEntity serialize() override;
    int getPv() const override;
    void setPv(int pv) override;
    std::shared_ptr<Hitbox> getHitbox() const override;
};

#endif //RTYPE_FIRE_HPP
