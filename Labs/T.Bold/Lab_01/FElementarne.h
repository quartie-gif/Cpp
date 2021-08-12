#pragma once 
#include "Fun.h"
#include <cmath>

class Liniowa: public Fun
{
public:
	Liniowa(): m_a(0.), m_b(0.){};
	static Liniowa* utworz(){return new Liniowa();}
	double wartosc(double x) override {return m_a *x + m_b; };
	Liniowa * a(double a){m_a = a; return this;}
	Liniowa * b(double b){m_b = b; return this;}
protected:
	double m_a;
	double m_b;
};

class Kwadratowa: public Fun
{
public:
	Kwadratowa(): m_a(0.), m_b(0.), m_c(0.){};
	static Kwadratowa* utworz(){return new Kwadratowa();}
	double wartosc(double x) override {return m_a * pow(x, 2) + m_b * x + m_c; };
	Kwadratowa * a(double a){m_a = a; return this;}
	Kwadratowa * b(double b){m_b = b; return this;}
	Kwadratowa * c(double c){m_c = c; return this;}
protected:
	double m_a;
	double m_b;
	double m_c;
};