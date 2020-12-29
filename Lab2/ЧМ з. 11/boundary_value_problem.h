#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <list>
//#include "TMatrix.h"
#define ksi 0.3
#define mu1 1.0
#define mu2 0.0

double k(double x);
double q(double x);
double f(double x);
double k_t(double x);
double q_t(double x);
double f_t(double x);
double TestTask(double x);
std::vector<double> TestTaskSolution(int n);
std::list<std::vector<double> > numerical_test_task(int n);
std::vector<double> numerical_task_n(int n);
std::list<std::vector<double> > numerical_main_task(int n);