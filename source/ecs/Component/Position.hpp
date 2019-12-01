//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

#include "Vector.hpp"

class Position : public Vector
{
public:
    Position(double x, double y, double z = 0);
    Position(const Position&);

    std::type_index getId() override;
};

#endif //CPP_RTYPE_2019_POSITION_HPP
