#pragma once
#include"Polygon.h"
class Right_polygon : public Polygon
{
public:
	Right_polygon(P mass[], int amount_of_peaks, int last_point);
	Right_polygon(const Right_polygon& rp);
	Right_polygon();
	void operator= (const Right_polygon& rp);
	bool check_of_right_polygon();
};

