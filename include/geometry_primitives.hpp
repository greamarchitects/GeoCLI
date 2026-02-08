#pragma once
#include <vector>
#include "geometry.hpp"

namespace geometry_primitives{
    double signed_area2(const std::vector<geometry::Point>& poly);
    double polygon_area(const std::vector<geometry::Point>& poly);
    double polygon_perimeter(const std::vector<geometry::Point>& poly);

    enum class Polygon_Orientation{CW, CCW, Degenerate};
    Polygon_Orientation polygon_orientation(const std::vector<geometry::Point>& poly, double eps = 1e-12);
}
