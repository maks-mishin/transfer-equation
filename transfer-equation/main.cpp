#include "Grid.h"
#include "Task.h"
#include <time.h>
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

string make_file_name(string task_number, int subtask_number, double K, double dx)
{
	string temp_name = task_number;
	temp_name += "_" + std::to_string(subtask_number);
	temp_name += "_K=";
	temp_name += std::to_string(K);
	temp_name += "_dx=";
	temp_name += std::to_string(dx);
	temp_name += ".txt";

	return temp_name;
}

int main()
{
	const vector<double> K_vec = { 0.1, 0.25, 0.5, 0.75, 1.0, 2.0 };
	const vector<double> h_vec = { 0.01, 0.005, 0.001 };
	const double time_max = 2.0;

	string file_name;

	for (size_t i = 0; i < K_vec.size(); i++)
	{
		
		Task task(time_max, h_vec[1], K_vec[i], "task_2");
		task.compute(K_vec[i], "task_2");
		
		file_name = make_file_name("task_2", 1, K_vec[i], h_vec[1]);
		task.record_values(file_name);
	}
	
	return 0;
}