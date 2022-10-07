#pragma once
#include "Curve.h"

class CURVESLIB_API Ellipse : public Curve
{
public:
    Ellipse(double a, double b);
    XYZ curve_pnt(double t) override;
    Vector curve_deriv(double t) override;
private:
    double rad_a;
    double rad_b;
};