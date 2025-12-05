#include <vector>

#ifndef VECTOR_2D_HPP
#define VECTOR_2D_HPP

class Vector2D
{
public:
    Vector2D(double x, double y) : x_(x), y_(y){}
    double x() const { return x_; }
    double y() const { return y_; }

private:
    double x_;
    double y_;

};

#endif /* VECTOR_2D_HPP */