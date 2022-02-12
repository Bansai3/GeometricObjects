#pragma once
#include"BrokenLine.h"
class ÑlosedLine : public BrokenLine 
{
public:
	ÑlosedLine(P mass[], int amount_of_peaks, int last_point);
	ÑlosedLine();
	ÑlosedLine(const ÑlosedLine& closed_line);
	void operator= (const ÑlosedLine& cl);
};

