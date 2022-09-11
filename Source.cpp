#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <random>
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
class Circle : public Curve
{

public:
    Circle(int r)
    {
        rad = r;
    }
    double radius()
    {
        return rad;
    }
    XYZ curve_pnt(double t) override
    {
        XYZ point;
        point.x = rad * std::cos(t);
        point.y = rad * std::sin(t);
        point.z = 0;
        return point;
    }

    Vector curve_deriv(double t) override
    {
        Vector deriv;
        deriv.x = rad * (-std::sin(t));
        deriv.y = rad * std::cos(t);
        return deriv;
    }
private:
    int rad;
};
class Ellipse : public Curve
{

public:
    Ellipse(int c, int d)
    {
        rad_a = c;
        rad_b = d;
    }
    XYZ curve_pnt(double t) override
    {
        XYZ point;
        point.x = rad_a * std::cos(t);
        point.y = rad_b * std::sin(t);
        point.z = 0;
        return point;

    }
    Vector curve_deriv(double t) override
    {
        Vector deriv;
        deriv.x = rad_a * (-std::sin(t));
        deriv.y = rad_b * std::cos(t);
        return deriv;
    }
private:
    int rad_a;
    int rad_b;
};
class Helix : public Curve
{

public:
    Helix(int r, int s)
    {
        rad = r;
        step = s;
    }
    XYZ curve_pnt(double t) override
    {
        XYZ point;
        point.x = rad * std::cos(t);
        point.y = rad * std::sin(t);
        point.z = step * t;
        return point;
    }
    Vector curve_deriv(double t) override
    {
        Vector deriv;
        deriv.x = rad * (-std::sin(t));
        deriv.y = rad * cos(t);
        deriv.z = step;
        return deriv;
    }
private:
    int rad;
    int step;
};
int main()
{
    std::vector<Curve*> v1;
    for (int i = 0; i < 3; i++)
    {
        Circle* a = new Circle(std::rand() % 10 + 1);
        v1.push_back(a);
        Ellipse* b = new Ellipse(std::rand() % 10 + 1, std::rand() % 10 + 1);
        v1.push_back(b);
        Helix* c = new Helix(std::rand() % 10 + 1, std::rand() % 10 + 1);
        v1.push_back(c);
    }
    for (Curve* obj : v1)
    {
        XYZ point = obj->curve_pnt(M_PI_4);
        obj->curve_pnt(M_PI_4);
        std::cout << point.x << " " << point.y << " " << point.z << std::endl;
        Vector deriv = obj->curve_deriv(M_PI_4);
        obj->curve_deriv(M_PI_4);
        std::cout << deriv.x << " " << deriv.y << " " << deriv.z << std::endl;
    }
    double radsum = 0;
    std::vector<Circle*> v2;
    for (int i2 = 0; i2 < v1.size(); i2++)
    {
        Circle* cptr = dynamic_cast<Circle*>(v1[i2]);
        if (cptr != nullptr)
        {
            v2.push_back(cptr);
            radsum = radsum + cptr->radius();
        }
    }
    std::sort(v2.begin(), v2.end(),
        [](Circle* a, Circle* b)
        {
            return (a->radius() < b->radius());
        }
    );
    for (Curve* objtodel : v1)
    {
        delete objtodel;
    }
    return 0;
}