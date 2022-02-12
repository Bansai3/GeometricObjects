#include "Ñlosedline.h"
#include<cmath>

ÑlosedLine::ÑlosedLine(P mass[], int amount_of_peaks, int last_point) : BrokenLine(mass, amount_of_peaks, last_point)
{
	if (last_point != 0)
	{
		this->amount_of_peaks = 0;
		peaks = nullptr;
	}
}

ÑlosedLine::ÑlosedLine() : BrokenLine()
{
	
}

ÑlosedLine::ÑlosedLine(const ÑlosedLine& closed_line) : BrokenLine(closed_line)
{
}


void ÑlosedLine::operator=(const ÑlosedLine& cl)
{
	peaks = cl.peaks;
	last_point = cl.last_point ;
	amount_of_peaks = cl.amount_of_peaks;
}

