#pragma once

#include<iostream>
#include<string>
#include <cmath>
#include "Figura.h"
#include "Wierzcholek.h"

class Prostokat: public Figura
{
	public:

		Prostokat(const std::string &name): Figura(name)
		{
			std::cout << "Tak naprawdę jestem prostokątem.\n";
		}

		double pole() const
		{
			double d_1 = m_container[0].distance(m_container[1]);
			double d_2 = m_container[0].distance(m_container[3]);
	
			return d_1 * d_2;
		}

		

};