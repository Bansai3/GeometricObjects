#include "Polynomial.h"
#include<stdlib.h>
#include<string>

Polynomial::Polynomial()
{
	mass_of_coefficients = new double[1];
	mass_of_coefficients[0] = 0;
	max_degree = 0;
}

Polynomial::Polynomial(double mass[], int max_degree)
{
	this->max_degree = max_degree;
	mass_of_coefficients = new double[max_degree + 1];
	for (int i = 0; i < max_degree + 1; i++)
	{
		mass_of_coefficients[i] = mass[i];
	}
	check_of_max_index(*this);
}

Polynomial::Polynomial(const Polynomial& pol)
{
	max_degree = pol.max_degree;
	mass_of_coefficients = new double[max_degree + 1];
	for (int i = 0; i <= max_degree; i++)
	{
		mass_of_coefficients[i] = pol.mass_of_coefficients[i];
	}
}

Polynomial::~Polynomial()
{
	delete[] mass_of_coefficients;
}

Polynomial Polynomial::operator=(const Polynomial& pol)
{
	max_degree = pol.max_degree;
	double* point = mass_of_coefficients;
	mass_of_coefficients = new double[max_degree + 1];
	for (int i = 0; i <= max_degree; i++)
	{
		mass_of_coefficients[i] = pol.mass_of_coefficients[i];
	}
	delete[] point;
	return *this;
}

bool Polynomial::operator==(const Polynomial& pol)
{
	if (max_degree != pol.max_degree)
		return false;
	else
	{
		for (int i = 0; i <= max_degree; i++)
		{
			if (mass_of_coefficients[i] != pol.mass_of_coefficients[i])
				return false;
		}
	}
	return true;
}

bool Polynomial::operator!=(const Polynomial& pol)
{
	if (max_degree != pol.max_degree)
		return true;
	else
	{
		for (int i = 0; i <= max_degree; i++)
		{
			if (mass_of_coefficients[i] != pol.mass_of_coefficients[i])
				return true;
		}
	}
	return false;
}

Polynomial Polynomial::operator+(const Polynomial& pol)
{
	Polynomial new_pol;
	if (this->max_degree >= pol.max_degree)
	{
		new_pol.max_degree = this->max_degree;
	}
	else 
		new_pol.max_degree = pol.max_degree;
	new_pol.mass_of_coefficients = new double[new_pol.max_degree + 1];
	if (this->max_degree >= pol.max_degree)
	{
		for (int i = 0; i <= (this->max_degree); i++)
		{
			new_pol.mass_of_coefficients[i] = this->mass_of_coefficients[i];
		}

		for (int i = 0; i < pol.max_degree + 1; i++)
		{
			new_pol.mass_of_coefficients[i] += pol.mass_of_coefficients[i];
		}
	}
	else
	{
		for (int i = 0; i <= (pol.max_degree); i++)
		{
			new_pol.mass_of_coefficients[i] = pol.mass_of_coefficients[i];
		}

		for (int i = 0; i <= this->max_degree; i++)
		{
			new_pol.mass_of_coefficients[i] += this->mass_of_coefficients[i];
		}
	}
	check_of_max_index(new_pol);
	return new_pol;
}

Polynomial Polynomial::operator-(const Polynomial& pol)
{
	Polynomial new_pol;
	if (this->max_degree >= pol.max_degree)
	{
		new_pol.max_degree = this->max_degree;
	}
	else
		new_pol.max_degree = pol.max_degree;
	new_pol.mass_of_coefficients = new double[new_pol.max_degree + 1];
	if (this->max_degree >= pol.max_degree)
	{
		for (int i = 0; i <= (this->max_degree); i++)
		{
			new_pol.mass_of_coefficients[i] = this->mass_of_coefficients[i];
		}

		for (int i = 0; i < pol.max_degree + 1; i++)
		{
			new_pol.mass_of_coefficients[i] -= pol.mass_of_coefficients[i];
		}
	}
	else
	{
		for (int i = 0; i <= (pol.max_degree); i++)
		{
			new_pol.mass_of_coefficients[i] = -pol.mass_of_coefficients[i];
		}

		for (int i = 0; i <= this->max_degree; i++)
		{
			new_pol.mass_of_coefficients[i] += this->mass_of_coefficients[i];
		}
	}
	check_of_max_index(new_pol);
	return new_pol;
}

