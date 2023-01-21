#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
// slave2
int main()
{
    enum
    {
        circle_shp,
        ellipse_shp,
        helix_shp
    };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 10.0);
    std::uniform_int_distribution<> dis_shp(circle_shp, helix_shp);
    std::vector<std::shared_ptr<Curve>> v1;

    for (int i = 0; i < 20; i++)
    {
        switch (int shp = dis_shp(gen))
        {
            case circle_shp:
            {
                v1.push_back(std::make_shared<Circle>(dis(gen)));
                break;
            }

            case ellipse_shp:
            {
                v1.push_back(std::make_shared<Ellipse>(dis(gen), dis(gen)));
                break;
            }

            case helix_shp:
            {
                v1.push_back(std::make_shared<Helix>(dis(gen), dis(gen)));
                break;
            }
        }
    }
    for (std::shared_ptr<Curve> obj : v1)
    {
        XYZ point = obj->curve_pnt(M_PI_4);
        std::cout << point.x << " " << point.y << " " << point.z << std::endl;
        Vector deriv = obj->curve_deriv(M_PI_4);
        std::cout << deriv.x << " " << deriv.y << " " << deriv.z << std::endl;
        std::cout << "\n" << std::endl;
    }
    
    double radsum = 0;
    std::vector<std::shared_ptr<Circle>> v2;
    
    for (int i = 0; i < v1.size(); i++)
    {
        std::shared_ptr<Circle> cptr = std::dynamic_pointer_cast<Circle>(v1[i]);
        if (cptr != nullptr)
        {
            v2.push_back(cptr);
        }
    }

#pragma omp parallel for reduction(+:radsum)
    for (int i = 0; i < v2.size(); i++)
    {
        radsum = radsum + v2[i]->radius();
    }
    
    std::sort(v2.begin(), v2.end(),
        [](std::shared_ptr<Circle> a, std::shared_ptr<Circle> b)
        {
            return (a->radius() < b->radius());
        }
    );
    return 0;
}