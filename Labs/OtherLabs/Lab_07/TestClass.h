#pragma once

#include <iostream>
#include <string>

class TestClass
{
public:
	TestClass(const std::string &info): _info(info)
	{
		std::cout << "++ Tworze obiekt TestClass: " << _info << std::endl;
	}
	~TestClass()
	{
		std::cout << "-- Usuwam obiekt TestClass: " << _info << std::endl;
	}
	std::string info() const { return _info; }


private:
	std::string _info;
};