//
// Created by $0QU000-PL44DU4VI3C9 on 25/11/2019.
//

#ifndef CPP_RTYPE_2019_COLLIDESYSTEM_HPP
#define CPP_RTYPE_2019_COLLIDESYSTEM_HPP

#include "ISystem.hpp"

class CollideSystem : public ISystem
{
public:
    void run(std::vector<std::shared_ptr<IEntity>> &entities, Events &events);

private:
    bool isCollide(IEntity);
};

#endif //CPP_RTYPE_2019_COLLIDESYSTEM_HPP
