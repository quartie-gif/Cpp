#pragma once

#include<iostream>
#include<string>
#include <cmath>

class Wierzcholek
{
	public:
		Wierzcholek(double x, double y):m_x(x), m_y(y) {};

		void print(std::ostream &out) const
		{
			out << "(" << m_x << " " << m_y << ")";
		}

	
		double distance(const Wierzcholek & other) const
		{	
			return sqrt(pow(m_x - other.m_x, 2) + pow(m_y - other.m_y, 2));
		}

		bool operator != (const Wierzcholek & other) const 
		{
			return !(*this == other);
		}

		bool operator == (const Wierzcholek & other) const 
		{
			if (this == &other) return true;
			return m_x == other.m_x and m_y == other.m_y;
		}

	protected:
		double m_x;
		double m_y;
};

inline std::ostream & operator << (std::ostream & out, const Wierzcholek &other)
{
	other.print(out);
	return out;
}
