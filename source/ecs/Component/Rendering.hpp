//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_RENDERING_HPP
#define CPP_RTYPE_2019_RENDERING_HPP

#include "IComponent.hpp"

class Rendering : public IComponent
{
private:
    std::string _soundEffect;
    std::string _texture;

public:
    std::string getSoundEffect();
    std::string getTexture();

    void setSoundEffect(std::string);
    void setTexture(std::string);

    std::type_index getId();
};

#endif //CPP_RTYPE_2019_RENDERING_HPP
