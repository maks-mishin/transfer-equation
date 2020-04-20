#pragma once
#include "Grid.h"

class Task
{
public:
	/*
		Constructor
		@param _time_max - max time of calculation
		@param dt - step for time
		@param _K - Courant number
		@param task_name - number of task (to reduce the time spent working with the program)
	*/
	Task(const double _time_max, const double _dx, const double _K, std::string task_number);
	~Task();

	/*
		Function for set init and boundary conditions
		@param _K - Courant number
		@param task_number - number of task
	*/
	void set_init_conditions(const double _K, std::string task_number);
	
	/*
		Main function of calculating
		@param _K - Courant number
	*/
	void compute(const double _K, std::string task_number);

	/*
		Function for record values to out file
	*/
	void record_values(std::string file_name);


private:
	Grid grid; // three-dimensional mesh

	int size_x; // size of arrays
	const double a = 0.5; // const by du/dx

	/*arrays for numerical solution*/
	double *U_n; // layer U(n)
	double *U_n1; // layer U(n+1)
	double *U_n_1; // layer U(n-1)

	double time_max; // max time of calculation
	double dt; // step for time
};