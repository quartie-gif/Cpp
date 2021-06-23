#pragma once 
#include <iostream>

class Primitive
{
public:
	Primitive(const float x = 0): m_x(x) {}

	virtual float equals() const {return m_x;}

	virtual void print() const { std::cout << m_x;}

	virtual void PrintWithValue() const
	{
		print();
		std::cout << " = " << equals() << std::endl;

	}

	void Set(const float x)
	{
		m_x = x;
	}

protected:
	float m_x;
};