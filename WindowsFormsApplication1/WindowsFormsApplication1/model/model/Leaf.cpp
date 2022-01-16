#include <iostream>
#include <math.h>
#include "Leaf.h"
#include <fstream>
using namespace std;

Leaf::Leaf()
{
	ifstream input;//?? 

	//input.open("omar.txt");
	input.open("omar.txt");

	if (input.fail())
		exit(1);

	double a[10];

	for (int i = 0; i < 9; i++)
		input >> a[i];

	U = a[7];
	number = a[8];

}
float Leaf::power_Ys(float C, float T)
{
	return (-1 * R*T*C);
}

float Leaf::power_Yw(float Yp, float Ys, float Yg)
{
	return Yp + Ys + Yg;
}

float Leaf::power(float c_shark, float t)
{
	f_leaf = power_Yw(-2.0*0.001, power_Ys(c_shark, t), 0) - power_Yw(-0.8*0.001, power_Ys(c_leaf, t), 0.1) + (vap_mass*9.8);//?????
	return f_leaf;
}
float Leaf::sating_compress(float t1)
{
	return 6.11*((7.5*(t1 + 273)) / (237.7 + (t1 + 273))) * 10;
}
float Leaf::L_power(float t)
{
	return sqrt(sqrt(t * 576 * pow(10, 4)*(0.23)));//E  %
}
float Leaf::delta(float t1, float t2)
{
	return (sating_compress(t1) - sating_compress(t2)) / (t1 - t2);
}
float Leaf::T2(float t1)
{
	return t1 - (vap_mass * 2257);
}

float Leaf::vap_power(float U, float T)
{
	return ((0.408*delta(T, T2(T))*(260 - 250)) + (0.000665*(900 / (T + 273))*U*(sating_compress(T) - sating_compress(T2(T))))) / (delta(T, T2(T)) + 0.000665*(L_power(T) + 0.34*U));
}
float Leaf::new_value(float T, float set_mass_shark)
{
	float new_mass_leaf;
	if ((f_leaf / 9.8)<set_mass_shark)
		new_mass_leaf = (f_leaf / 9.8);
	else
		new_mass_leaf = set_mass_shark;

	c_leaf = c_leaf + (new_mass_leaf*.015);
	mass_leaf = mass_leaf + new_mass_leaf;
	vap_mass = (vap_power(U, T)*number) / (24 * 60 * 60);//??????????????
	if (vap_mass<mass_leaf)
	{
		mass_leaf = mass_leaf - vap_mass;      //??c_leaf=-vap_power(U,ea,ed,delta)/(24*60*60)*.015;
		c_leaf = c_leaf - (vap_mass*0.015);
	}
	else
	{
		mass_leaf = 0.666;//????????????????
		c_leaf = 0.01;
	}
	return new_mass_leaf;
}
void Leaf::print()
{
	cout << "\n--------3---------\nLEAF:\npower leaf = " << f_leaf << "\nmass leaf = "
		<< mass_leaf << "\nc leaf" << c_leaf << "\nvap" << vap_mass << "\n-----------------\n";
}
