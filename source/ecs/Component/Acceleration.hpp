//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_ACCELERATION_HPP
#define CPP_RTYPE_2019_ACCELERATION_HPP

#include "Vector.hpp"

class Acceleration : public Vector
{
public:
    Acceleration(float x, float y, float z = 0);
    std::type_index getId() override;
};

#endif //CPP_RTYPE_2019_ACCELERATION_HPP
