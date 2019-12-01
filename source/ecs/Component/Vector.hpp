//
// Created by $0QU000-PL44DU4VI3C9 on 19/11/2019.
//

#ifndef CPP_RTYPE_2019_VECTOR_HPP
#define CPP_RTYPE_2019_VECTOR_HPP

#include "IComponent.hpp"

class Vector : public IComponent
{
private:
    float _z;
    float _y;
    float _x;

public:

    /**
     * Initialize the vector
     * @param x is horizontal argument
     * @param y is vertical argument
     * @param z is depth argument
     */
    Vector(float x, float y, float z = 0);
    Vector();

    /**
     * Set x argument
     * @param x
     */
    void setX(float);

    /**
     * Set y argument
     * @param y
     */
    void setY(float);

    /**
     * Set z argument
     * @param z
     */
    void setZ(float);

    /**
     * Get x argument
     * @return horizontal argument
     */
    float getX() const;

    /**
     * Get y argument
     * @return the vertical argument
     */
    float getY() const;

    /**
     * Get z argument
     * @return the depth argument
     */
    float getZ() const;
};

#endif //CPP_RTYPE_2019_VECTOR_HPP
