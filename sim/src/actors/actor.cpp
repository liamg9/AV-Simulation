#include "simulator/actors/actor.hpp"


void Actor::rotate(double delta_yaw)
{
    yaw_ = normalizeAngle(delta_yaw + yaw_);
}

double Actor::normalizeAngle(double yaw_deg)
{
    while (yaw_deg > 180.0) yaw_deg -= 360.0;
    while (yaw_deg < -180.0) yaw_deg += 360.0;
    return yaw_deg;
}
