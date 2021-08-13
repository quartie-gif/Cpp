#pragma once

#include <iostream>
#include <cmath>
#include <math.h>
#include "Point.h"
#include "Functions.h"

class Circle: public Drawable, public Transformable, public ClosedShape
{
public:
	Circle(const Point &point, double r): m_center(point), m_r(r) {}

	void draw() const override
	{
		std::cout << "Rysujemy kolo o srodku " << m_center << " i promieniu " << m_r << std::endl;
	}
	double length() const override
	{
		return 2 * M_PI * m_r;
	}
	void shift(const double x_shift, const double y_shift) override
	{
		m_center.shift(x_shift, y_shift);
	}

	double area() const override
	{
		return M_PI * pow(m_r, 2);
	}
private:
	Point m_center;
	double m_r;
};


class Section: public Drawable, public Transformable
{
public:
	Section(const Point &point1,const Point &point2): m_point1(point1), m_point2(point2) {}

	void draw() const override
	{
		std::cout << "Rysujemy odcinek od " << m_point1 << " do " << m_point2 << std::endl;
	}

	double length() const override
	{
		return sqrt(pow(m_point2.get_x()-m_point1.get_x(), 2) + pow(m_point2.get_y()-m_point1.get_y(), 2));
	}

	void shift(const double x_shift, const double y_shift) override
	{
		m_point1.shift(x_shift, y_shift);
		m_point2.shift(x_shift, y_shift);
	}

	void print(std::ostream &o) const
	{
		o << m_point1 <<  " " << m_point2;
	}

private:
	Point m_point1;
	Point m_point2;
};

inline std::ostream & operator << (std::ostream &o, const Section &other)
{
	other.print(o);
	return o;	
}

class Deltoid: public Drawable, public Transformable, public ClosedShape
{
public:
	Deltoid(const Section &section1, const Section &section2): m_section1(section1), m_section2(section2) {}
	Deltoid(const Point &point1, const Point &point2, const Point &point3, const Point &point4): m_section1(Section(point1, point2)), m_section2(Section(point3, point4)) {}


	void draw() const override
	{
		std::cout << "Rysujemy deltoid o wierzcholkach "<< m_section1 << " "<< m_section2 << std::endl;
	}

	double length() const override
	{
		return 2 * m_section1.length() + 2 * m_section2.length();
	}

	void shift(const double x_shift, const double y_shift) override
	{
		m_section1.shift(x_shift, y_shift);
		m_section2.shift(x_shift, y_shift);
	}

	double area() const override
	{
		return 0.5 * m_section1.length() * m_section2.length();
	}
private:
	Section m_section1;
	Section m_section2;
};




