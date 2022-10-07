#include <cmath>
#include <utility>
#include <limits.h>
#include "Ellipse.h"

Ellipse::Ellipse(double c, double d)
{
    rad_a = c;
    rad_b = d;
}

XYZ Ellipse::curve_pnt(double t)
{
    XYZ point;
    point.x = rad_a * std::cos(t);
    point.y = rad_b * std::sin(t);
    point.z = 0;
    return point;

}
Vector Ellipse::curve_deriv(double t)
{
    Vector deriv;
    deriv.x = rad_a * (-std::sin(t));
    deriv.y = rad_b * std::cos(t);
    return deriv;
}
