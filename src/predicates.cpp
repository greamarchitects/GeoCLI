#include "predicates.hpp"
#include "geometry.hpp"
#include <algorithm> // for std::min and std::max

namespace predicates
{
    //------------------ 02 ORIENTATION --------------------
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
        if (v < -eps) return -1; // Right of A -> B (CW)
        return 0;               // on the line (collinear)
    }

    //-----------------03 INTERSECT --------------------
    // Check if a point P is in line A -> B
    bool on_segment(const geometry::Point& a,
                    const geometry::Point& b,
                    const geometry::Point& p,
                    double eps)
    {
        if (side_of_line(a,b,p,eps) != 0) return false; // Not collinear
        // Check if p is within the bounding box of a and b
        return (std::min(a.x, b.x) - eps <= p.x && p.x <= std::max(a.x, b.x) + eps) &&
               (std::min(a.y, b.y) - eps <= p.y && p.y <= std::max(a.y, b.y) + eps);
    }

    // Create a class for types of Intersections
    SegmentIntersectionType segment_intersection_type(
        const geometry::Point& a, const geometry::Point& b,
        const geometry::Point& c, const geometry::Point& d,
        double eps)
    {
        int s1 = side_of_line(a,b,c,eps);
        int s2 = side_of_line(a,b,d,eps);
        int s3 = side_of_line(c,d,a,eps);
        int s4 = side_of_line(c,d,b,eps);

        if (s1 == 0 && s2 == 0) {
            // Check for collinear overlap
            if (std::max(std::min(a.x, b.x), std::min(c.x, d.x)) <= std::min(std::max(a.x, b.x), std::max(c.x, d.x)) + eps &&
                std::max(std::min(a.y, b.y), std::min(c.y, d.y)) <= std::min(std::max(a.y, b.y), std::max(c.y, d.y)) + eps) {
                return SegmentIntersectionType::CollinearOverlap;
            }
        }

        // Check if the segments touch
        if (s1 == 0 && on_segment(a,b,c,eps)) return SegmentIntersectionType::Touching;
        if (s2 == 0 && on_segment(a,b,d,eps)) return SegmentIntersectionType::Touching;
        if (s3 == 0 && on_segment(c,d,a,eps)) return SegmentIntersectionType::Touching;
        if (s4 == 0 && on_segment(c,d,b,eps)) return SegmentIntersectionType::Touching;

        // Check if they properly intersect
        if (s1 * s2 < 0 && s3 * s4 < 0) return SegmentIntersectionType::Proper; // Proper intersection

        return SegmentIntersectionType::None; // No intersection
    }

    // Check if two lines intersect
    bool segment_intersect(
        const geometry::Point& a, const geometry::Point& b,
        const geometry::Point& c, const geometry::Point& d,
        double eps
    ){
        return segment_intersection_type(a,b,c,d,eps) != SegmentIntersectionType::None;
    }
}