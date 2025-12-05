#include <vector>

#include "map.hpp"

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

class Simulator
{
public:
    Simulator(Map& map) : map_(map) {}
    void step(double dt);
    void updateActors();
    void addActor(Actor* new_actor);

private:
    Map& map_;

};

#endif /* SIMULATOR_HPP */