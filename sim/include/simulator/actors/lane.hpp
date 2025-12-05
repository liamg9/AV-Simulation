#include "actor.hpp"

#ifndef LANE_HPP
#define LANE_HPP

class Lane : Actor
{
public:
    Lane(double x, double y, double yaw, const std::string& name, const Polygon& polygon)
        : Actor(x, y, yaw, name, polygon) {}

};

#endif /* LANE_HPP */
