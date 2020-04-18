#include "Grid.h"
#include "Task.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	const vector<double> K_vec = { 0.1, 0.25, 0.5, 0.75, 1.0, 2.0 };
	const vector<double> h_vec = { 0.01, 0.005, 0.001 };
	const double time_max = 2.0;

	const vector<string> file_names_task_1_1
	{
		"taks=1_1_K=0.1_h=0.01.txt",
		"taks=1_1_K=0.25_h=0.01.txt",
		"taks=1_1_K=0.5_h=0.01.txt",
		"taks=1_1_K=0.75_h=0.01.txt",
		"taks=1_1_K=1_h=0.01.txt",
		"taks=1_1_K=2_h=0.01.txt",
	};
	
	TaskHeat task(time_max, h_vec[0], K_vec[0]);
	task.compute(K_vec[0]);
	task.write_values(file_names_task_1_1[0]);
	
	return 0;
}