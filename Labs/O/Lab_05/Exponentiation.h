#pragma once 
 

#include <iostream>
#include <memory>
#include <cmath>
#include <string>
#include "Operation.h"

class Exponentiation: public Operation
{
public:
	Exponentiation(float x, float y): 
	m_x(x),
	m_y(y) 
	{}

	void print() const override
	{
		std::cout << m_x << " ^ " << m_y;
	}

	float eval() const override
	{
		return pow(m_x, m_y);
	}


private:
	float m_x; // base
	float m_y; // exponent 
};

inline void operator >>= (const std::string & text, const Exponentiation & other)
{
	std::cout << text << " " ;
	other.print();
	std::cout << " "  << text << std::endl;
}
