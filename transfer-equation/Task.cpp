#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <math.h>
#include "Task.h"
#include "solver.h"

using namespace std;

Task::Task(const double _time_max, const double _dx, const double _K, std::string task_number)
{
	time_max = _time_max;
	grid = Grid(0.0, 2.0, _dx);

	set_init_conditions(_K, task_number);
}

Task::~Task()
{
	delete [] U_n_1;
	U_n_1 = nullptr;

	delete [] U_n;
	U_n = nullptr;
	
	delete [] U_n1;
	U_n1 = nullptr;
}

void Task::set_init_conditions(const double _K, std::string task_number)
{
	// allocate memory for arrays
	size_x = grid.steps_x;

	U_n = new double[size_x];
	U_n1 = new double[size_x];
	U_n_1 = new double[size_x];

	if (task_number == "task_1")
	{
		for (int i = 0; i < size_x; i++)
		{
			U_n[i] = 0;
			U_n1[i] = 0;
			U_n_1[i] = 0;

			if (grid.grid_x[i] >= 0.25 && grid.grid_x[i] <= 0.75)
			{
				U_n_1[i] = 1;
			}
		}
	}
	else if (task_number == "task_2")
	{
		for (int i = 0; i < size_x; i++)
		{
			U_n[i] = 0;
			U_n1[i] = 0;
			U_n_1[i] = 0;

			U_n_1[i] = exp(-16 * pow((grid.grid_x[i] - 0.5), 2))*sin(grid.grid_x[i] * (2*atan(1.0)*4)/(8*grid.dx));
		}
	}
	else if (task_number == "task_3")
	{
		for (int i = 0; i < size_x; i++)
		{
			U_n[i] = 0;
			U_n1[i] = 0;
			U_n_1[i] = 0;

			U_n_1[i] = exp(-3200 * pow((grid.grid_x[i] - 0.5), 2));
		}
	}

	for (int i = 1; i < size_x; i++)
	{
		U_n[i] = U_n_1[i] - _K*(U_n_1[i] - U_n_1[i - 1]);
	}
}

void Task::compute(const double _K, string task_number)
{
	dt = grid.dx * _K / a;

	double current_time = 0.0;
	do
	{
		if (time_max - current_time < dt)
			dt = time_max - current_time;

		step_calculation(U_n1, U_n, U_n_1, _K, size_x);

		// swap arrays
		for (int i = 0; i < size_x; i++)
		{
			U_n_1[i] = U_n[i];
		}

		for (int i = 0; i < size_x; i++)
		{
			U_n[i] = U_n1[i];
		}

		current_time += dt;

	} while (current_time < time_max);
}

void Task::record_values(string file_name)
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
			out << U_n1[i] << endl;
		}
	}
	out.close();
}