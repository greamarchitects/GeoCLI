/**
 * @file io.cpp
 * @brief Utility functions for handling input and output operations
 *        related to coordinates in a computational geometry context.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <filesystem>

#include "io.hpp"
#include "geometry.hpp"
#include "cli.hpp"

namespace io
{
    // ------------------------------------------------------------
    // Helper: trim whitespace
    // ------------------------------------------------------------
    static std::string trim_copy(std::string s)
    {
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front())))
            s.erase(s.begin());
        while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back())))
            s.pop_back();
        return s;
    }

    // ------------------------------------------------------------
    // Read coordinates from simple XY text file
    // ------------------------------------------------------------
    void readCoordinatesFromFile(const std::string &fileName)
    {
        std::ifstream inputFile(fileName);
        if (!inputFile)
        {
            std::cerr << "Error: Could not open file " << fileName << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            double x, y;
            if (iss >> x >> y)
            {
                std::cout << "Point: (" << x << ", " << y << ")\n";
            }
            else
            {
                std::cerr << "Invalid line format: " << line << '\n';
            }
        }
    }

    // ------------------------------------------------------------
    // Write points to file
    // ------------------------------------------------------------
    void writeCoordinatesToFile(const std::string &fileName,
                                const std::string &points)
    {
        std::ofstream outputFile(fileName);
        if (!outputFile)
        {
            std::cerr << "Error: Could not open file " << fileName << std::endl;
            return;
        }
        outputFile << points;
    }

    // ------------------------------------------------------------
    // Read XY polygon file
    // ------------------------------------------------------------
    std::vector<geometry::Point> read_point_xy(const std::string &fileName)
    {
        std::ifstream in(fileName);
        if (!in)
            throw std::runtime_error("Could not open file: " + fileName);

        std::vector<geometry::Point> points;
        std::string line;

        while (std::getline(in, line))
        {
            line = trim_copy(line);
            if (line.empty() || line[0] == '#')
                continue;

            std::istringstream iss(line);
            geometry::Point p;

            if (!(iss >> p.x >> p.y))
                throw std::runtime_error("Invalid line (expected: x y): " + line);

            points.push_back(p);
        }

        if (points.size() < 3)
            throw std::runtime_error("Need at least 3 points for a polygon");

        return points;
    }

    // ------------------------------------------------------------
    // Read CSV polygon file
    // ------------------------------------------------------------
    std::vector<geometry::Point> read_points_csv(const std::string &fileName)
    {
        std::ifstream in(fileName);
        if (!in)
            throw std::runtime_error("Could not open file: " + fileName);

        std::vector<geometry::Point> points;
        std::string line;
        bool first = true;

        while (std::getline(in, line))
        {
            line = trim_copy(line);
            if (line.empty())
                continue;

            if (first)
            {
                first = false;
                if (line == "x,y") // FIX: exact header match only
                    continue;
            }

            std::istringstream iss(line);
            geometry::Point p;
            char comma;

            iss >> std::ws; // FIX: ignore leading whitespace
            if (!(iss >> p.x >> comma >> p.y) || comma != ',')
                throw std::runtime_error("Invalid csv line (expected: x,y): " + line);

            points.push_back(p);
        }

        if (points.size() < 3)
            throw std::runtime_error("Need at least 3 points for a polygon");

        return points;
    }

    // ------------------------------------------------------------
    // WKT (not implemented)
    // ------------------------------------------------------------
    std::vector<geometry::Point> read_points_wkt(const std::string &)
    {
        throw std::runtime_error("WKT parsing not implemented yet.");
    }

    // ------------------------------------------------------------
    // Prompt polygon points
    // ------------------------------------------------------------
    std::vector<geometry::Point> prompt_polygon_points()
    {
        std::cout << "Input polygon:\n";
        std::cout << "- a. Manual entry\n";
        std::cout << "- b. Read from file (.txt xy, or .csv x,y)\n";

        int choice = cli::read_choice("Choose a or b: ", "ab");

        if (choice == 'a')
        {
            int n = cli::read_int(
                "Enter number of points (>=3): ", 3, 1000);

            std::vector<geometry::Point> poly;
            poly.reserve(static_cast<size_t>(n));

            for (int i = 0; i < n; ++i)
            {
                geometry::Point p;
                std::cout << "Vertex " << (i + 1) << ":\n";
                p.x = cli::read_double("  x: ");
                p.y = cli::read_double("  y: ");
                poly.push_back(p);
            }
            return poly;
        }
        else
        {
            std::string path;
            std::cout << "File path: ";
            std::getline(std::cin, path);

            if (path.empty())
                throw std::runtime_error("File path cannot be empty");

            if (path.size() >= 4 && path.substr(path.size() - 4) == ".csv")
                return read_points_csv(path);

            return read_point_xy(path);
        }
    }

} // namespace io
