#include "constants.h"
#include "object.h"
#include "point.h"
#include "parse.h"
#include <symengine/symbol.h>


Object::Object(std::vector<std::vector<double >>& scalar_field, std::vector<std::string>& strings, int _x, int _y, bool is_scalar)
{
	shift_x = _x;
	shift_y = _y;

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (calc_all_expressions(strings, shift_x - x, shift_y - y))
			{
				points_array.push_back(Point(x, y));
			}
		}
	}

	visualize(scalar_field, is_scalar);
}

double Object::get_potential_in_the_point(int _x, int _y)
{
	double potential = 0.0;

	for (int i = 0; i < points_array.size(); i++)
	{
		potential += ELECTRICAL_CONSTANT / points_array[i].get_distance(_x, _y);
	}

	return potential;
}

