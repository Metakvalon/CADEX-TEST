#pragma once
#include "Curve.h"

class CURVESLIB_API Helix : public Curve
{
public:
    Helix(double r, double s);
    XYZ curve_pnt(double t) override;
    Vector curve_deriv(double t) override;
private:
    double rad;
    double step;
};