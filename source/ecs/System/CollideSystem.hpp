//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#ifndef RTYPE_COLLIDESYSTEM_HPP
#define RTYPE_COLLIDESYSTEM_HPP

#include "ISystem.hpp"

class CollideSystem : public ISystem
{
public:
    bool run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events) override;

private:
    void collide(std::vector<std::shared_ptr<IEntity>> &entities, size_t);
    void destroyEntity(std::vector<std::shared_ptr<IEntity>> &entities);
    bool isInRect(std::shared_ptr<IMovingEntity> first, std::shared_ptr<IMovingEntity> snd);
};

#endif //RTYPE_COLLIDESYSTEM_HPP
