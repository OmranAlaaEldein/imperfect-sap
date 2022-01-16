#include "Shark.h"
#include "Root.h"
#include"math.h"
#include<iostream>
#include <fstream>
using namespace std;

Shark::Shark()
{
	ifstream input;
	//input.open("omar.txt");
	input.open("omar.txt");
	if (input.fail())
		exit(1);

	double a[10];

	for (int i = 0; i < 9; i++)
		input >> a[i];

	r = a[4];
	p = a[5];
	h_all = a[6];
}
float Shark::f_power(float y_shark, float o)
{
	return 2 * 3.14*r*y_shark*cos(o);
}

float Shark::w_power(float h)
{
	return (p*((3.14*r*r)*h))*9.8;
}
float Shark::power()
{
	f_shark = f_power(72.75, 45) - w_power(h_shark);
	return f_shark;
}
float Shark::new_value(float set_mass_root)
{
	float new_mass_shark;
	if ((f_shark / 9.8)<set_mass_root)
		new_mass_shark = (f_shark / 9.8);
	else
		new_mass_shark = set_mass_root;

	mass_shark = mass_shark + new_mass_shark;
	c_shark = c_shark + (0.015*new_mass_shark);
	h_shark = mass_shark / ((p*3.14*r*r) * 30000);//number of path in shark
	return new_mass_shark;
}
void Shark::print()
{
	cout << "\n--------2---------\nhight water in the shark = " << h_shark << "\npower in shark = " << f_shark
		<< "\nmass shark = " << mass_shark
		<< "\nconcentrate materials in shark=" << c_shark << "\n-----------------\n";
}
