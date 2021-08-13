#pragma once

#include <iostream>
#include "Operation.h"
#include <string>

class Division: public Operation
{
public:
	Division(int denominator, int numerator): _numerator(numerator)
	{
		if(denominator != 0)
			_denominator = denominator;
	}

	void print() const override
	{
		std::cout << _denominator << " / " << _numerator;
	}

	std::string eval() const override
	{
		return std::to_string(_denominator/_numerator);
	}

private:
	int _denominator, _numerator;
};