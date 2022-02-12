#pragma once
#include"ÑlosedLine.h"
class Polygon : public ÑlosedLine
{
public:
	Polygon(P mass[], int amount_of_peaks, int last_point);
	Polygon(const Polygon& polygon);
	Polygon();
	void operator= (const Polygon& pol);
};

