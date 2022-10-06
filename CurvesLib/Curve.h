#pragma once

#ifdef CURVESLIB_EXPORTS
#define CURVES_API __declspec(dllexport)
#else
#define CURVES_API __declspec(dllimport)
#endif


#define M_PI       3.14159265358979323846
#define M_PI_2     1.57079632679489661923
#define M_PI_4     0.785398163397448309616
#include <cmath>


struct XYZ
{
    double x = 0;
    double y = 0;
    double z = 0;
};
struct Vector
{
    double x = 0;
    double y = 0;
    double z = 0;
};
class Curve
{
public:
    virtual XYZ curve_pnt(double t) = 0;
    virtual Vector curve_deriv(double t) = 0;
};