Polynomial Polynomial::operator-()
{
	Polynomial new_pol;
	new_pol.max_degree = max_degree;
	new_pol.mass_of_coefficients = new double[max_degree + 1];
	for (int i = 0; i <= max_degree; i++)
	{
		new_pol.mass_of_coefficients[i] = mass_of_coefficients[i] * (-1);
	}
	return new_pol;
}

void Polynomial::operator+=(const Polynomial& pol)
{
	if (pol.max_degree > this->max_degree)
	{
		double* point = mass_of_coefficients;
		mass_of_coefficients = new double[pol.max_degree + 1];
		for (int i = 0; i <= pol.max_degree; i++)
		{
			mass_of_coefficients[i] = pol.mass_of_coefficients[i];
		}
		for (int i = 0; i <= max_degree; i++)
		{
			mass_of_coefficients[i] += point[i];
		}
		delete[] point;
	}
	else
	{
		for (int i = 0; i <= pol.max_degree; i++)
		{
			mass_of_coefficients[i] += pol.mass_of_coefficients[i];
		}
	}
	check_of_max_index(*this);
}

void Polynomial::operator-=(const Polynomial& pol)
{
	if (pol.max_degree > this->max_degree)
	{
		double* point = mass_of_coefficients;
		mass_of_coefficients = new double[pol.max_degree + 1];
		max_degree = pol.max_degree;
		for (int i = 0; i <= pol.max_degree; i++)
		{
			mass_of_coefficients[i] = -pol.mass_of_coefficients[i];
		}
		for (int i = 0; i <= max_degree; i++)
		{
			mass_of_coefficients[i] += point[i];
		}
		delete[] point;
	}
	else
	{
		for (int i = 0; i <= pol.max_degree; i++)
		{
			mass_of_coefficients[i] -= pol.mass_of_coefficients[i];
		}
	}
	check_of_max_index(*this);
}

Polynomial Polynomial::operator*(double number)
{
	Polynomial new_pol;
	new_pol.max_degree = max_degree;
	new_pol.mass_of_coefficients = new double[max_degree + 1];
	for (int i = 0; i <= max_degree; i++)
	{
		new_pol.mass_of_coefficients[i] = mass_of_coefficients[i] * number;
	}
	check_of_max_index(new_pol);
	return new_pol;
}

Polynomial Polynomial::operator/(double number)
{
	Polynomial new_pol;
	if (number == 0)
	{
		return *this;
	}
	else
	{
		new_pol.max_degree = max_degree;
		new_pol.mass_of_coefficients = new double[max_degree + 1];
		for (int i = 0; i <= max_degree; i++)
		{
			new_pol.mass_of_coefficients[i] = mass_of_coefficients[i] / number;
		}
	}
	return new_pol;
}

void Polynomial::operator*=(double number)
{
	for (int i = 0; i <= max_degree; i++)
	{
		mass_of_coefficients[i] *= number;
	}
	check_of_max_index(*this);
}

void Polynomial::operator/=(double number)
{
	if (number == 0)
		return;
	else
	{
		for (int i = 0; i <= max_degree; i++)
		{
			mass_of_coefficients[i] /= number;
		}
	}
}

double Polynomial::operator[](int index)
{
	if (index > max_degree || index < 0)
	{
		setlocale(LC_ALL, "Russian");
		std::string str = "Выход за пределы массива";
		std::cout << str << " ";
		return -6;
	}
		return mass_of_coefficients[index];
}

void Polynomial::check_of_max_index(Polynomial& pol)
{
	int new_max_degree = pol.max_degree;
	double* point = pol.mass_of_coefficients;
	while (pol.mass_of_coefficients[new_max_degree] == 0 && new_max_degree > 0)
	{
		new_max_degree--;
	}
	if (new_max_degree != pol.max_degree)
	{
		pol.mass_of_coefficients = new double[new_max_degree + 1];
		for (int i = 0; i <= new_max_degree; i++)
		{
		pol.mass_of_coefficients[i] = point[i];
			pol.max_degree = new_max_degree;
		}
		delete[] point;
	}
}

std::ostream& operator<<(std::ostream& out, const Polynomial& pol)
{
	for (int i = 0; i <= pol.max_degree; i++)
	{
		if (i == 0)
		{
			out << pol.mass_of_coefficients[i] << " ";
		}
		else
		out << pol.mass_of_coefficients[i] << "x" << "^" << i << " ";
	}
	return out;
}

std::istream& operator>>(std::istream& in, const Polynomial& pol)
{
	for (int i = 0; i <= pol.max_degree; i++)
	{
		in >> pol.mass_of_coefficients[i];
	}
	return in;
}
