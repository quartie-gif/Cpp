#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include "Funkcje.h"


/*! A class that represents function composition */

class ZlozenieFunkcji
{
public:
	void insert(std::function<double(double)> fun )
	{
		m_fun.push_back(fun);
	};

	double wynik(double x)
	{
		m_results.clear();

		m_results.push_back(m_fun[0](x));

		for(unsigned i=1; i<m_fun.size(); ++i)
		{
			m_results.push_back(m_fun[i](m_results[i-1]));
		}
		return m_results.at(m_results.size()-1);
	};

	double operator [] (unsigned index)
	{
		return m_results[index];
	}

private:
	std::vector<std::function<double(double)>> m_fun; /*!< vector that saves function objects */
	std::vector<double> m_results; /*!< vector that saves values generated using m_fun functions */
};

