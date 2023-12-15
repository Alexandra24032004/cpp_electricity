#include "constants.h"
#include "object.h"
#include "point.h"

Object::Object()
{
	//Formula..;

	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		/*for (int x = 0; x < FIELD_WIDTH; x++)
		{
			if (is_in_figure(formula))
			{
				points_array.push_back(Point(x, y));
			}
		}*/
	}
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

