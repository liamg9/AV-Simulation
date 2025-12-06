#include <vector>
#include <memory>

#include "simulator/map.hpp"

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

class Simulator
{
public:
    Simulator(Map& map) : map_(map) {}
    void addActor(double x, double y, double vx, double vy, double yaw_deg, const std::string& name, Polygon polygon);
    void step(const double dt);
    static void updateActors();


private:
    Map& map_;
    std::vector<std::unique_ptr<Actor>> actors_;
};

#endif /* SIMULATOR_HPP */