#include <string>
#include "polygon.hpp"

#ifndef ACTOR_HPP
#define ACTOR_HPP

class Actor
{

public:
Actor(double x, double y, double yaw, const std::string& name, const Polygon& polygon)
    : x_(x), y_(y), yaw_(yaw), name_(name), polygon_(polygon) {}

double x() const { return x_; }
double y() const { return y_; }
double yaw() const { return yaw_; }
std::string name() const { return name_; }

void updatePosition(double dx, double dy) { x_ += dx; y_ += dy; }
void setPosition(double x, double y) { x_ = x; y_ = y; }
void setYaw(double yaw) { yaw_ = yaw; }
std::vector<Vector2D> getWorldVertices() const { return polygon_.getTranslated(x_, y_, yaw_); }
void rotate(double delta_yaw);
static double normalizeAngle(double yaw_deg);
const Polygon& getLocalPolygon() const { return polygon_; }

private:
    double x_, y_, yaw_;
    std::string name_;
    Polygon polygon_;
    
};

#endif /* ACTOR_HPP */
