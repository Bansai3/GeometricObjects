#include "GeometricObjects.h"

GeometricObjects::GeometricObjects(P mass[], int amount_of_peaks, int last_point)
{
	this->amount_of_peaks = amount_of_peaks;
	this->last_point = last_point;
	peaks = new P[amount_of_peaks];

	for (int i = 0; i < amount_of_peaks; i++)
	{
		peaks[i] = mass[i];
	}
}

GeometricObjects::GeometricObjects()
{
	peaks = nullptr;
	last_point = 0;
	amount_of_peaks = 0;
}

GeometricObjects::GeometricObjects(const GeometricObjects& bl)
{
	peaks = bl.peaks;
	last_point = bl.last_point;
	amount_of_peaks = bl.amount_of_peaks;
}

std::ostream& operator<<(std::ostream & out, const  GeometricObjects& bl)
{
	for (int i = 0; i < bl.amount_of_peaks; i++)
	{
		out << "[" << bl.peaks[i].x << ", " << bl.peaks[i].y << "]" << std::endl;
	}
	out << bl.amount_of_peaks << std::endl;
	out << bl.last_point << std::endl;
	return out;
}