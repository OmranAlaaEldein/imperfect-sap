#ifndef SHARK_H
#define SHARK_H


class Shark
{
public:
	float r, y_shark, o, mass_shark, c_shark, p, f_shark, h_shark, h_all;

	Shark();
	float f_power(float y_shark, float o);
	float w_power(float h);
	float power();
	float new_value(float set_mass_root);
	void print();

};

#endif // SHARK_H
