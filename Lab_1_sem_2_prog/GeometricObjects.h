#pragma once
#include<iostream>

struct P
{
	double x;
	double y;
};
class GeometricObjects
{
protected:
	P* peaks;
	int last_point;
	int amount_of_peaks;
public:
	GeometricObjects(P mass[], int amount_of_peaks, int last_point);
	GeometricObjects();
	GeometricObjects(const GeometricObjects& bl);
	friend std::ostream& operator<< (std::ostream& out, const GeometricObjects& bl);
	virtual double Perimeter() = 0;
	virtual double Square() = 0;
};

