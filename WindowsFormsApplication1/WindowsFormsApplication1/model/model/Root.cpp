#include "Root.h"
#include<iostream>
#include <fstream>
using namespace std;

Root::Root()
{
	ifstream input;

	input.open("omar.txt");

	if (input.fail())
		exit(1);

	double a[10];

	for (int i = 0; i < 9; i++)
		input >> a[i];

	T = a[0]+273;
	l = a[1]; 
	C_root = a[3];
	C_soil = a[2];
	
}
float Root::power_Ys(float C)
{
	return (-1 * R*T*C);
}

float Root::power_Yw(float Yp, float Ys)
{
	return Yp + Ys;
}

float Root::sub()
{
	res_soils = this->power_Yw(-0.2*0.001, this->power_Ys(C_soil));
	res_root = this->power_Yw(-0.4*0.001, this->power_Ys(C_root));

	if (res_root >= -1.3)
		e = 2.3;
	else if (res_root <= -1.3 &&res_root >= -1.8)
		e = 1.7;
	else if (res_root <= -1.8 && res_root >= -2.1)
		e = 1.4;
	else if (res_root <= -2.1 && res_root >= -2.18)
		e = 0.8;
	else if (res_root <= -2.18 && res_root >= -2.5)
		e = 0.5;
	else if (res_root <= -2.5 && res_root >= -2.8)
		e = 0.3;
	else if (res_root <= -2.8 && res_root >= -3.06)
		e = 0.12;
	else if (res_root <= -3.06 &&  res_root <= -3.4)
		e = 0.06;
	else if (res_root <= -3.4)
		e = 0;

	return res_soils - res_root;
}

float Root::speed_water()
{
	return (0.000001*0.001) * (res_soils - res_root);
}

float Root::Time()
{
	TIme = (0.693 * (l*l*l)) / (0.000001*(l*l * 6) * (e - this->power_Ys(C_root)));
	return TIme;
}

void Root::print()
{
	cout << "\n-------1----------\nROOT:\nall mass = " << old_mass << "\npower root= "
		<< res_root << "\nC_root=" << C_root << "\npower soil=" << res_soils << "\nC_soil=" << C_soil <<
		"\ntime = " << TIme << "\nspeed =" << speed_water() << "\n-------------------------------";
}

