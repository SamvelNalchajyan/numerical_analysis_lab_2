#include "boundary_value_problem.h"

double k(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x >= 0 && x < ksi)
	{
		return (x * x + 2);
	}
	if (x > ksi && x <= 1)
	{
		return (x * x);
	}
}

double q(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x >= 0 && x < ksi)
	{
		return (x);
	}
	if (x > ksi && x <= 1)
	{
		return (x * x);
	}
}

double f(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x >= 0 && x < ksi)
	{
		return 1.0;
	}
	if (x > ksi && x <= 1)
	{
		return (sin(M_PI * x));
	}
}

double k_t(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x < ksi)
	{
		return (ksi * ksi + 2.0);
	}
	if (x > ksi)
	{
		return (ksi * ksi);
	}
}

double q_t(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x < ksi)
	{
		return (ksi);
	}
	if (x > ksi)
	{
		return (ksi * ksi);
	}
}

double f_t(double x)
{
	
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	if (x < ksi)
	{
		return 1.0;
	}
	if (x > ksi)
	{
		return (sin(M_PI * ksi));
	}
}

double TestTask(double x)
{
	if (x < 0 || x > 1)
	{
		throw - 1;
	}
	
	//double C1 = -0.305144267161;
	//double C2 = -2.02818573283;
	//double C3 = 1.8932392630727;
	//double C4 = -13.989220463263;
	
	double C1 = -0.9603081830421;
	double C2 = -1.373025150287;
	double C3 = -2.459846401507;
	double C4 = -6.25891030953;
	if (x >= 0 && x <= ksi)
	{
		return (C1 * exp(x * sqrt(ksi / (2.0 + ksi * ksi))) + C2 * exp(-1.0 * x * sqrt(ksi / (2.0 + ksi * ksi))) + 1.0 / ksi);
		//return (C1 * exp(sqrt(30.0 / 209.0) * x) + C2 * exp(-1.0 * sqrt(30.0 / 209.0) * x) + 10.0 / 3.0);
	}
	else
	{
		return (C3 * exp(x) + C4 * exp(-1.0 * x) + sin(ksi * M_PI) / (ksi * ksi));
		//return (C3 * exp(x) + C4 * exp(-1.0 * x) + sin(M_PI * x) / (0.09 * (1.0 + M_PI * M_PI)));
	}

}

std::vector<double> TestTaskSolution(int n)
{
	double h = 1.0 / (double)n;
	std::vector<double> res;
	double x;
	for (int i = 0; i <= n; i++)
	{
		x = i * h;
		res.push_back(TestTask(x));
	}
	return res;
}

