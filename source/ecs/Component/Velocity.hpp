//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_VELOCITY_HPP
#define CPP_RTYPE_2019_VELOCITY_HPP

#include "AVector.hpp"

class Velocity : public AVector
{
public:
    Velocity(double x, double y, double z);
    std::type_index getId() override;
};


#endif //CPP_RTYPE_2019_VELOCITY_HPP
