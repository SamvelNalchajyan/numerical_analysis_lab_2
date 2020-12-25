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
	for (int i = 1; i <= n; i++)
	{
		x = i * h;
		if (x <= ksi)
		{
			a_i.push_back(2.0 + ksi * ksi);
		}
		if (x - h < ksi && x > ksi)
		{
			a_i.push_back(1.0 / (((ksi - h * (i - 1)) / 2.09 + (i * h - ksi) / 0.09) * (1.0 / h)));
		}
		if (x - h >= ksi)
		{
			a_i.push_back(ksi * ksi);
		}
	}
	for (int i = 1; i < n; i++)
	{
		x = i * h;
		//-------------------//
		if (x + 0.5 * h <= ksi)
		{
			d_i.push_back(ksi);
			fi_i.push_back(1.0);
		}
		if (x - 0.5 * h < ksi && x + 0.5 * h > ksi)
		{
			d_i.push_back((1.0 / h) * (0.3 * (ksi - (i - 0.5) * h) + 0.09 * (i + 0.5) * h - ksi));
			fi_i.push_back((1.0 / h) * (1.0 * (ksi - h * (i - 0.5)) + 0.80901699437 * ((i + 0.5) * h - ksi))); //sin(pi * ksi)
		}
		if (x - 0.5 * h >= ksi)
		{
			d_i.push_back(ksi * ksi);
			fi_i.push_back(0.80901699437); //0.016448598865398
		}
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
	//-------------------//
	std::vector<double> u = TestTaskSolution(n);
	for (int i = 0; i <= n; i++)
	{
		x = i * h;
		std::vector<double> table_line = { x, u[i], v_tmp[i], fabs(u[i] - v_tmp[i]) };
		result.push_back(table_line);
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
		x = i * h;
		if (x <= ksi)
		{
			a_i.push_back(k(x - 0.5 * h));
		}
		if (x - h < ksi && x > ksi)
		{
			a_i.push_back(1.0 / (((ksi - h * (i - 1)) / k((x - h + ksi) / 2.0) + (i * h - ksi) / k(ksi + x)) * (1.0 / h)));
		}
		if (x - h >= ksi)
		{
			a_i.push_back(k(x - 0.5 * h));
		}
	}
	for (int i = 1; i < n; i++)
	{
		x = i * h;
		//-------------------//
		if (x + 0.5 * h <= ksi)
		{
			d_i.push_back(q(x));
			fi_i.push_back(f(x));
		}
		if (x - 0.5 * h < ksi && x + 0.5 * h > ksi)
		{
			d_i.push_back((1.0 / h) * (q((x - 0.5 * h + ksi) / 2.0) * (ksi - (i - 0.5) * h) + q((ksi + x + 0.5 * h) / 2.0) * (i + 0.5) * h - ksi));
			fi_i.push_back((1.0 / h) * (f((x - 0.5 * h + ksi) / 2.0) * (ksi - h * (i - 0.5)) + f(ksi + x + 0.5 * h) * ((i + 0.5) * h - ksi)));
		}
		if (x - 0.5 * h >= ksi)
		{
			d_i.push_back(q(x));
			fi_i.push_back(f(x));
		}
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
	double x;
	double h = 1.0 / (double)n;
	for (int i = 0; i <= n; i++)
	{
		x = i * h;
		std::vector<double> table_line = { x, v[i], v2[2 * i], fabs(v[i] - v2[2 * i]) };
		result.push_back(table_line);
	}
	return result;
}