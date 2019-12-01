//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#ifndef RTYPE_COLLIDESYSTEM_HPP
#define RTYPE_COLLIDESYSTEM_HPP

#include "ISystem.hpp"

/**
 * Class collideSystem to create the collision in all the game
 */

class CollideSystem : public ISystem
{
public:
    /** The function assembles of the function to chekc if a collide is do and need to call the good one function
         * 
         * @Param entities: took all the entities to call the collide function for all the entities
         *        events: unsed cause the override need to be here
         * 
         * @return a bool to check if the function return true and works, 
         */
    bool run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events) override;

private:
    void collide(std::vector<std::shared_ptr<IEntity>> &entities, size_t);
    void destroyEntity(std::vector<std::shared_ptr<IEntity>> &entities);
    bool isInRect(std::shared_ptr<IMovingEntity> first, std::shared_ptr<IMovingEntity> snd);
};

#endif //RTYPE_COLLIDESYSTEM_HPP
