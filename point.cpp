#include <cmath>
#include "point.h"

Point::Point(int _x, int _y) : x(_x), y(_y)
{

}

double Point::get_distance(int _x, int _y)
{
    if (_x == x && _y == y)
    {
        return 0;
    }

    return sqrt((_x - x) * (_x - x) + (_y - y) * (_y - y));
}
