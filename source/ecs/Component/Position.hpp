//
// Created by $0QU000-PL44DU4VI3C9 on 20/11/2019.
//

#ifndef CPP_RTYPE_2019_POSITION_HPP
#define CPP_RTYPE_2019_POSITION_HPP

#include "AVector.hpp"

class Position : public AVector
{
public:
    Position(double x, double y, double z);

    std::type_index getId() override;
};

#endif //CPP_RTYPE_2019_POSITION_HPP
