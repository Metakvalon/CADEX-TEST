#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>
#include <limits.h>
#include "Helix.h"

Helix::Helix(double r, double s)
{
    rad = r;
    step = s;
}

XYZ Helix::curve_pnt(double t)
{
    XYZ point;
    point.x = rad * std::cos(t);
    point.y = rad * std::sin(t);
    point.z = (step * t) / (2 * M_PI);
    return point;

}
Vector Helix::curve_deriv(double t)
{
    Vector deriv;
    deriv.x = rad * (-std::sin(t));
    deriv.y = rad * cos(t);
    deriv.z = step / (2 * M_PI);
    return deriv;
}