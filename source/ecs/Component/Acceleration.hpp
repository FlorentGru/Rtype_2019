//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_ACCELERATION_HPP
#define CPP_RTYPE_2019_ACCELERATION_HPP

#include "AVector.hpp"

class Acceleration : public AVector
{
    Acceleration(double x, double y, double z);
    std::type_index getId();
};

#endif //CPP_RTYPE_2019_ACCELERATION_HPP
