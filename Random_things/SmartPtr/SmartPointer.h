#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <typeinfo>

template<typename T>
class Deleter
{
public:
	using value_type = T;

	void operator () (T *ptr)
	{
		++Deleter::_counter;
		delete ptr;
	}


	void info()
	{
		std::cout << std::endl;
		std::string type{typeid(value_type).name()};
		size_t size = Deleter::_counter * sizeof(value_type);

		std::cout << "Deleted objects: " << Deleter::_counter << " of type " << type << std::endl;
		std::cout << "Freed size in bytes: " << size << std::endl; 
		std::cout << std::endl;
	}

private:
	static unsigned _counter;
};

template<typename T>
unsigned Deleter<T>::_counter = 0;

