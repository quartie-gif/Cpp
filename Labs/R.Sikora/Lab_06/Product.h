#pragma once 

#include <iostream>
#include "Primitive.h"

class Product: public Primitive
{
public:
	Product(const Primitive& p1, const Primitive& p2): m_p1(p1), m_p2(p2) {}

	void print() const override
	{
		std::cout << "(";
		m_p1.print();
		std::cout << "*"; 
		m_p2.print();
		std::cout << ")";
	}

	float equals() const override 
	{
		return m_p1.equals() * m_p2.equals() ;
	}

private:
	const Primitive & m_p1;
	const Primitive & m_p2;
};