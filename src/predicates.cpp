#include "predicates.hpp"
#include "geometry.hpp"

namespace predicates
{
    // Signed area *2 of triangle (A, B, C): positive CCW, negative = CW, 0 = Collinear
    double oriented2d(const geometry::Point& a,
                      const geometry::Point& b,
                      const geometry::Point& c)
    {
        // (b - a) x (c - a)
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    }

    // Returns -1 (right), 0(on line), +1(left) for point P relative to directed line A->B
    int side_of_line(const geometry::Point& a,
                     const geometry::Point& b,
                     const geometry::Point& p,
                     double eps)
    {
        const double v = oriented2d(a,b,p);
        if (v > eps) return +1; // Left of A -> B (CCW)
        if (v < eps) return -1; // Right of A -> B (CW)
        return 0;               // on the line (collinear)
    }

}