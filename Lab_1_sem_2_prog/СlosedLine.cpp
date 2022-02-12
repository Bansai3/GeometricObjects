#include "�losedline.h"
#include<cmath>

�losedLine::�losedLine(P mass[], int amount_of_peaks, int last_point) : BrokenLine(mass, amount_of_peaks, last_point)
{
	if (last_point != 0)
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

�losedLine::�losedLine() : BrokenLine()
{
	
}

�losedLine::�losedLine(const �losedLine& closed_line) : BrokenLine(closed_line)
{
}


void �losedLine::operator=(const �losedLine& cl)
{
	peaks = cl.peaks;
	last_point = cl.last_point ;
	amount_of_peaks = cl.amount_of_peaks;
}

