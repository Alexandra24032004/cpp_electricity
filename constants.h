#include <string>

#ifndef CONSTANTS_H
#define CONSTANTS_H

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1000;
const int FIELD_WIDTH = 1000;
const int FIELD_HEIGHT = 1000;
const double ELECTRICAL_CONSTANT = 1.0;
const std::string POTENTIAL_FIELD_FILE = "scalar_visualisation_data.txt";
const std::string VECTOR_FIELD_FILE = "vector_visualisation_data.txt";
const int length_of_bold = 500;
const int width_of_bold = 30;
const int step = 30;
int const null_x = 50;
int const null_y = 50;
const int shape_of_grid = 20;
const int num_of_vec = FIELD_WIDTH / shape_of_grid;
const std::string c1 = "#0000FF"; //blue
const std::string c2 = "#FFFF00"; //yellow
const std::string c4 = "#EE82EE"; //purple
const std::string c3 = "#00FFFF"; //light blue

#endif
