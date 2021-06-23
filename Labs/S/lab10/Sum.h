#pragma once

#include <iostream>


class Sum{

public:

	Sum(double sum): m_sum(sum) {}

	double value() const { return m_sum; }

	void operator () (double to_add)
	{
		m_sum += to_add;
	}

	
private:
	double m_sum = 0.;

};
