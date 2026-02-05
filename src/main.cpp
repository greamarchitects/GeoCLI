#include <iostream>
#include <limits>
using namespace std;

// Include header files
#include "cli.hpp"
#include "geometry.hpp"
#include "predicates.hpp"
#include "algorithms.hpp"
#include "io.hpp"

// Function to show the Main Menu
static void displayMenu()
{
    cout << "\n============ GEOMETRY COMMAND LINE INTERFACE (GeoCLI) =============" << endl;
    cout << "\n1. Compute Distance between points" << endl;
    cout << "--------------------------------------" << endl;
    cout << "- a. Euclidean distance " << endl;
    cout << "- b. Squared distance" << endl;
    cout << "\n2. Orientation Test" << endl;
    cout << "--------------------------------------" << endl;
    cout << "- a. Orientation of 3 points" << endl;
    cout << "- b. Point relative to line AB" << endl;
    cout << "\n3. Line Segment Intersection" << endl;
    cout << "--------------------------------------" << endl;
    cout << "- a. Intersect" << endl;
    cout << "- b. Intersection type" << endl;
    cout << "\n4. Polygon Area" << endl;
    cout << "--------------------------------------" << endl;
    cout << "- a. Polygon area (Shoelace)" << endl;
    cout << "- b. Polygon orientation (CW/CCW) + perimeter" << endl;
    cout << "\n5. Exit" << endl
         << endl;
}

int main()
{

    bool running = true;

    while (running)
    {
        displayMenu();
        int choice;

        cout << " Select an option (1 - 5): ";
        while (true)
        {
            // int choice = cli::read_int("Select an option (1 - 5): ", 1, 5);
            if (cin >> choice && choice >= 1 && choice <= 5)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cout << "Invalid input. Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 1:
            algorithms::run_distance_tool();
            break;
        case 2:
            algorithms::run_orientation_tool();
            break;
        case 3:
            algorithms::run_segment_intersection_tool();
            break;
        case 4:
            algorithms::run_polygon_area_tool();
            break;
        case 5:
            running = false;
            cout << "Thanks for using GeoCLI!";
            break;

        default:
            break;
        }
    }
    return 0;
}