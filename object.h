#include <vector>
#include "constants.h"
#include "point.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
private:
	std::vector<Point> points_array;
	int shift_x = 0;
	int shift_y = 0;

public:

	Object(std::vector<std::vector<double >>& scalar_field, std::vector<std::string>& strings, int x, int y, bool is_scalar);

	double get_potential_in_the_point(int _x, int _y);
};

#endif
