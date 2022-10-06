#include <utility>
#include <limits.h>
#include "Circle.h"

Circle::Circle(double r)
{
    rad = r;
}
double Circle::radius()
{
    return rad;
}
XYZ Circle::curve_pnt(double t)
{
    XYZ point;
    point.x = rad * std::cos(t);
    point.y = rad * std::sin(t);
    point.z = 0;
    return point;
}
Vector Circle::curve_deriv(double t)
{
    Vector deriv;
    deriv.x = rad * (-std::sin(t));
    deriv.y = rad * std::cos(t);
    return deriv;
}
