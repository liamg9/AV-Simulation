#include "simulator/actors/actor.hpp"

#ifndef LANE_HPP
#define LANE_HPP

class Lane : public Actor
{
public:
    Lane(double x, double y, double vx, double vy, double yaw, const std::string& name, Polygon polygon)
        : Actor(x, y, vx, vy, yaw, name, std::move(polygon)) {}

};

#endif /* LANE_HPP */
