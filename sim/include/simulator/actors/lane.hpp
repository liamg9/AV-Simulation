#include "simulator/actors/actor.hpp"

#ifndef LANE_HPP
#define LANE_HPP

class Lane : public Actor
{
public:
    Lane(State& state, const std::string& name, Polygon polygon)
        : Actor(state, name, std::move(polygon)) {}

};

#endif /* LANE_HPP */
