#include <iostream>
#include <fstream>
#include <string>
#include "Grid.h"


Grid::Grid()
{
}

//Initialize grid
Grid::Grid(double _lower_bound, double _upper_bound, double _dx)
{
	lower_bound = _lower_bound;
	upper_bound = _upper_bound;

	dx = _dx;

	for (double i = 0; i < (upper_bound - lower_bound); i += dx)
	{
		grid_x.push_back(i);
		steps_x++;
	}

	grid_x.push_back(upper_bound);
	steps_x++;
}

Grid::~Grid()
{
}
