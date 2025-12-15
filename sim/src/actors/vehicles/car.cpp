#include "simulator/actors/vehicles/car.hpp"
#include <cmath>
#include <algorithm>

 void Car::update(double dt)
{
    updateSteeringFromWaypoint();
    updateKinematics(dt);
}

void Car::updateSteeringFromWaypoint()
{
    // Bicycle model (see https://thomasfermi.github.io/Algorithms-for-Automated-Driving/Control/BicycleModel.html)
    // Assumes wheel slip is 0
    if (wp_idx_ >= waypoints_.size())
    {
        setVelocity(0.0);
        steeringAngle_ = 0.0;
        return;
    }

    Vector2D curr_wp = waypoints_[wp_idx_];
    double dx = curr_wp.x() - state().x;
    double dy = curr_wp.y() - state().y;
    double dist = std::sqrt(dx*dx + dy*dy);

    if (dist < 0.5) //if within 0.5 of the waypoint, consider done and move onto the next
    {
        wp_idx_++;
        return;
    }

    double target_heading = std::atan2(dy, dx);
    double heading_error = target_heading - state().yaw;

    while (heading_error > M_PI)  heading_error -= 2 * M_PI;
    while (heading_error < -M_PI) heading_error += 2 * M_PI;

    steeringAngle_ = std::atan(2.0 * wheelBase_ * std::sin(heading_error) / dist);

    // Steering saturation (actuator limit)
    const double max_steering = M_PI / 4.0; // 45 degrees TODO: lower??

    if (steeringAngle_ > max_steering)
    {
        steeringAngle_ = max_steering;
    }
    else if (steeringAngle_ < -max_steering)
    {
        steeringAngle_ = -max_steering;
    } 
}

void Car::updateKinematics(double dt)
{
    if (state().v == 0.0)
        return;

    double dx = state().v * std::cos(state().yaw) * dt;
    double dy = state().v * std::sin(state().yaw) * dt;
    double dyaw = (state().v / wheelBase_) * std::tan(steeringAngle_) * dt;

    State d_state;
    d_state.x = dx;
    d_state.y = dy;
    d_state.yaw = dyaw;
    d_state.v = 0.0;
    d_state.steering = 0.0;

    setState(d_state);
}