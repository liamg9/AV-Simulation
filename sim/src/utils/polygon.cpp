#include "utils/polygon.hpp"
#include <algorithm>
#include <cmath>

std::vector<Vector2D> Polygon::getTranslated(double origin_x, double origin_y, double yaw_deg) const
{
    std::vector<Vector2D> moved_vertices;
    moved_vertices.reserve(vertices_.size());

    double yaw_rad = yaw_deg * M_PI / 180.0;    //convert to radians for std::sin and std::cos
    double cos_yaw = std::cos(yaw_rad);
    double sin_yaw = std::sin(yaw_rad);

    for (const auto& vertex : vertices_)
    {
        double x_rot = vertex.x() * cos_yaw - vertex.y() * sin_yaw;
        double y_rot = vertex.x() * sin_yaw + vertex.y() * cos_yaw;

        double x_world = origin_x + x_rot;
        double y_world = origin_y + y_rot;

        moved_vertices.emplace_back(x_world, y_world);
    }

    return moved_vertices;
}

std::vector<Vector2D> Polygon::getAxes() const
{
    std::vector<Vector2D> axes;
    for (size_t i = 0; i < vertices_.size(); i++)
    {
        size_t next = (i + 1) % vertices_.size();
        Vector2D edge = vertices_[next] - vertices_[i];
        Vector2D axis = edge.perp();
        axis.normalize();
        axes.push_back(axis);
    }
    return axes;
}

Vector2D Polygon::getProjection(const Vector2D& axis) const
{
    double min = axis.dot(vertices_[0]);
    double max = min;
    for(auto& vertex : vertices_)
    {
        double projection = axis.dot(vertex);
        min = std::min(projection, min);
        max = std::max(projection, max);
    }
    Vector2D proj(min, max);
    return proj;
}
