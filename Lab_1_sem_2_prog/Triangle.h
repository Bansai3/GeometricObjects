#pragma once
#include"Polygon.h"
class Triangle : public Polygon
{
public:
	Triangle(P mass[], int amount_of_peaks, int last_point);
	Triangle(const Triangle& tr);
	Triangle();
	void operator= (const Triangle& tr);
};

