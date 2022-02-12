#include "Right_polygon.h"
#include<cmath>

Right_polygon::Right_polygon(P mass[], int amount_of_peaks, int last_point) : Polygon(mass, amount_of_peaks, last_point)
{
	if (!check_of_right_polygon())
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

Right_polygon::Right_polygon(const Right_polygon& rp) : Polygon(rp)
{
}

Right_polygon::Right_polygon() : Polygon()
{
}

void Right_polygon::operator=(const Right_polygon& rp)
{
	peaks = rp.peaks;
	amount_of_peaks = rp.amount_of_peaks;
	last_point = rp.last_point;
}

bool Right_polygon::check_of_right_polygon()
{
	if (amount_of_peaks == 0)
		return false;
	double* mass_of_length = new double[amount_of_peaks];
	double* mass_of_angle = new double[amount_of_peaks];
	for (int i = 0; i < amount_of_peaks; i++)
	{
		if (i == amount_of_peaks - 1)
		{
			mass_of_length[i] = sqrt(pow((peaks[0].x - peaks[i].x), 2) + pow((peaks[0].y - peaks[i].y), 2));
			double cos_a = ((peaks[0].x - peaks[i].x) * (peaks[i - 1].x - peaks[i].x) +
								(peaks[0].y - peaks[i].y) * (peaks[i - 1].y - peaks[i].y)) /
								sqrt((pow((peaks[0].x - peaks[i].x), 2) + pow((peaks[0].y - peaks[i].y), 2)) *
								 sqrt(pow((peaks[i - 1].x - peaks[i].x), 2) + pow((peaks[i - 1].y - peaks[i].y), 2)));
			mass_of_angle[i] = acos(cos_a);
		}
		else
		{
			mass_of_length[i] = sqrt(pow((peaks[i + 1].x - peaks[i].x), 2) + pow((peaks[i + 1].y - peaks[i].y), 2));
			if (i == 0)
			{
				double cos_a = ((peaks[amount_of_peaks - 1].x - peaks[i].x) * (peaks[i + 1].x - peaks[i].x) +
								(peaks[amount_of_peaks - 1].y - peaks[i].y) * (peaks[i + 1].y - peaks[i].y)) /
								sqrt(pow((peaks[amount_of_peaks - 1].x - peaks[i].x), 2) + pow((peaks[amount_of_peaks - 1].y - peaks[i].y), 2)) *
								 sqrt(pow((peaks[i + 1].x - peaks[i].x), 2) + pow((peaks[i + 1].y - peaks[i].y), 2));
				mass_of_angle[i] = acos(cos_a);
			}
			else
			{
				double cos_a = ((peaks[i - 1].x - peaks[i].x) * (peaks[i + 1].x - peaks[i].x) +
								(peaks[i - 1].y - peaks[i].y) * (peaks[i + 1].y - peaks[i].y)) /
								 sqrt(pow((peaks[i - 1].x - peaks[i].x), 2) + pow((peaks[i - 1].y - peaks[i].y), 2)) *
								 sqrt(pow((peaks[i + 1].x - peaks[i].x), 2) + pow((peaks[i + 1].y - peaks[i].y), 2));
				mass_of_angle[i] = acos(cos_a);
			}
		}
	}
	for (int i = 0; i < amount_of_peaks - 1; i++)
	{
		if (mass_of_length[i] != mass_of_length[i + 1] || mass_of_angle[i] != mass_of_angle[i + 1])
			return false;
	}
	return true;
}
