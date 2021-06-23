#pragma once

#include <iostream>
#include <cmath>

/*! A class that represents function: f(x) = sin(a*x + b) */

class Sinus
{
public:
	Sinus(double a, double b): m_a(a), m_b(b){}
	double operator () (double x) const{ return sin(m_a * x+ m_b);}

private:
	double m_a; /*!< parameter a of that function */
	double m_b;	/*!< parameter b of that function */
};


/*! A class that represents function: f(x) = x^0.5 */

class PierwiastekKwadratowy
{
public:
	
	double operator () (double x) const { return pow(x, 0.5);}

};
/*! A class that represents function: f(x) = ax + b */
class Liniowa
{
public:
	Liniowa(double a, double b): m_a(a), m_b(b){}
	double operator () (double x) const { return m_a * x+m_b;}
private:
	double m_a; /*!< parameter a of linear function */
	double m_b; /*!< parameter b of linear function */
};