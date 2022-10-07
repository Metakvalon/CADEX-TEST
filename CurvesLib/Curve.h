#pragma once
#include <iostream>
#ifdef CURVESLIB_EXPORTS
#define CURVESLIB_API __declspec(dllexport)
#else
#define CURVESLIB_API __declspec(dllimport)
#endif

struct XYZ
{
    double x = 0;
    double y = 0;
    double z = 0;
};
using Vector = XYZ;

class Curve
{
public:
    virtual XYZ curve_pnt(double t) = 0;
    virtual Vector curve_deriv(double t) = 0;
};






