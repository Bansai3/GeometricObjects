#pragma once
#include"Polygon.h"
class Trapeze : public Polygon
{
public:
	Trapeze(P mass[], int amount_of_peaks, int last_point);
	Trapeze(const Trapeze& tr);
	Trapeze();
	void operator= (const Trapeze& tr);
	bool check_for_traspeze();
};

