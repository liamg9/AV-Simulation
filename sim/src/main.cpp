#include <iostream>
#include <vector>
#include "utils/vector2d.hpp"
#include "utils/polygon.hpp"
#include "simulator/actors/actor.hpp"
#include "simulator/map.hpp"
#include "simulator/simulator.hpp"

int main()
{
/*
Currently in progress, verifies that objects can compile without errors
and do a sanity check on the step function
*/
    std::vector<Vector2D> vehicle_shape = {
        Vector2D(-1.0, -0.5),
        Vector2D( 1.0, -0.5),
        Vector2D( 1.0,  0.5),
        Vector2D(-1.0,  0.5)
    };
    Polygon vehicle_polygon(vehicle_shape);

    Map world_map;

    Simulator sim(world_map);

    sim.addActor(0.0, 0.0, 1.0, 0.5, 0.0, "Vehicle1", vehicle_polygon);
    sim.addActor(5.0, 5.0, -0.5, 0.0, 90.0, "Vehicle2", vehicle_polygon);
    // sim.addActor(-0.25, -0.25, 0.75, 0.25, 0.0, "Vehicle3", vehicle_polygon);

    std::cout << "Before step:\n";
    std::vector<Actor*> actors = world_map.getActors();
    for (const Actor* a : actors)
    {
        std::cout << a->name() << " at (" << a->x() << ", " << a->y() << ")\n";
    }

    double dt = 0.1; // 100ms timestep
    sim.step(dt);
    

    std::cout << "\nAfter step:\n";
    for (size_t i = 0; i < actors.size(); ++i)
    {
        for (size_t j = i + 1; j < actors.size(); ++j)
        {
            const Actor* a = actors[i];
            const Actor* b = actors[j];

            if (sim.isColliding(*a, *b))
            {
                std::cout << "\n======COLLISION DETECTED between "
                        << a->name() << " and " << b->name() << " =====\n";
            }
        }
}

    return 0;
}
