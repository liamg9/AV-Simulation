#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#include "simulator/map.hpp"
#include "simulator/simulator.hpp"
#include "simulator/actors/vehicles/car.hpp"

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

    State init_state_actor1 {0.0, 0.0, 1.0, 0.0, 0.0};
    // State init_state_actor2 {5.0, 5.0, 0.5, 0.0, 0.0};
    State init_state_actor3 = {0.5, 0.5, 1.0, 0.0, 0.0};

    std::vector<Vector2D> waypoints_one = {
        {5.0, 2.0}, {7.5, 0.0}, {10.0, -2.0}, {12.5, 0.0}, {15.0, 2.0}
    };
    // std::vector<Vector2D> waypoints_two = {{7,7}, {8,8}};
    // std::vector<Vector2D> waypoints_three = {{1,1}, {2,2}};
    std::string v1 = "Vehicle1";
    std::string v2 = "Vehicle2";
    std::string v3 = "Vehicle3";
    double wheelbase = 2.7;


    auto car_one = std::make_unique<Car> (init_state_actor1, v1, vehicle_polygon, wheelbase, waypoints_one);
    // auto car_two = std::make_unique<Car> (init_state_actor2, v2, vehicle_polygon, wheelbase, waypoints_two);
    auto car_three = std::make_unique<Car> (init_state_actor3, v3, vehicle_polygon, wheelbase, waypoints_one);

    sim.addActor(std::move(car_one));
    // sim.addActor(std::move(car_two));
    sim.addActor(std::move(car_three));

    std::cout << "Before step:\n";
    std::vector<Actor*> actors = world_map.getActors();
    for (const Actor* a : actors)
    {
        std::cout << a->name() << " at (" << a->state().x << ", " << a->state().y << ")\n";
    }

    double dt = 0.1; // 100ms timestep
    double time = 30; // 1 second of total time in sim
    for (double i = 0; i < time; i += 0.1)
    {
        sim.step(dt);
        // std::cout << "----positions at time = " << i << "----\n";
        for (const Actor* a : actors)
        {
            // std::cout << a->name() << " at (" << a->state().x << ", " << a->state().y << ")\n";
            std::cout << a->name() << " " << a->state().x << ", " << a->state().y << "\n";
        }
    }

    std::cout << "\nAfter step:\n";

    for (const Actor* a : actors)
    {
        std::cout << a->name() << " at (" << a->state().x << ", " << a->state().y << ")\n";
    }

    // for (size_t i = 0; i < actors.size(); ++i)
    // {
    //     for (size_t j = i + 1; j < actors.size(); ++j)
    //     {
    //         const Actor* a = actors[i];
    //         const Actor* b = actors[j];

    //         if (sim.isColliding(*a, *b))
    //         {
    //             std::cout << "\n======COLLISION DETECTED between "
    //                     << a->name() << " and " << b->name() << " =====\n";
    //             return 0;
    //         }
    //     }
    // }
    std::cout << "\n======SIM FINISHED=======\n";

    return 0;
}
