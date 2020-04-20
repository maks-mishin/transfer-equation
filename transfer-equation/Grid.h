#pragma once

#include <vector>

class Grid
{
public:
	/*
		Default constructor
	*/
	Grid();

	/*
		Constructor
		@param _dx - step on X
	*/
	Grid(double lower_bound, double upper_bound, double _dx);
	~Grid();

	std::vector<double> get_grid_x() { return grid_x; }
	
	// spatial mesh
	std::vector<double> grid_x;

	int get_steps_x() { return steps_x; }

	// step on X
	double dx;

	// amount of steps on X and Y
	int steps_x = 0;

	// boundaries of area
	double lower_bound;
	double upper_bound;
};
