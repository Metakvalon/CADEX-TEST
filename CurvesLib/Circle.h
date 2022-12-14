#pragma once
#include "Curve.h"

class CURVESLIB_API Circle : public Curve
{
public:
    Circle(double r);
    double radius();
    XYZ curve_pnt(double t) override;
    Vector curve_deriv(double t) override;
private:
    double rad;
};