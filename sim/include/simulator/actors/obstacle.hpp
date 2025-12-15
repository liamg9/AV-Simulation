#include "simulator/actors/actor.hpp"

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

class Obstacle : public Actor
{
public:
    Obstacle(double x, double y, double v, double yaw, const std::string& name, Polygon polygon)
        : Actor(x, y, v, yaw, name, std::move(polygon)) {}

};

#endif /* OBSTACLE_HPP */
