#pragma once

#include <vector>

class GridHeat
{
public:
	GridHeat();
	GridHeat(double a, double dx);
	~GridHeat();

	std::vector<double> get_grid_x() { return grid_x; }
	std::vector<double> grid_x;

	int get_steps_x() { return steps_x; }

	// Step on X and Y
	double dx;

	//Amount of steps on X and Y
	int steps_x = 0;

	//Boundary of area
	double a;
};
