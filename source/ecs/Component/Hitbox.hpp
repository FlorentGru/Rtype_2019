//
// Created by $0QU000-PL44DU4VI3C9 on 30/11/2019.
//

#ifndef RTYPE_HITBOX_HPP
#define RTYPE_HITBOX_HPP

#include "IComponent.hpp"

class Hitbox : public IComponent
{
public:
    std::type_index getId() override;
    /**
     * Initialise the hitbox component
     * @param length is the component length
     * @param heigh is the component heigh
     */
    Hitbox(size_t length, size_t heigh);

    /**
     * Get Length component
     * @return the component length
     */
    size_t getLength() const;

    /**
     * Get Heigh component
     * @return the component heigh
     */
    size_t getHeigh() const;

    /**
     * Get Length component
     * @param the component length
     */
    void setLength(size_t length);


    /**
     * Set Heigh component
     * @param the component heigh
     */
    void setHeigh(size_t heigh);

private:
    size_t _length;
    size_t _heigh;
};

#endif //RTYPE_HITBOX_HPP
