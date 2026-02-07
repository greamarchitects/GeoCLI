#pragma once
#include "geometry.hpp"

namespace predicates
{
    //------------------ 02 ORIENTATION --------------------

    // Signed area *2 of triangle (A, B, C): positive CCW, negative = CW, 0 = Collinear
    double oriented2d(const geometry::Point& a,
                      const geometry::Point& b,
                      const geometry::Point& c);

    // Returns -1 (right), 0(on line), +1(left) for point P relative to directed line A->B
    int side_of_line(const geometry::Point& a,
                     const geometry::Point& b,
                     const geometry::Point& p,
                     double eps = 1e-12);

    // ----------------03 INTERSECT --------------------

    // Create a class for types of Intersections
    enum class SegmentIntersectionType{
        None,
        Proper,
        Touching,
        CollinearOverlap
    };

    // Declare : Function that gives out which type of Intersection we have
    SegmentIntersectionType segment_intersection_type(
        const geometry::Point& a, const geometry::Point& b,
        const geometry::Point& c, const geometry::Point& d,
        double eps = 1e-12
    );

    // Declare: Function to Check if two lines intersect
    bool segment_intersect(
        const geometry::Point& a, const geometry::Point& b,
        const geometry::Point& c, const geometry::Point& d,
        double eps = 1e-12
    );


    
}