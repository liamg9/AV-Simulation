#include "utils/vector2d.hpp"

#ifndef POLYGON_HPP
#define POLYGON_HPP


class Polygon
{
public:
    Polygon(std::vector<Vector2D> vertices) : vertices_(std::move(vertices)){}
    const std::vector<Vector2D>& getVertices() const { return vertices_; }
    std::vector<Vector2D> getTranslated(double origin_x, double origin_y, double yaw_deg = 0.0) const;
    std::vector<Vector2D> getAxes() const;
    Vector2D getProjection(const Vector2D& axis) const;

private:
    std::vector<Vector2D> vertices_;

};

#endif /*POLYGON_HPP*/