#include "Trapeze.h"
#include<cmath>

Trapeze::Trapeze(P mass[], int amount_of_peaks, int last_point) : Polygon(mass, amount_of_peaks, last_point)
{
	if (!check_for_traspeze())
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

Trapeze::Trapeze(const Trapeze& tr) : Polygon(tr)
{

}

Trapeze::Trapeze() : Polygon()
{
}

void Trapeze::operator=(const Trapeze& tr)
{
	peaks = tr.peaks;
	amount_of_peaks = tr.amount_of_peaks;
	last_point = tr.last_point;

}

bool Trapeze::check_for_traspeze()
{
	if (amount_of_peaks != 4)
		return false;
	int count = 0;
	double mass_of_k[4] = { -INFINITY,  -INFINITY,  -INFINITY,  -INFINITY};
	for (int i = 0; i < amount_of_peaks; i++)
	{
		if (peaks[i + 1].x - peaks[i].x != 0)
		{
			mass_of_k[i] = 1.0 * (peaks[i + 1].y - peaks[i].y) / (peaks[i + 1].x - peaks[i].x);
		}
	}
	if (mass_of_k[0] == mass_of_k[2] && (mass_of_k[1] != mass_of_k[3]) ||
		mass_of_k[0] != mass_of_k[2] && (mass_of_k[1] == mass_of_k[3]))
		return true;
	return false;
}


