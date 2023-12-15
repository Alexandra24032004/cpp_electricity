#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

public:
    Point(int _x, int _y);
    double get_distance(int _x, int _y);
};

#endif
