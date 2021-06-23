#pragma once 

#include <iostream>

class Point
{
public:
	Point(const double x, const double y): m_x(x), m_y(y) {}

	void print(std::ostream &o) const
	{
		o << "(" << m_x << ", " << m_y << ")";
	}

	double get_x() const { return m_x; }
	double get_y() const { return m_y; }

	void shift(const double x_shift,const double y_shift)
	{
		m_x += x_shift;
		m_y += y_shift;
	}

private:
	double m_x;
	double m_y;
};

std::ostream & operator << (std::ostream & o, const Point &other)
{
	other.print(o);
	return o;
}