std::list<std::vector<double> > numerical_test_task(int n)
{
	std::list<std::vector<double> > result;
	std::vector<double> a_i;
	std::vector<double> d_i;
	std::vector<double> fi_i;
	double x = 0;
	double h = 1.0 / (double)n;
	/*
	//a
	for (int i = 0; i <= n; i++)
	{
		if (x + h <= ksi)
		{
			a_i[i] = k_t(x + h / 2.0);
		}
		else
		{
			if (x >= ksi)
			{
				a_i[i] = k_t(x + h / 2.0);
			}
			else
			{
				double tmp = n * ((ksi - x) / k_t(0.5 * (x + ksi)) + (x + h - ksi) / k_t(0.5 * (x + h + ksi)));
				a_i[i] = 1.0 / tmp;
			}
		}
		x += h;
	}
	//d
	x = h / 2.0;
	for (int i = 0; i <= n; i++)
	{
		if (x + h <= ksi)
		{
			d_i[i] = q_t(x + h / 2.0);
		}
		else
		{
			if (x >= ksi)
			{
				d_i[i] = q_t(x + h / 2.0);
			}
			else
			{
				d_i[i] = n * ((ksi - x) * q_t(0.5 * (x + ksi)) + (x + h - ksi) * q_t(0.5 * (x + h + ksi)));
			}
		}
		x += h;
	}
	//fi
	x = h / 2.0;
	for (int i = 0; i <= n; i++)
	{
		if (x + h <= ksi)
		{
			fi_i[i] = f_t(x + h / 2.0);
		}
		else
		{
			if (x >= ksi)
			{
				fi_i[i] = f_t(x + h / 2.0);
			}
			else
			{
				fi_i[i] = n * ((ksi - x) * f_t(0.5 * (x + ksi)) + (x + h - ksi) * f_t(0.5 * (x + h + ksi)));
			}
		}
		x += h;
	}
	*/
	
	for (int i = 1; i <= n; i++)
	{
		if (x + h <= ksi)
		{
			a_i.push_back(k_t(x + 0.5 * h));
		}
		else
		{
			if (x >= ksi)
			{
				a_i.push_back(k_t(x + 0.5 * h));
			}
			else
			{
				double tmp = n * ((ksi - x) / k_t(0.5 * (x + ksi)) + (x + h - ksi) / k_t(0.5 * (x + h + ksi)));
				a_i.push_back(1.0 / tmp);
			}
		}
		/*
		if (x < ksi && x - h > ksi)
		{
			double tmp =  ((ksi - x + h) / k_t(0.5 * (x - h + ksi)) + (x - ksi) / k_t(0.5 * (x + ksi)));
			a_i.push_back(1.0 / tmp);
			//a_i.push_back(1.0 / (((ksi - h * (i - 1)) / 2.09 + (i * h - ksi) / 0.09) * (1.0 / h)));
		}
		if (x >= ksi)
		{
			a_i.push_back(k_t(x));
		}
		*/
		x += h;
	}
	x = 0;
	//x = h / 2.0;
	for (int i = 1; i < n; i++)
	{
		if (x + 0.5 * h <= ksi)
		{
			d_i.push_back(q_t(x));
			fi_i.push_back(f_t(x));
		}
		else
		{
			if (x - 0.5 * h >= ksi)
			{
				d_i.push_back(q_t(x));
				fi_i.push_back(f_t(x));
			}
			else
			{
				d_i.push_back(n * ((ksi - x + 0.5 * h) * q_t(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * q_t(0.5 * (x + 0.5 * h + ksi))));
				fi_i.push_back(n * ((ksi - x + 0.5 * h) * f_t(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * f_t(0.5 * (x + 0.5 * h + ksi))));
			}
		}
		/*
		if (x + 0.5 * h < ksi && x - 0.5 * h > ksi)
		{
			d_i.push_back( ((ksi - x + 0.5 * h) * q_t(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * q_t(0.5 * (x + 0.5 * h + ksi))));
			fi_i.push_back( ((ksi - x + 0.5 * h) * f_t(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * f_t(0.5 * (x + 0.5 * h + ksi))));
			//d_i.push_back((1.0 / h) * (0.3 * (ksi - (i - 0.5) * h) + 0.09 * (i + 0.5) * h - ksi));
			//fi_i.push_back((1.0 / h) * (1.0 * (ksi - h * (i - 0.5)) + 0.80901699437 * ((i + 0.5) * h - ksi))); //sin(pi * ksi)
		}
		if (x + 0.5 * h >= ksi)
		{
			d_i.push_back(q_t(x));
			fi_i.push_back(f_t(x)); 
		}
		*/
		x += h;
	}
	
	/*
	std::vector<double> lower_diag = a_i;
	std::vector<double>	main_diag = d_i;
	std::vector<double>	upper_diag = a_i;
	lower_diag[0] *= n * n;
	for (int i = 1; i <= n; i++)
	{
		lower_diag[i] *= n * n;
		upper_diag[i - 1] = lower_diag[i];
		main_diag[i - 1] += lower_diag[i] + lower_diag[i - 1];
	}
	lower_diag[n] = 0.0;
	main_diag[0] = 1.0;
	main_diag[n] = 1.0;
	upper_diag[n] = 0.0;
	// Прогонка
	std::vector<double> v_tmp(n + 1);
	std::vector<double> a(n + 1);
	std::vector<double> b(n + 1);
	std::vector<double> free = fi_i;
	free[0] = 1.0;
	free[n] = 0.0;
	for (int i = 1; i <= n; i++)
	{
		double tmp = main_diag[i - 1] - a[i - 1] * lower_diag[i - 1];
		a[i] = upper_diag[i - 1] / tmp;
		b[i] = (free[i - 1] + b[i - 1] * lower_diag[i - 1]) / tmp;
	}
	v_tmp[n] = (free[n] + lower_diag[n] * b[n]) / (1 - lower_diag[n] * a[n]);
	for (int i = n - 1; i >= 0; i--)
	{
		v_tmp[i] = a[i + 1] * v_tmp[i + 1] + b[i + 1];
	}
	*/

	
	// Прогонка
	double xi1 = 0.0;
	double xi2 = 0.0;
	
	std::vector<double> v_tmp(n + 1);
	v_tmp[0] = mu1;
	v_tmp[n] = mu2;
	
	std::vector<double> A, B, C;
	for (int i = 0; i < n - 1; i++)
	{
		A.push_back(a_i[i] / (h * h));
		B.push_back(a_i[i + 1] / (h * h));
		C.push_back(A.back() + B.back() + d_i[i]);
	}
	
	std::vector<double> alpha, beta;
	alpha.push_back(xi1);
	beta.push_back(mu1);
	for (int i = 0; i < n - 1; i++)
	{
		alpha.push_back(B[i] / (C[i] - alpha[i] * A[i]));
		beta.push_back((fi_i[i] + beta[i] * A[i]) / (C[i] - alpha[i] * A[i]));
	}
	for (int i = n - 1; i >= 0; i--)
	{
		v_tmp[i] = alpha[i] * v_tmp[i + 1] + beta[i];
	}
	
	//-------------------//
	x = 0;
	std::vector<double> u = TestTaskSolution(n);
	for (int i = 0; i <= n; i++)
	{
		std::vector<double> table_line = { x, u[i], v_tmp[i], fabs(u[i] - v_tmp[i]) };
		result.push_back(table_line);
		x += h;
	}
	
	//-------------------//
	return result;
}

std::vector<double> numerical_task_n(int n)
{
	std::vector<double> a_i;
	std::vector<double> d_i;
	std::vector<double> fi_i;
	double x = 0;
	double h = 1.0 / (double)n;
	for (int i = 1; i <= n; i++)
	{
		x += h;
		if (x <= ksi)
		{
			a_i.push_back(k(x - 0.5 * h));
		}
		else
		{
			if (x - h >= ksi)
			{
				a_i.push_back(k(x - 0.5 * h));
			}
			else
			{
				double tmp = n * ((ksi - x + h) / k(0.5 * (x - h + ksi)) + (x - ksi) / k(0.5 * (x + ksi)));
				a_i.push_back(1.0 / tmp);
			}
		}
	}
	x = 0;
	//x = h / 2.0;
	for (int i = 1; i < n; i++)
	{
		x += h;
		if (x + 0.5 * h <= ksi)
		{
			d_i.push_back(q(x));
			fi_i.push_back(f(x));
		}
		else
		{
			if (x - 0.5 * h >= ksi)
			{
				d_i.push_back(q(x));
				fi_i.push_back(f(x));
			}
			else
			{
				d_i.push_back(n * ((ksi - x + 0.5 * h) * q(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * q(0.5 * (x + 0.5 * h + ksi))));
				fi_i.push_back(n * ((ksi - x + 0.5 * h) * f(0.5 * (x - 0.5 * h + ksi)) + (x + 0.5 * h - ksi) * f(0.5 * (x + 0.5 * h + ksi))));
				//d_i.push_back(n * ((ksi - x + h) * q(0.5 * (x - h + ksi)) + (x - ksi) * q(0.5 * (x + ksi))));
				//fi_i.push_back(n * ((ksi - x + h) * f(0.5 * (x - h + ksi)) + (x - ksi) * f(0.5 * (x + ksi))));
			}
		}
		//x += h;
	}

	// Прогонка
	double xi1 = 0.0;
	double xi2 = 0.0;

	std::vector<double> v_tmp(n + 1);
	v_tmp[0] = mu1;
	v_tmp[n] = mu2;

	std::vector<double> A, B, C;
	for (int i = 0; i < n - 1; i++)
	{
		A.push_back(a_i[i] / (h * h));
		B.push_back(a_i[i + 1] / (h * h));
		C.push_back(A.back() + B.back() + d_i[i]);
	}

	std::vector<double> alpha, beta;
	alpha.push_back(xi1);
	beta.push_back(mu1);
	for (int i = 0; i < n - 1; i++)
	{
		alpha.push_back(B[i] / (C[i] - alpha[i] * A[i]));
		beta.push_back((fi_i[i] + beta[i] * A[i]) / (C[i] - alpha[i] * A[i]));
	}
	for (int i = n - 1; i >= 0; i--)
	{
		v_tmp[i] = alpha[i] * v_tmp[i + 1] + beta[i];
	}
	return v_tmp;
}

std::list<std::vector<double> > numerical_main_task(int n)
{
	std::list<std::vector<double> > result;
	std::vector<double> v = numerical_task_n(n);
	std::vector<double> v2 = numerical_task_n(2 * n);
	double x = 0;
	double h = 1.0 / (double)n;
	for (int i = 0; i <= n; i++)
	{
		std::vector<double> table_line = { x, v[i], v2[2 * i], fabs(v[i] - v2[2 * i]) };
		result.push_back(table_line);
		x += h;
	}
	return result;
}