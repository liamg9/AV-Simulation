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
        // for (auto& neighbor : actors_)
        // {
        //     if (isColliding(*actor, *neighbor) && actor.get() != neighbor.get())
        //     {

        //     }
        // }
    }
}

void Simulator::updateActors()
{
    //TODO: maybe handle collisions?
}

bool Simulator::isColliding(const Actor& actor1, const Actor& actor2)
{
    Polygon actor1_poly = actor1.getWorldVertices();
    Polygon actor2_poly = actor2.getWorldVertices();
    std::vector<Vector2D> actor1_axes = actor1_poly.getAxes();
    std::vector<Vector2D> actor2_axes = actor2_poly.getAxes();
    
    for (auto& axis : actor1_axes)
    {
        Vector2D p1 = actor1_poly.getProjection(axis);
        Vector2D p2 = actor2_poly.getProjection(axis);
        if (actorsOverlap(p1, p2))
        {
            return true;
        }
    }

    for (auto& axis : actor2_axes)
    {
        Vector2D p1 = actor1_poly.getProjection(axis);
        Vector2D p2 = actor2_poly.getProjection(axis);
        if (actorsOverlap(p1, p2))
        {
            return true;
        }
    }
    return false;
}

bool Simulator::actorsOverlap(const Vector2D& p1, const Vector2D& p2)
{
    if ( p1.y() < p2.x() || p2.y() < p1.x() )
    {
        return false;
    }
    return true;
}
