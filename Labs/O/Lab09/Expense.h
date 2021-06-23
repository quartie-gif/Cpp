#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>


struct Sum
{
    void operator()(double n) { sum += n; }
    double sum{0};
};

class Expense
{
public:
	Expense(const std::string &day, const std::initializer_list < double >& list): m_day(day), m_list(list) {}

	void print() const 
	{
		std::cout << m_day << ":";
		auto fun = [](const double& x) { std::cout << "\t" << x; };
		std::for_each(m_list.begin(), m_list.end(), fun);
		std::cout << std::endl;
	}

	double mean() const
	{
		Sum sum = std::for_each(m_list.begin(), m_list.end(), sum);
		return sum.sum/m_list.size();
	}

private:
	std::initializer_list < double > m_list;
	std::string m_day;
};