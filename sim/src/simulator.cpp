#include "simulator/simulator.hpp"


void Simulator::addActor(double x, double y, double vx, double vy, double yaw_deg, const std::string& name, Polygon polygon)
{
    auto actor = std::make_unique<Actor>(x, y, vx, vy, yaw_deg, name, polygon);
    map_.registerActor(actor.get());
    actors_.push_back(std::move(actor));
}

void Simulator::step(const double dt)
{
    for (auto& actor : actors_)
    {
        double dx = actor->vx() * std::cos(actor->yaw()) * dt;
        double dy = actor->vy() * std::sin(actor->yaw()) * dt;
        actor->updatePosition(dx, dy);
    }
}

void Simulator::updateActors()
{
    //TODO: maybe handle collisions?
    return;
}
