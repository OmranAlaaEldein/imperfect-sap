#ifndef ROOT_H
#define ROOT_H


class Root
{
public:

#define R 0.00832
	float T, l, e;
	float old_mass, res_soils, res_root, C_soil, C_root, TIme;

	Root();
	float power_Ys(float C);
	float power_Yw(float Yp, float Ys);
	float sub();
	float Time();
	float speed_water();
	void print();

};

#endif // ROOT_H
