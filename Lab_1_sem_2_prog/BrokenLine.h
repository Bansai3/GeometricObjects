#pragma once
#include<iostream>
#include"GeometricObjects.h"

class BrokenLine : public GeometricObjects
{
public:
	BrokenLine(P mass[], int amount_of_peaks, int last_point);
	BrokenLine();
	BrokenLine(const BrokenLine& bl);
	void operator= (const BrokenLine& broken_line);
	bool check_for_intersection();
	virtual double Perimeter() override;
	virtual double Square() override;
};

