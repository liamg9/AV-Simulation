#include <string>
#include "utils/polygon.hpp"
#include "utils/state.hpp"

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor // Base class for static (lanes, obstacles) and dynamic (moving cars, peds) actors
{

public:
    Actor(const State& initial_state, const std::string& name, Polygon polygon)
        : state_(initial_state), name_(name), polygon_(std::move(polygon)) {}
    virtual ~Actor() = default;   //silence compiler warning
    // getters
    const State& state() const { return state_; }
    const std::string& name() const { return name_; }
    const Polygon& getLocalPolygon() const { return polygon_; }
    const std::vector<Vector2D> getWorldVertices() const { return polygon_.getTranslated(state_.x, state_.y, state_.yaw); }

    //overridable update function so that cars can use kinematics models while static actors don't
    virtual void update(double dt) = 0; //TODO: update everywhere
    void setState(State& state);
    void setVelocity(double v) { state_.v = v; }
    
    void rotate(double delta_yaw);
    static double normalizeAngle(double yaw_deg); //TODO: normalizeAngle() mixes degrees and radians

    

private:
    State state_;
    std::string name_;
    Polygon polygon_;
    
};

#endif /* ACTOR_HPP */


/*
TODO:
refactor actor to use State struct instead of x, y, yaw, ...
implement bicycle model
*/