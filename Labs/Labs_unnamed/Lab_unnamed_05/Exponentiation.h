#pragma once

#include <iostream>
#include "Operation.h"
#include <string>
#include <math.h>

class Exponentiation: public Operation
{
public:
	Exponentiation(int basis, float exponent): _basis(basis), _exponent(exponent)
	{
		
	}

	void print() const override
	{
		std::cout << _basis << " ^ " << _exponent;
	}

	std::string eval() const override
	{
		return std::to_string(pow(_basis, _exponent));
	}

private:
	int _basis;
	float _exponent;
};