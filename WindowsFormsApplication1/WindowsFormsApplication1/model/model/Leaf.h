#include "Shark.h"
#ifndef LEAF_H
#define LEAF_H


class Leaf
{
public:
#define R 0.00832
	float  f_leaf, c_leaf, mass_leaf, vap_mass, U, number;//

	Leaf();
	float power_Ys(float C, float T);
	float power_Yw(float Yp, float Ys, float Yg);
	float power(float c_shark, float t);
	float sating_compress(float t1);
	float vap_power(float U, float T);
	float L_power(float t);
	float delta(float t1, float t2);
	float T2(float t1);
	float new_value(float T, float set_mass_shark);
	void print();
};

#endif // LEAF_H
