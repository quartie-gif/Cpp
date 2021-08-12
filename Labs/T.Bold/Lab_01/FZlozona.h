#pragma once 

#include "Fun.h"

class FZlozona: public Op1
{
public:
	FZlozona(Fun * g): m_g(g) {};
	double w(double x) {return m_g->wartosc(m_fun->wartosc(x)) ;} ;
protected:
	Fun* m_g;
};