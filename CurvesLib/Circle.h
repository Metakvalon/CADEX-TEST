#pragma once
#include "Curves.h"

class CURVES_API Circle : public Curve
{
public:
    Circle(double r);
    double radius();
    XYZ curve_pnt(double t) override;
    Vector curve_deriv(double t) override;
private:
    double rad;
};