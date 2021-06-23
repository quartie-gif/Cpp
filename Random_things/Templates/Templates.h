#pragma once

#include <iterator>
#include <iostream>
#include <string>
#include <utility>

template <typename T>
T Sum(T x, T y)
{
	return x + y;
}

template <typename T>
T Max(T x, T y)
{
	return (x>=y)?x:y;
}

template <typename T>
class Parr{
T first, second;
public:
	Parr(T a, T b): first(a), second(b){};
	void print() const
	{
		std::cout << "First parameter : " << first <<  "\t Second parameter : " << second << std::endl;
	}
	T getFirst() const;
};


template <typename T>
T Parr<T>::getFirst() const
{
	return first;
}