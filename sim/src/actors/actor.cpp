#include "simulator/actors/actor.hpp"


void Actor::setState(State& d_state)
{
    state_.x += d_state.x;
    state_.y += d_state.y;
    state_.v += d_state.v;
    state_.yaw += d_state.yaw;
    state_.steering += d_state.steering;
}

void Actor::rotate(double delta_yaw)
{
    state_.yaw = normalizeAngle(delta_yaw + state_.yaw);
}

double Actor::normalizeAngle(double yaw_rad)
{
    while (yaw_rad > M_PI) yaw_rad -= 2 * M_PI;
    while (yaw_rad < M_PI) yaw_rad += 2 * M_PI;
    return yaw_rad;
}
