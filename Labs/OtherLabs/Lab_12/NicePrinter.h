#pragma once 

#include <iostream>
#include <string>
#include <iomanip>


struct NicePrinter{

	unsigned _prefix;
	inline static unsigned _lines = 0;


	NicePrinter(unsigned prefix): _prefix(prefix) {}

	template<typename T>
	void operator () (const T &text) const
	{
		std::cout << std::setw(_prefix) << ++_lines << ":" << text << std::endl;
	}


};