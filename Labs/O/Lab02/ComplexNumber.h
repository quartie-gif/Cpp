#pragma once 

#include <iostream>


class ComplexNumber
{
public:
	ComplexNumber(double x=0, double y=0): 
	m_x(x),
	m_y(y) 
	{}

	void print(std::ostream &out) const
	{
		out << m_x << " + " << m_y << "i" ;
	}

	explicit operator double() const
	{
		return m_x;
	}

	ComplexNumber operator + (const ComplexNumber& other) const
	{
		return ComplexNumber{m_x + other.m_x, m_y + other.m_y};
	}

	ComplexNumber operator - (const ComplexNumber& other) const
	{
		return ComplexNumber{m_x - other.m_x, m_y - other.m_y};
	}


	ComplexNumber operator * (const ComplexNumber& other) const
	{
		//(A1 + i*A2)*(B1 + i*B2) = A1*B1 - A2*B2 + i*(A1*B2 + A2*B1)
		return ComplexNumber{m_x * other. m_x - m_y * other.m_y, m_x * other.m_y + m_y * other.m_x};
	}

	void operator *= (int x)
	{
		m_x *= x;
		m_y *= x;
	}

	ComplexNumber operator ++ ()
	{
		m_x ++;
		m_y ++;
		return *this;
	}

	ComplexNumber operator ++ (int x)
	{
		ComplexNumber temp = *this;
		++*this;
		return temp;
	}

	bool operator > (const ComplexNumber& other) const 
	{
		double mod_1 = m_x * m_x + m_y *m_y;
		double mod_2 = other.m_x * other.m_x + other.m_y *other.m_y;

		return mod_1 > mod_2 ? true : false;
	}

	double & operator [] (unsigned int index)
	{
		return index == 0 ? m_x : m_y;
	}


	double getX() const
	{
		return m_x;
	}

	double getY() const
	{
		return m_y;
	}


private:
	double m_x;
	double m_y;
};




inline std::ostream & operator << (std::ostream & out, const ComplexNumber & other)
{
	other.print(out);
	return out;
}

inline ComplexNumber operator + (int x, const ComplexNumber & other)
{
	return ComplexNumber{x + other.getX(), other.getY()};
}

