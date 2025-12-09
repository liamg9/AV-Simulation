#include <vector>

#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

class Vector2D
{
public:
    Vector2D(double x, double y) : x_(x), y_(y){}
    double x() const { return x_; }
    double y() const { return y_; }
    Vector2D operator-(const Vector2D& other) const { return Vector2D(x_ - other.x_, y_ - other.y()); }
    Vector2D perp() const { return Vector2D(-y_, x_);}
    double dot(const Vector2D& other) const { return x_ * other.x_ + y_ * other.y_; }
    void normalize();
    bool overlaps(const Vector2D& other) const;

    //TODO: use projection struct instead of Vector2D
    struct Projection{ double min; double max; };

private:
    double x_;
    double y_;

};

#endif /* VECTOR_2D_HPP */