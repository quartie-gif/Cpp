	#pragma once

#include <iostream>




template <typename T, typename U>
class PairOfNumbers{
public:

	PairOfNumbers(T& first, U& sec): first(first), second(sec) {}

	PairOfNumbers<double, int> Swapped() const 
	{ 
		return PairOfNumbers<U, T>(second, first); 
	} 

	void Add(T val)
	{
		first += val;
		second += val;
	}

	void Scale(T scale) 
	{
		first *= scale;
		second *= scale;
	}

	void Info() const
	{
		std::cout << "This is const pair of numbers" << std::endl;
	}
	void Info()
	{
		std::cout << "This is NON-const pair of numbers" << std::endl;
	}

	void Print(std::ostream &o = std::cout) const
	{
		o << "Print method: " <<  first << " " << second << std::endl;
	}

	T getFirst() const { return first; }
	U getSecond() const { return second; }

	T& first;
	U& second;
};

