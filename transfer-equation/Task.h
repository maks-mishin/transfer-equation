#pragma once
#include "Grid.h"

class TaskHeat
{
public:
	TaskHeat(const double _time_max, const double _dx, const double _K);
	~TaskHeat();

	void set_init_conditions(const double _K);
	void compute(const double _K);

	void write_values(std::string file_name);


private:
	GridHeat grid;

	int size_x;
	const double a = 0.5;

	double *U_n = nullptr;
	double *U_n1 = nullptr;
	double *tmp = nullptr;

	double time_max;
	double dt;
};