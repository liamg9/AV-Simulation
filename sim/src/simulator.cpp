#include "simulator/simulator.hpp"
#include <iostream>


void Simulator::addActor(std::unique_ptr<Actor> actor)
{
    map_.registerActor(actor.get());
    actors_.push_back(std::move(actor));
}

void Simulator::step(const double dt)
{
    updateActors(dt);       // motion model only
    detectCollisions();     // geometry only
    resolveCollisions();    // behavior / logging
}

void Simulator::updateActors(double dt)
{
    for (auto& actor : actors_)
    {
        actor->update(dt);
    }

}

bool Simulator::isColliding(const Actor& actor1, const Actor& actor2)
{
    Polygon actor1_poly (actor1.getWorldVertices());
    Polygon actor2_poly (actor2.getWorldVertices());
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
    if ( p1.y() < p2.x() || p2.y() < p1.x() )   //TODO: create struct to change .x() and .y() to .min() and .max()
    {
        return false;
    }
    return true;
}

void Simulator::detectCollisions()
{
    collisions_.clear();

    for (size_t i = 0; i < actors_.size(); ++i)
    {
        for (size_t j = i + 1; j < actors_.size(); ++j)
        {
            if (isColliding(*actors_[i], *actors_[j]))
            {
                const Actor* a = actors_[i].get();
                const Actor* b = actors_[j].get();
                auto pair = (a < b) ? std::make_pair(a, b) : std::make_pair(b, a);
                collisions_.insert(pair);
            }
        }
    }
}

void Simulator::resolveCollisions()
//TODO: add failsafe, logging or other logging features in the future
{
    std::set<std::pair<const Actor*, const Actor*>> currentCollisions;

    for (auto& [a, b] : collisions_)
    {
        //(A,B) == (B,A)
        auto pair = std::minmax(a, b);
        currentCollisions.insert(pair);

        if (previousCollisions_.find(pair) == previousCollisions_.end())
        {
            // NEW collision detected
            std::cout << "NEW COLLISION: "
                      << a->name() << " <-> "
                      << b->name() << "\n";
            //TODO: handle the collision in a helper (ex: handleNewCollision(a, b);)
        }
    }

    // Update previous collisions for the next step
    previousCollisions_ = std::move(currentCollisions);
}
