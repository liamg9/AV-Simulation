#ifndef STATE_HPP
#define STATE_HPP

struct State
{
    double x;
    double y;
    double v;           //forward velocity
    double yaw;         //radians
    double steering;    //steering angle
};

#endif /* STATE_HPP */