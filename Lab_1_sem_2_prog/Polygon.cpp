#include "Polygon.h"
#include<math.h>

Polygon::Polygon(P mass[], int amount_of_peaks, int last_point) : ÑlosedLine(mass, amount_of_peaks, last_point)
{
	if (check_for_intersection() || amount_of_peaks < 3)
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

Polygon::Polygon(const Polygon& polygon) : ÑlosedLine(polygon)
{
}

Polygon::Polygon() : ÑlosedLine()
{

}

void Polygon::operator=(const Polygon& pol)
{
	peaks = pol.peaks;
	last_point = pol.last_point;
	amount_of_peaks = pol.amount_of_peaks;
}

