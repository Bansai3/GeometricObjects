#pragma once
#include<iostream>

class Point
{
	double x;
	double y;
public:
	Point(double x = 0.0, double y = 0.0);
	Point(const Point& p);
	void operator= (const Point& p);
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

