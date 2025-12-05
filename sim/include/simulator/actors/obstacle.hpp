#include "actor.hpp"

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

class Obstacle : Actor
{
public:
    Obstacle(double x, double y, double yaw, const std::string& name, const Polygon& polygon)
        : Actor(x, y, yaw, name, polygon) {}

};

#endif /* OBSTACLE_HPP */
