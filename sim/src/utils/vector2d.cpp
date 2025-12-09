#include "utils/vector2d.hpp"
#include <cmath>

void Vector2D::normalize()
{
    double magnitude = std::sqrt( std::pow(x_, 2) + std::pow(y_, 2) );
    if (magnitude > 0)
    {
        x_ /= magnitude;
        y_ /= magnitude;
    }
}
