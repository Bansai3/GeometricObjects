#include"Triangle.h"
#include"Point.h"
#include"Trapeze.h"
#include"Right_polygon.h"
#include<iostream>
#include"Polynomial.h"
int main() 
{
	P mass_1[4] = { {0,0}, {0,1}, {1, 1}, {1, 0} };
	P mass_2[4] = { {0,0}, {1,1}, {0, 2}, {3, 0} };
	P mass_3[3] = { {0,0}, {1,1}, {2, 0} };
	P mass_4[3] = { {0, 0}, {0, 1}, {0, 2} };
	P mass_5[4] = { {0,0}, {2, 2}, {3,1}, {1,1} };
	Right_polygon rp(mass_1, 4, 0);
	Right_polygon rp_2 = rp;
	Trapeze trap(mass_2, 4, 0);
	Triangle tr(mass_3, 3, 0);
	BrokenLine bl(mass_4, 3, 0);
	ÑlosedLine cl(mass_5, 4, 0);
	BrokenLine mass[5] = {rp, trap, tr, bl, cl};
	for (int i = 0; i < 5; i++)
	{
		std::cout << " Perimeter = " << mass[i].Perimeter() << std::endl;
		std::cout << "Square = " << mass[i].Square() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	/*for (int i = 0; i < 4; i++)
	{
		std::cout<< mass[i] << std::endl;
		std::cout << std::endl;
	}*/

	/*double mass_1[5] = { 1, 3, 6, 8, 1 };
	double mass_2[6] = { 1, 2, 5, 9, 1, 4 };
	Polynomial pol_1(mass_1, 4);
	Polynomial pol_2(mass_2, 5);
	Polynomial pol_3;
	std::cout << pol_1 << std::endl;
	std::cout << pol_2 << std::endl;;
	std::cout << (pol_1 + pol_2) << std::endl;
	std::cout << pol_1 - pol_2 << std::endl;
	std::cout << pol_1 * 6 << std::endl;
	std::cout << (pol_1 / 2) << std::endl;
	std::cout << pol_1 - pol_1 << std::endl;
	std::cout << pol_1[3] << std::endl;
	std::cout << pol_1[6] << std::endl;
	std::cout << (pol_1 == pol_2) << std::endl;
	std::cout << (pol_1 != pol_2) << std::endl;
	pol_1 *= 3;
	std::cout << (pol_1) << std::endl;
	pol_1 /= 3;
	std::cout << (pol_1) << std::endl;
	std::cout << -(pol_1) << std::endl;
	pol_1 -= pol_2;
	std::cout << pol_1 << std::endl;
	pol_1 += pol_2;
	std::cout << pol_1 << std::endl;
	std::cin >> pol_2;
	std::cout << pol_2;*/
	return 0;
}