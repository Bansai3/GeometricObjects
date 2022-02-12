#pragma once
#include<iostream>
class Polynomial
{
	double* mass_of_coefficients;
	int max_degree;
public:
	Polynomial();
	Polynomial(double mass[], int max_degree);
	Polynomial(const Polynomial& pol);
	~Polynomial();
	Polynomial operator= (const Polynomial& pol);
	bool operator== (const Polynomial& pol);
	bool operator!= (const Polynomial& pol);
	Polynomial operator+ (const Polynomial& pol);
	Polynomial operator- (const Polynomial& pol);
	Polynomial operator- ();
	void operator+= (const Polynomial& pol);
	void operator-= (const Polynomial& pol);
	Polynomial operator* (double number);
	Polynomial operator/ (double number);
	void operator*= (double number);
	void operator/= (double number);
	friend std::ostream& operator<< (std::ostream& out, const Polynomial& pol);
	friend std::istream& operator>> (std::istream& in, const Polynomial& pol);
	double operator[] (int index);
	void check_of_max_index(Polynomial& pol);
};

