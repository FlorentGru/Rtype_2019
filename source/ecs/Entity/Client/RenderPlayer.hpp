//
// Created by $0QU000-PL44DU4VI3C9 on 27/11/2019.
//

#ifndef RTYPE_RENDERPLAYER_HPP
#define RTYPE_RENDERPLAYER_HPP

#include <memory>
#include "Vector.hpp"
#include "IRenderEntity.hpp"

class RenderPlayer : public IRenderEntity
{
private:
    std::vector<std::shared_ptr<IComponent>> _component;
    size_t _pv;
    int _id;
public:
    RenderPlayer(size_t pv, int id, std::shared_ptr<Position> position);

    std::vector<std::shared_ptr<IComponent>> getComponents() override;

    Type getType() override;
    int getId() override;

    std::string getTexture() override;
    std::shared_ptr<Position> getPosition() override;
    size_t getPv();
};


#endif //RTYPE_RENDERPLAYER_HPP
