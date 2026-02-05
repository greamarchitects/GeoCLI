#pragma once
#include "geometry.hpp"

namespace predicates
{
    // Signed area *2 of triangle (A, B, C): positive CCW, negative = CW, 0 = Collinear
    double oriented2d(const geometry::Point& a,
                      const geometry::Point& b,
                      const geometry::Point& c);

    // Returns -1 (right), 0(on line), +1(left) for point P relative to directed line A->B
    int side_of_line(const geometry::Point& a,
                     const geometry::Point& b,
                     const geometry::Point& p,
                     double eps = 1e-12);

}