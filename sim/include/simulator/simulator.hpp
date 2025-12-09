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
    bool isColliding(const Actor& actor1, const Actor& actor2);

private:
    bool actorsOverlap(const Vector2D& p1, const Vector2D& p2);
    Map& map_;
    std::vector<std::unique_ptr<Actor>> actors_;
    void updateActors();
};

#endif /* SIMULATOR_HPP */