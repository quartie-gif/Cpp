#pragma once 
#include "Fun.h"

class Op1
{
public:
	virtual Op1 *z(Fun * fun){m_fun = fun; return this;};
	virtual double w(double x) = 0;

protected:
	Fun * m_fun;
};