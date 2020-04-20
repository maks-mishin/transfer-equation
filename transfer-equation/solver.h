#pragma once

/*
	Function for calculation step
	@param U_n1 - array of layer U(n+1)
	@param U_n - array of layer U(n)
	@param U_n_1 - array of layer U(n-1)
	@param _K - Courant number
	@param size_x - size of array
*/
void step_calculation(double *U_n1, double *U_n, double *U_n_1, const double _K, const int size_x)
{
	for (int i = 1; i < size_x - 1; i++)
	{
		U_n1[i] = U_n_1[i] - _K*(U_n[i + 1] - U_n[i - 1]);
	}
}