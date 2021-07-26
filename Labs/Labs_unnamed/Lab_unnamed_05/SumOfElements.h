#pragma once

#include <iostream>
#include "Operation.h"
#include <string>
#include <vector>

class SumOfElements: public Operation
{
public:
	SumOfElements(double *arr, unsigned n)
	{
		for(int i=0; i<n; ++i)
			_vecOfNums.push_back(arr[i]);
	}

	void print() const override
	{
		for(auto &el: _vecOfNums)
			if (el == _vecOfNums[_vecOfNums.size()-1])
				std::cout << el;
			else
				std::cout << el << " + ";
	}

	std::string eval() const override
	{
		double sum = 0;

		for(auto &el: _vecOfNums)
			sum += el;

		return std::to_string(sum);
	}

private:
	std::vector<double> _vecOfNums;
};