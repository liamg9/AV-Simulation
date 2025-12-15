#include <vector>
#include <memory>
#include <set>

#include "simulator/map.hpp"

#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

class Simulator
{
public:
    Simulator(Map& map) : map_(map) {}
    void addActor(std::unique_ptr<Actor> actor);
    void step(const double dt);
    bool isColliding(const Actor& actor1, const Actor& actor2);
    void updateHeading(Actor& actor, std::vector<Vector2D>& waypoints);
    void detectCollisions();
    void resolveCollisions();

private:
    bool actorsOverlap(const Vector2D& p1, const Vector2D& p2);
    Map& map_;
    std::vector<std::unique_ptr<Actor>> actors_;
    std::set<std::pair<const Actor*, const Actor*>> collisions_, previousCollisions_;
    void updateActors(double dt);
};

#endif /* SIMULATOR_HPP */