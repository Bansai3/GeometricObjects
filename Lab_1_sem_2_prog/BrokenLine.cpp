#include "BrokenLine.h"
#include<math.h>
#include<vector>

BrokenLine::BrokenLine(P mass[], int amount_of_peaks, int last_point) : GeometricObjects(mass, amount_of_peaks, last_point)
{
}
BrokenLine::BrokenLine() : GeometricObjects()
{
}
BrokenLine::BrokenLine(const BrokenLine& bl) : GeometricObjects(bl)
{
}
void BrokenLine::operator=(const BrokenLine& broken_line)
{
	peaks = broken_line.peaks;
	last_point = broken_line.last_point;
	amount_of_peaks = broken_line.amount_of_peaks;
}
double BrokenLine::Perimeter()
{
	if (amount_of_peaks == 0)
		return 0.0;
	std::vector<double> mass_of_k;
	if (peaks == nullptr)
		return 0.0;
	double perimeter = 0.0;
	for (int i = 0; i < amount_of_peaks - 1 ; i++)
	{
			perimeter += sqrt(pow(peaks[i].x - peaks[i + 1].x, 2) +
							  pow(peaks[i].y - peaks[i + 1].y, 2));
	}
	if (last_point >= amount_of_peaks - 2 || last_point < 0)
		return perimeter;
	else
	{
		for (int i = 0; i < amount_of_peaks - 1; i++)
		{
			double x = -1000;
			double k = -1000;
			double b = -1000;
			if (peaks[i + 1].x - peaks[i].x == 0)
			{
				x = peaks[i + 1].x;
				mass_of_k.push_back(x);
			}
			else
			{
				k = 1.0 * (peaks[i + 1].y - peaks[i].y) / (peaks[i + 1].x - peaks[i].x);
				mass_of_k.push_back(k);
				b = peaks[i].y - k * peaks[i].x;
			}
			if (x != -1000)
			{
				if (peaks[amount_of_peaks - 1].x == x)
				{
					if (peaks[amount_of_peaks - 1].y < peaks[i].y && peaks[amount_of_peaks - 1].y > peaks[i + 1].y ||
						peaks[amount_of_peaks - 1].y > peaks[i].y && peaks[amount_of_peaks - 1].y < peaks[i + 1].y)
					{
						if (last_point == i || last_point == i + 1)
							return perimeter;
						else
						{
							perimeter += sqrt(pow(peaks[last_point].x - peaks[amount_of_peaks - 1].x, 2) +
											  pow(peaks[last_point].y - peaks[amount_of_peaks - 1].y, 2));
							return perimeter;
						}
					}
					else
					{
						if((peaks[amount_of_peaks - 1].x == peaks[i].x && peaks[amount_of_peaks - 1].y == peaks[i].y) ||
						   (peaks[amount_of_peaks - 1].x == peaks[i + 1].x && peaks[amount_of_peaks - 1].y == peaks[i + 1].y))
						{
							if (last_point == i || last_point == i + 1)
								return perimeter;
							else
							{
								int count = 0;
								for (int i = 0; i < mass_of_k.size() - 1; i++)
								{
									if (mass_of_k[i] != mass_of_k[i + 1])
										break;
									else count++;
								}
								if (count == mass_of_k.size() - 1)
								{
									return perimeter;
								}
								perimeter += sqrt(pow(peaks[last_point].x - peaks[amount_of_peaks - 1].x, 2) +
												  pow(peaks[last_point].y - peaks[amount_of_peaks - 1].y, 2));
								return perimeter;
							}
						}
					}
					continue;
				}
				continue;
			}
			else
			{
				if (peaks[amount_of_peaks - 1].y == k * peaks[amount_of_peaks - 1].x + b)
				{
					if ((peaks[amount_of_peaks - 1].y < peaks[i].y && peaks[amount_of_peaks - 1].y > peaks[i + 1].y ||
						peaks[amount_of_peaks - 1].y > peaks[i].y && peaks[amount_of_peaks - 1].y < peaks[i + 1].y) &&
						(peaks[amount_of_peaks - 1].x < peaks[i].x && peaks[amount_of_peaks - 1].x > peaks[i + 1].x ||
							peaks[amount_of_peaks - 1].x > peaks[i].x && peaks[amount_of_peaks - 1].x < peaks[i + 1].x))
					{
						if (last_point == i || last_point == i + 1)
						{
							return perimeter;
						}
						else
						{
							int count = 0;
							for (int i = 0; i < mass_of_k.size() - 1; i++)
							{
								if (mass_of_k[i] != mass_of_k[i + 1])
									break;
								else count++;
							}
							if (count == mass_of_k.size() - 1)
							{
								return perimeter;
							}
							perimeter += sqrt(pow(peaks[last_point].x - peaks[amount_of_peaks - 1].x, 2) +
								pow(peaks[last_point].y - peaks[amount_of_peaks - 1].y, 2));
							return perimeter;
						}
					}
					else
					{
						if ((peaks[amount_of_peaks - 1].x == peaks[i].x && peaks[amount_of_peaks - 1].y == peaks[i].y) ||
							(peaks[amount_of_peaks - 1].x == peaks[i + 1].x && peaks[amount_of_peaks - 1].y == peaks[i + 1].y))
						{
							if (last_point == i || last_point == i + 1)
								return perimeter;
							else
								perimeter += sqrt(pow(peaks[last_point].x - peaks[amount_of_peaks - 1].x, 2) +
									pow(peaks[last_point].y - peaks[amount_of_peaks - 1].y, 2));
							return perimeter;
						}
					}
					continue;
				}
				else
				 continue;
			}
		}
	}
	perimeter += sqrt(pow(peaks[last_point].x - peaks[amount_of_peaks - 1].x, 2) +
					  pow(peaks[last_point].y - peaks[amount_of_peaks - 1].y, 2));
	return perimeter;
}
double BrokenLine::Square()
{
	if (check_for_intersection())
		return 0;
	else if (last_point == 0 && amount_of_peaks >= 3)
	{
		double square = 0;
		double sum_1 = 0;
		double sum_2 = 0;
		for (int i = 0; i < amount_of_peaks - 1; i++)
		{
			sum_1 += peaks[i].x * peaks[i + 1].y;
		}
		sum_1 += peaks[amount_of_peaks - 1].x * peaks[0].y;

		for (int i = 0; i < amount_of_peaks - 1; i++)
		{
			sum_2 += peaks[i].y * peaks[i + 1].x;
		}
		sum_2 += peaks[0].x * peaks[amount_of_peaks - 1].y;
		square = 0.5 * fabs(sum_1 - sum_2);
		return square;
	}
	return 0;
}
bool BrokenLine::check_for_intersection()
{
	for (int i = 0; i < amount_of_peaks - 1; i++)
	{
		for (int j = i + 2; j < amount_of_peaks - 1; j++)
		{
			double k_1 = -1000;
			double k_2 = -1000;
			double x_1 = -1000;
			double x_2 = -1000;
			if (peaks[i + 1].x - peaks[i].x == 0)
				x_1 = peaks[i].x;
			else
				 k_1 = 1.0 * (peaks[i + 1].y - peaks[i].y) / (peaks[i + 1].x - peaks[i].x);
			if (peaks[j + 1].x - peaks[j].x == 0)
				x_2 = peaks[j].x;
			else
				k_2 = 1.0 * (peaks[j + 1].y - peaks[j].y) / (peaks[j + 1].x - peaks[j].x);

			if (x_1 != -1000 && x_2 != -1000)
				continue;

			else if (x_1 != -1000)
			{
				double b = peaks[i].y - k_1 * peaks[i].x;
				double intersection_point_y = k_1 * x_2 + b;
				if ((intersection_point_y <= peaks[i + 1].y && intersection_point_y >= peaks[i].y) ||
					(intersection_point_y <= peaks[i].y && intersection_point_y >= peaks[i + 1].y))
				{
					if ((intersection_point_y <= peaks[j + 1].y && intersection_point_y >= peaks[j].y) ||
						(intersection_point_y <= peaks[j].y && intersection_point_y >= peaks[j + 1].y))
					return true;
				}
			}

			else if (x_2 != -1000)
			{
				double b = peaks[j].y - k_2 * peaks[j].x;
				double intersection_point_y = k_2 * x_1 + b;
				if ((intersection_point_y <= peaks[j + 1].y && intersection_point_y >= peaks[j].y) ||
					(intersection_point_y < peaks[j].y && intersection_point_y > peaks[j + 1].y))
				{
					if ((intersection_point_y <= peaks[i + 1].y && intersection_point_y >= peaks[i].y) ||
						(intersection_point_y <= peaks[i].y && intersection_point_y >= peaks[i + 1].y))
					return true;
				}
			}

			else
			{
				double b_1 = peaks[i].y - k_1 * peaks[i].x;
				double b_2 = peaks[j].y - k_2 * peaks[j].x;
				if (k_1 - k_2 == 0)
				{
					continue;
				}
				double intersection_point_x = (b_2 - b_1) / (k_1 - k_2);
				if ((intersection_point_x <= peaks[j + 1].x && intersection_point_x >= peaks[j].x) ||
					(intersection_point_x <= peaks[j].x && intersection_point_x >= peaks[j + 1].x))
				{
					if ((intersection_point_x <= peaks[i + 1].x && intersection_point_x >= peaks[i].x) ||
						(intersection_point_x <= peaks[i].x && intersection_point_x >= peaks[i + 1].x))
						return true;
				}
			}

		}
	}
	return false;
}
 