//
// Created by $0QU000-PL44DU4VI3C9 on 01/12/2019.
//

#ifndef RTYPE_RENDERENEMY_HPP
#define RTYPE_RENDERENEMY_HPP


#include "IRenderEntity.hpp"

class RenderEnemy : public IRenderEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    int _id;
public:
    RenderEnemy(int id, std::shared_ptr<Position> position);

    std::vector<std::shared_ptr<IComponent>> getComponents() override;

    Type getType() override;
    int getId() override;

    std::string getTexture() override;
    std::shared_ptr<Position> getPosition() override;
};


#endif //RTYPE_RENDERENEMY_HPP
