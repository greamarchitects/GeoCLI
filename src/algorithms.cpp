#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Include header files
#include "algorithms.hpp"
#include "cli.hpp"
#include "geometry.hpp"
#include "predicates.hpp"

namespace 
{
    // --------- 02 ORIENTATION --------------------
    geometry::Point read_point(const std::string& name){
        geometry::Point p;
        std::cout << name << endl;
        p.x = cli::read_double(" x: ");
        p.y = cli::read_double(" y: ");
        return p;
    }

    // --------- 03 INTERSECT ----------------------
    const char* type_to_string(predicates::SegmentIntersectionType t){
        switch (t)
        {
        case predicates::SegmentIntersectionType::None : return "None";
        case predicates::SegmentIntersectionType::Proper : return "Proper (crossing)";
        case predicates::SegmentIntersectionType::Touching : return "Touching (endpoint / boundary)";
        case predicates::SegmentIntersectionType::CollinearOverlap : return "Collinear overlap";        
        }
        return  "Unknown";

    }
    
} 

namespace algorithms
{
    // -------------- 01 DISTANCE --------------------
    void run_distance_tool()
    {
        cout << "\n[Distance between points]\n";
        cout << "- a. Euclidean distance\n";
        cout << "- b. Squared distance\n";

        char choice = cli::read_choice("Choose (a/b)", "ab");

        double x1 = cli::read_double("x1: ");
        double y1 = cli::read_double("y1: ");
        double x2 = cli::read_double("x2: ");
        double y2 = cli::read_double("y2: ");

        double dx = x2 - x1;
        double dy = y2 - y1;

        double dist = sqrt(dx * dx + dy * dy);
        double dist2 = dx * dx + dy * dy;

        cout << "Distance between (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") = " << dist << endl;

        if (choice == 'a')
        {
            cout << "Euclidean distance = " << dist << endl;
        }
        else
        {
            cout << "Squared distance = " << dist2 << endl;
        }
    }

    // ---------------- 02 ORIENTATION -----------------
    void run_orientation_tool()
    {
        cout << "\n[Orientation test]\n";
        cout << "- a. Orientation of 3 Points\n";
        cout << "- b. Point relative to line AB\n";

        char choice = cli::read_choice("Choose (a/b)", "ab");

        if (choice == 'a')
        {
            const auto A = read_point("Point A");
            const auto B = read_point("Point B");
            const auto C = read_point("Point C");

            const double v = predicates::oriented2d(A, B, C);
            
            cout << "\nResult:\n";
            if (v > 0){
                cout << " Counterclockwise (CCW)\n";
            } else if (v > 0){
                cout << " Clockwise (CW)\n";
            } else {
                cout << " Collinear\n";
            }

            cout << " oriented2d value = " << v << "\n\n";
        }
        else
        {
            const auto A = read_point("Line Point A");
            const auto B = read_point("Line Point B");
            const auto P = read_point("Test Point P");

            const int side = predicates::side_of_line(A,B,P);

            cout << "\nResult:\n";
            if (side > 0){
                cout << "P is LEFT to the Line AB\n";
            }else if(side < 0){
                cout << "P is RIGHT to the Line AB\n";
            }else{
                cout << "P is ON the Line\n";
            }
            cout << "\n";
        }

    }

    // ------------- 03 INTERSECTION ------------------
    void run_segment_intersection_tool()
    {
        cout << "\n[Segment intersection]\n";
        cout << " - a. Intersect? (Yes / No)\n";
        cout << " - b. Intersection type\n";

        char choice = cli::read_choice("Chose (a/b): ","ab");

        const auto A = read_point("Segment AB - Point A");
        const auto B = read_point("Segment AB - Point B");
        const auto C = read_point("Segment CD - Point C");
        const auto D = read_point("Segment CD - Point D");

        if (choice == 'a'){
            const bool doIntersect = predicates::segment_intersect(A,B,C,D);
            cout << "\nResult: " << (doIntersect ? "Yes" : "No") << "\n\n";
        }
        else{
            const auto t = predicates::segment_intersection_type(A, B, C, D);
            cout << "\nResult: " << type_to_string(t) << "\n\n";

        }
    
    }

    // ------------- 04 AREA -------------------------
    void run_polygon_area_tool()
    {
        cout << "\n[Polygon area]\n";
        int n = cli::read_int("Number of vertices (>=3): ", 3, 1000);
        // TODO: read n points, compute shoelace area
        cout << n;
    }
}