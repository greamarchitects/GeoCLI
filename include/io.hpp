#pragma once
#include <string>
#include <vector>

#include "geometry.hpp"

namespace io{
/**
 * @brief Reads coordinates from a specified file and prints them to the console.
 * @param fileName The name of the file to read coordinates from.
 */
void readCoordinatesFromFile(const std::string& fileName);

/**
 * @brief Writes a string of points to a specified file.
 * @param fileName The name of the file to write coordinates to.
 * @param points A string containing the points to be written to the file.
 */
void writeCoordinatesToFile(const std::string& fileName, const std::string& points);

/**
 * @brief Prompts the user to input coordinates or provide a file path for input.
 */
void getUserCoordinates();

/**
 * @brief Reads points from a string containing x and y coordinates.
 * @param input A string containing the coordinates in the format "x1 y1\nx2 y2\n...".
 * @return A vector of Point objects read from the string.
 */
std::vector<geometry::Point> read_point_xy(const std::string& input);

/**
 * @brief Reads points from a CSV file where each line contains x and y coordinates.
 * @param file_name The name of the CSV file to read points from.
 * @return A vector of Point objects read from the file.
 */
std::vector<geometry::Point> read_points_csv(const std::string& file_name);

/**
 * @brief Reads points from a WKT file containing POINT or MULTIPOINT geometries.
 * @param file_name The name of the WKT file to read points from.
 * @return A vector of Point objects read from the file.
 */
std::vector<geometry::Point> read_points_wkt(const std::string& file_name);

/**
 * @brief Prompts the user to input polygon points from a specified file.
 * @param file_name The name of the file to read polygon points from.
 * @return A vector of Point objects representing the polygon vertices.
 */
std::vector<geometry::Point> prompt_polygon_points();


} // namespace io

