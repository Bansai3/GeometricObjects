#pragma once
#include"�losedLine.h"
class Polygon : public �losedLine
{
public:
	Polygon(P mass[], int amount_of_peaks, int last_point);
	Polygon(const Polygon& polygon);
	Polygon();
	void operator= (const Polygon& pol);
};

