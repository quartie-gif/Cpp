#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "OutOfRange.h"


struct Number
{

	Number(const std::string &text, const double num): _text(text), _num(num) 
	{

	}

	~Number() 
	{

		std::cout << "Destroying number " << _num << std::endl;
	}
	//named constructor idiom
	static Number* Factory(const std::string &text, const double num)
	{

		std::cout << "Manufacturing number " << num << std::endl;

		if(num > _range.second || num < _range.first)
		{
			throw OutOfRange(text, num, _range);
		}
		Number::_numbers.push_back(new Number(text, num));
		return Number::_numbers.back();
	}

	static void SetRange(const double begin, const double end) 
	{
		_range = std::pair<double, double>(begin, end);
	}

	void Print() const
	{
		std::cout << _text << " = " << _num << std::endl;
	}



	//fields
	std::string _text;
	double _num;
	static std::pair<double, double> _range;
	static std::vector<Number*> _numbers;
};
