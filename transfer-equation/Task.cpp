#include <fstream>
#include "Task.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

void print(double *U, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << U[i] << " ";
		if (i % 10 == 0)
			cout << endl;
	}
}

TaskHeat::TaskHeat(const double _time_max, const double _dx, const double _K)
{
	time_max = _time_max;
	grid = GridHeat(2.0, _dx);

	set_init_conditions(_K);
}

TaskHeat::~TaskHeat()
{

}

/*
 * Function for calculation step
 * @params
 */
void step_calculation(double *U_n1, double *U_n, const double _K, const int size_x)
{
	double* temp = U_n1; // на входе слой n
	for (int i = 1; i < size_x - 1; i++)
	{
		temp[i] = U_n[i] - _K*(U_n1[i + 1] - U_n1[i - 1]);
	}
	U_n1 = temp; // на выходе слой n+1
}

void TaskHeat::set_init_conditions(const double _K)
{
	size_x = grid.steps_x;

	U_n = new double[size_x];
	U_n1 = new double[size_x];

	for (int i = 0; i < size_x; i++)
	{
		U_n[i] = 0;
		U_n1[i] = 0;

		if (grid.grid_x[i] >= 0.25 && grid.grid_x[i] <= 0.75)
		{
			U_n[i] = 1;
			U_n1[i] = 1;
		}

		/*U_n[i] = exp(-16 * (grid.grid_x[i] - 0.5))*sin(grid.grid_x[i] * atan(1.0)/(4*grid.dx));
		U_n1[i] = 0;// exp(-16 * (grid.grid_x[i] - 0.5))*sin(grid.grid_x[i] * atan(1.0) / (4 * grid.dx));
		*/
		//U_n[i] = exp(-3.2*(grid.grid_x[i] - 0.5));
		//U_n1[i] = 0;
	}

	for (int i = 1; i < size_x; i++)
	{
		U_n1[i] = U_n[i] - _K*(U_n[i] - U_n[i - 1]);
	}
}

void TaskHeat::compute(const double _K)
{
	dt = grid.dx * _K / a;

	double current_time = 0.0;
	do
	{
		if (time_max - current_time < dt)
			dt = time_max - current_time;

		// на входе Un1 = U(n=1)
		tmp = U_n1;
		step_calculation(U_n1, U_n, _K, size_x);

		U_n = tmp;
		// на выходе Un1 = U(n=2)

		current_time += dt;

	} while (current_time  < time_max);
}

void TaskHeat::write_values(string file_name)
{
	std::ofstream out;
	out.open(file_name);
	if (out.is_open() == false)
	{
		cout << "File " << file_name << " is not opened." << endl;
	}
	else
	{
		for (int i = 0; i < size_x; i++)
		{
			out << U_n[i] << endl;
		}
	}
	out.close();
}