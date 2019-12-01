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
    size_t _pv;
    float _scaleX;
    float _scaleY;

public:
    /**
     * Initialize displaying information
     * @param texture for the component
     * @param soundEffect on event per component
     * @param pv is the actual life
     */
    Rendering(const std::string &texture, const std::string &soundEffect, size_t pv);

    /**
     * Get the sound
     * @return soundEffect
     */
    std::string getSoundEffect();

    /**
     * Get the texture
     * @return Texture
     */
    std::string getTexture();

    /**
     * Get the actual life
     * @return actual pv
     */
    size_t getPv();

    /**
     * Get the x scaling argument
     * @return scale x
     */
    float getScaleX();

    /**
     * Get the y scaling argument
     * @return scale y
     */
    float getScaleY();

    /**
     * Set the sound
     * @param soundEffect
     */
    void setSoundEffect(const std::string &);

    /**
     * Set the texture
     * @param Texture
     */
    void setTexture(const std::string &);

    /**
     * Set the life
     * @param pv
     */
    void setPv(size_t);

    /**
     * Set the x scaling argument
     * @param scale x
     */
    void setScaleX(float);

    /**
     * Set the y scaling argument
     * @param scale y
     */
    void setScaleY(float);

    std::type_index getId() override;
};

#endif //CPP_RTYPE_2019_RENDERING_HPP
