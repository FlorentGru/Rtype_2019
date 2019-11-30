//
// Created by tfian on 26/11/2019.
//

#ifndef RTYPE_IRENDERSYSTEM_HPP
#define RTYPE_IRENDERSYSTEM_HPP

#include <memory>
#include "IRenderEntity.hpp"
#include "ISystem.hpp"

class IRenderSystem : public ISystem
{
public:
    bool run(vector<shared_ptr<IEntity>> &entities, Events &events) override = 0;
protected:
    virtual bool draw(std::shared_ptr<IRenderEntity> renderEntity) = 0;
    virtual void CreateWindow() = 0;
};

#endif //RTYPE_IRENDERSYSTEM_HPP
