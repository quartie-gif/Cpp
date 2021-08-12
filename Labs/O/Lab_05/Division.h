#pragma once 
 

#include <iostream>
#include <memory>
#include "Operation.h"

class Division: public Operation
{
public:
	Division(float n = 0., float dn = 0.): 
	m_n(n),
	m_dn(dn) 
	{}

	void print() const override
	{
		std::cout << m_n << " / " << m_dn;
	}

	float eval() const override
	{
		return m_n / m_dn;
	}


private:
	float m_n; // nominatior (licznik)
	float m_dn; // denominatior (mianownik)
};

inline void operator >>= (const std::string & text, const Division & other)
{
	std::cout << text << " " ;
	other.print();
	std::cout << " "  << text << std::endl;
}