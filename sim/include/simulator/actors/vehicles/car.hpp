#include "simulator/actors/actor.hpp"

#ifndef CAR_HPP
#define CAR_HPP

class Car : public Actor
{
public:
    Car(State& state, std::string& name, Polygon polygon, double& wheelBase, std::vector<Vector2D>& waypoints, double steeringAngle = 0.0) : 
    Actor(state, name, std::move(polygon)), wheelBase_(wheelBase), waypoints_(waypoints), steeringAngle_(steeringAngle) {}
    void update(double dt) override;
    void updateSteeringFromWaypoint();
    void updateKinematics(double dt);

private:
    double wheelBase_;      // distance from front wheel to back wheel
    double steeringAngle_;  // angle the front wheel rotates during turns (0 when perfectly straight)
    std::vector<Vector2D> waypoints_;
    int wp_idx_ = 0;

};

#endif /* CAR_HPP */