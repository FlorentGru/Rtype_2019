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
    Hitbox(size_t length, size_t heigh);

    size_t getLength() const;
    size_t getHeigh() const;

    void setLength(size_t length);
    void setHeigh(size_t heigh);

private:
    size_t _length;
    size_t _heigh;
};

#endif //RTYPE_HITBOX_HPP
