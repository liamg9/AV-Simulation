#include <string>
#include "utils/polygon.hpp"

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor
{

public:
    Actor(double x, double y, double vx, double vy, double yaw, const std::string& name, Polygon polygon)
        : x_(x), y_(y), vx_(vx), vy_(vy),yaw_(yaw), name_(name), polygon_(std::move(polygon)) {}

    // getters
    double x() const { return x_; }
    double y() const { return y_; }
    double vx() const { return vx_; }
    double vy() const { return vy_; }
    double yaw() const { return yaw_; }
    const std::string& name() const { return name_; }
    const Polygon& getLocalPolygon() const { return polygon_; }
    std::vector<Vector2D> getWorldVertices() const { return polygon_.getTranslated(x_, y_, yaw_); }

    void updatePosition(double dx, double dy) { x_ += dx; y_ += dy; }
    void setPosition(double x, double y) { x_ = x; y_ = y; }
    void setYaw(double yaw) { yaw_ = yaw; }
    
    void rotate(double delta_yaw);
    static double normalizeAngle(double yaw_deg);
    

private:
    double x_, y_, vx_, vy_, yaw_;
    std::string name_;
    Polygon polygon_;
    
};

#endif /* ACTOR_HPP */
