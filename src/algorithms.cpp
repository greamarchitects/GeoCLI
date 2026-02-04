#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Include header files
#include "algorithms.hpp"
#include "cli.hpp"
#include "geometry.hpp"
#include "predicates.hpp"

namespace algorithms
{
    //
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

    //
    void run_orientation_tool()
    {
        cout << "\n[Orientation test]\n";
        // TODO: read A,B,C and call predicates::orientation(...)
    }

    //
    void run_segment_intersection_tool()
    {
        cout << "\n[Segment intersection]\n";
        // TODO: read segments and call predicates/algorithms
    }

    //
    void run_polygon_area_tool()
    {
        cout << "\n[Polygon area]\n";
        int n = cli::read_int("Number of vertices (>=3): ", 3, 1000);
        // TODO: read n points, compute shoelace area
        cout << n;
    }
}