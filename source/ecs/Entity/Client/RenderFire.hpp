//
// Created by $0QU000-PL44DU4VI3C9 on 28/11/2019.
//

#ifndef RTYPE_RENDERFIRE_HPP
#define RTYPE_RENDERFIRE_HPP


#include <vector>
#include "IRenderEntity.hpp"

class RenderFire : public  IRenderEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    int _id;
public:
    RenderFire(int id, std::shared_ptr<Position> position);

    std::vector<std::shared_ptr<IComponent>> getComponents() override;

    Type getType() override;
    int getId() override;

    std::string getTexture() override;
    std::shared_ptr<Position> getPosition() override;
};

#endif //RTYPE_RENDERFIRE_HPP
