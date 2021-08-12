#pragma once 
#include <iostream>

class Argumenty
{
public:
	Argumenty(): m_arg(nullptr), m_size(0){}

	Argumenty(int size): m_size(size)
	{
		m_arg = new double[size];
		for(int i=0; i<size; ++i)
		{
			m_arg[i] = 0;
		}
	}
	~Argumenty()
	{
		delete [] m_arg;
	}

	Argumenty & operator () (const int index, const double val)
	{
		m_arg[index] = val;
		return *this;
	}

	double & operator [] (const int index)
	{
		return m_arg[index];
	}

	double & operator [] (const int index) const
	{
		return m_arg[index];
	}

	void print(const std::string &text, std::ostream & strm = std::cout) const
	{
		strm << text << " ";

		for(int i=0; i<m_size; ++i)
		{

			strm << m_arg[i] << " ";
		}

		strm << std::endl;
	}

	int getSize() const
	{
		return m_size;
	}

protected:	
	double * m_arg;
	int m_size;
};

class Algo
{
	public:
		Algo() = default;
		
		virtual Argumenty wykonaj(const Argumenty & arg) const = 0;
		virtual Algo*  sklonuj() const = 0;
	private:

};


