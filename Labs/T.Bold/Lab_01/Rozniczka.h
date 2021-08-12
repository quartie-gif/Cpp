#pragma once 

#include "Op.h"

class ProstaRozniczka: public Op1
{
public:
	ProstaRozniczka(double h): m_h(h) {};
	double w(double x) {return (m_fun->wartosc(x + m_h)-m_fun->wartosc(x - m_h))/ (2 * m_h);} ;
protected:
	double m_h;
};