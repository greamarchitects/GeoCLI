#include <cmath>
#include <vector>

#include "geometry.hpp"
#include "geometry_primitives.hpp"

namespace geometry_primitives{

    // Calculate signed area
    double signed_area2(const std::vector<geometry::Point>& poly){
        double area = 0.0;
        const size_t n = poly.size();
        for(size_t i = 0; i < n; ++i){
            const geometry::Point& p1 = poly[i];
            const geometry::Point& p2 = poly[(i + 1) % n]; // Wrap around to the first point
            area += (p1.x * p2.y - p2.x * p1.y);
        }
        return area;
    } 

    // Calculate polygon area
    double polygon_area(const std::vector<geometry::Point>& poly){
        return std::abs(signed_area2(poly)) / 2.0;
    }


    // Calculate polygon perimeter
    double polygon_perimeter(const std::vector<geometry::Point>& poly){
        double perimeter = 0.0;
        const size_t n = poly.size();
        for(size_t i = 0; i < n; ++i){
            const geometry::Point& p1 = poly[i];
            const geometry::Point& p2 = poly[(i + 1) % n]; // Wrap around to the first point
            perimeter += std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        }
        return perimeter;
    }



    // Give out the Polygon Orientation Label (CCW - Counter Clockwise, CW - Clockwise, Degenerate or Collinear - Area 0)
    Polygon_Orientation polygon_orientation(const std::vector<geometry::Point>& poly, double eps){
        const double area2 = signed_area2(poly);
        if (area2 > eps) return Polygon_Orientation::CCW;
        else if (area2 < -eps) return Polygon_Orientation::CW;
        else return Polygon_Orientation::Degenerate;
    }

    
}