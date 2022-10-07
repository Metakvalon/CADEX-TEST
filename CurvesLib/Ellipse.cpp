#include <cmath>
#include <utility>
#include <limits.h>
#include "Ellipse.h"

Ellipse::Ellipse(double a, double b)
{
    rad_a = a;
    rad_b = b;
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
    deriv.z = 0;
    return deriv;
}