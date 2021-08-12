#pragma once 
 

#include <iostream>
#include <memory>
#include <string>
#include "Operation.h"


class SumOfElements: public Operation
{
public:
	SumOfElements(double * numbers = nullptr, int size = 0): 
	m_size(size) 
	{
		m_numbers = new double[size];
		for(size_t i=0; i<m_size; ++i)
		{
			m_numbers[i] = numbers[i];
		}
	}
	~SumOfElements() {delete [] m_numbers;}
	void print() const override
	{
		std::cout << m_numbers[0];
		for(size_t i=1; i<m_size; ++i)
		{
			std::cout << " + " << m_numbers[i];
		}
	}

	float eval() const override
	{
		float sum =0;
		for(size_t i=0; i<m_size; ++i)
		{
			sum += m_numbers[i];
		}
		return sum;
	}

private:
	double * m_numbers = nullptr;
	unsigned int m_size = 0;

};


inline void operator >>= (const std::string & text, const SumOfElements & other)
{
	std::cout << text << " " ;
	other.print();
	std::cout << " "  << text << std::endl;
}