#include "Point.h"
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point::Point(const Point& p)
{
	x = p.x;
	y = p.y;
}
void Point::operator=(const Point& p)
{
	x = p.x;
	y = p.y;
}

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << "x = " << point.x << std::endl;
	out << "y = " << point.y << std::endl;
	return out;
}
