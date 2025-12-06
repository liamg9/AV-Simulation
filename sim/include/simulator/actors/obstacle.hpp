#include "simulator/actors/actor.hpp"

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

class Obstacle : public Actor
{
public:
    Obstacle(double x, double y, double vx, double vy, double yaw, const std::string& name, Polygon polygon)
        : Actor(x, y, vx, vy, yaw, name, std::move(polygon)) {}

};

#endif /* OBSTACLE_HPP */
