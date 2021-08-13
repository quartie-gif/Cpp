#include "Argumenty.h"

Argumenty::Argumenty(): m_arg(nullptr), m_size(0){}
Argumenty::Argumenty(int size): m_size(size)
{
	m_arg = new double[size];
	for(int i=0; i<size; ++i)
	{
		m_arg[i] = 0;
	}
}

Argumenty::Argumenty(const Argumenty & arg)
{
    m_arg = new double[arg.m_size]; 
    for (size_t i=0; i < arg.m_size; ++i)
    {
        m_arg[i] = arg.m_arg[i];
    }
    m_size = arg.m_size;
}
Argumenty & Argumenty::operator () (const int index, const double val)
{
	m_arg[index] = val;
	return *this;
}
double & Argumenty::operator [] (const int index)
{
	return m_arg[index];
}
double & Argumenty::operator [] (const int index) const
{
	return m_arg[index];
}
void Argumenty::print(std::ostream & strm ) const
{
	for(int i=0; i<m_size; ++i)
	{
		strm << m_arg[i] << " ";
	}
}
int Argumenty::getSize() const
{
	return m_size;
}
Argumenty Argumenty::pojedynczy(double x)
{
    Argumenty arg(1);
    arg(0,x);
    return arg;
}