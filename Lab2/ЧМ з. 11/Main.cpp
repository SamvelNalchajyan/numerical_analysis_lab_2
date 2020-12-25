#include <iostream>
#include <clocale>
#include <cstdlib>
#include <iomanip>
#include "boundary_value_problem.h"
#define N 8

int main()
{
	setlocale(LC_CTYPE, "Russian");

	std::list<std::vector<double> > test_result = numerical_test_task(N);
	std::list<std::vector<double> >::iterator it;
	std::cout << "x      | u              v               |u - v|" << std::endl;
	for (it = test_result.begin(); it != test_result.end(); it++)
	{
		std::cout << std::left << std::setw(5) << it->at(0) << " | " << std::left << std::setw(5) << it->at(1) << " | " << std::left << std::setw(5) << it->at(2) << " | " << std::left << std::setw(5) << it->at(3) << std::endl;
	}
	std::cout << std::endl << "--------------------------------------" << std::endl;
	std::list<std::vector<double> > main_result = numerical_main_task(N);
	std::list<std::vector<double> >::iterator m_it;
	std::cout << "x      | v              v2              |v - v2|" << std::endl;
	for (m_it = main_result.begin(); m_it != main_result.end(); m_it++)
	{
		std::cout << std::left << std::setw(5) << m_it->at(0) << " | " << std::left << std::setw(5) << m_it->at(1) << " | " << std::left << std::setw(5) << m_it->at(2) << " | " << std::left << std::setw(5) << m_it->at(3) << std::endl;
	}

	system("pause");
	return 0;
}