#include <iostream>
#include <fstream>
#include <string>
#include "Grid.h"


GridHeat::GridHeat()
{
}

//Initialize grid
GridHeat::GridHeat(double _a, double _dx)
{
	a = _a;
	dx = _dx;

	for (double i = 0; i < a; i += dx)
	{
		grid_x.push_back(i);
		steps_x++;
	}

	grid_x.push_back(a);
	steps_x++;
}

GridHeat::~GridHeat()
{
}
