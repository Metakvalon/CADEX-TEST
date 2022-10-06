#pragma once
#include "Curves.h"

class CURVES_API Ellipse : public Curve
{
public:
    Ellipse(double c, double d);
    XYZ curve_pnt(double t) override;
    Vector curve_deriv(double t) override;
private:
    double rad_a;
    double rad_b;
};