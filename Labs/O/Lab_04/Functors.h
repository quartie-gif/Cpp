#pragma once

#include <iostream>
#include <functional>


class DivisibleBy
{
public:
	DivisibleBy(int x): m_x(x) {}
	bool operator () (int x)
	{
		return (x % m_x) == 0;
	}
private:
	int m_x;
};

class GreaterThan
{
public:

	GreaterThan(int x): m_x(x) {}

	bool operator () (int x)
	{
		return x > m_x;
	}
private:
	int m_x;
};