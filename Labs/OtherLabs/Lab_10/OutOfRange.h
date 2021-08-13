#pragma once

#include <iostream>
#include <string>
#include "Number.h"

struct OutOfRange
{

	OutOfRange(const std::string& text, const double num, std::pair<double, double> range) 
	: _text(text), _num(num), _range(range) {}

	~OutOfRange() 
	{
		// while(!Number::_numbers.empty())
		// {
		// 	Number* num = Number::_numbers.back();
		// 	Number::_numbers.pop_back();
		// 	delete num;
		// }
	}

	std::ostream & print(std::ostream &o) const
	{

		return o << "Number named: " << _text << " has value " << _num << 
  					  " which is outside of the allowed range: [" << 
  					  _range.first << ", " <<_range.second << "]";
	}

	//fields
	std::string _text;
	double _num;
	std::pair<double, double> _range;
};

inline std::ostream & operator << (std::ostream &o, const OutOfRange& other)
{
	return other.print(o);
}