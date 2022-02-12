#include "Triangle.h"

Triangle::Triangle(P mass[], int amount_of_points, int last_point) : Polygon(mass, amount_of_points, last_point)
{
	if (amount_of_points != 3)
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

Triangle::Triangle(const Triangle& tr) 
{
	peaks = tr.peaks;
	last_point = tr.last_point;
	amount_of_peaks = tr.amount_of_peaks;
}

Triangle::Triangle() : Polygon()
{
}

void Triangle::operator=(const Triangle& tr)
{
	peaks = tr.peaks;
	last_point = tr.last_point;
	amount_of_peaks = tr.amount_of_peaks;
}
