#pragma once
#include"BrokenLine.h"
class �losedLine : public BrokenLine 
{
public:
	�losedLine(P mass[], int amount_of_peaks, int last_point);
	�losedLine();
	�losedLine(const �losedLine& closed_line);
	void operator= (const �losedLine& cl);
};

