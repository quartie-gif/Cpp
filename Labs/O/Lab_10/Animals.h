#pragma once

#include <iostream>
#include <string>
#include "Animal.h"

class Sheep: public Animal
{
public:
	Sheep(const std::string &name = ""): m_name(name) {}

	Sheep(const Sheep& s): m_name(s.m_name), m_shear(s.m_shear) {}

	virtual ~Sheep() 
	{
		std::cout << "- Owca " << m_name;
		if(m_shear){std::cout <<" strzyzona" ;}
		else {std::cout <<" niestrzyzona" ;}
		std::cout << " wraca do zagrody" << std::endl;
	}
	void print() const override 
	{
		std::cout << "- Owca " << m_name;
		if(m_shear){std::cout <<" strzyzona" << std::endl;}
		else {std::cout <<" niestrzyzona" << std::endl;}
	}

	std::string name() const override
	{
		return m_name;
	}

	void shear()
	{
		m_shear = true;
	}

private:
	std::string m_name = "";
	bool m_shear = false;
	std::string m_type = "Sheep";
};

class Cow: public Animal
{
public:
	Cow(const std::string &name = ""): m_name(name) {}

	virtual ~Cow() 
	{
		std::cout << "- Krowa " << m_name << " wraca do obory" << std::endl;
	}

	void print() const override
	{
		std::cout << "- Krowa " << m_name << std::endl;
	}

	std::string name() const override
	{
		return m_name;
	}

private:
	std::string m_name = "";
	std::string m_type = "Cow";
};

class Horse: public Animal
{
public:
	Horse(const std::string &name = ""): m_name(name) {}

	virtual ~Horse() 
	{
		std::cout << "- Krowa " << m_name  << " wraca do stajni" << std::endl;
	}

	void print() const override
	{
		std::cout << "- Kon " << m_name << std::endl;
	}

	std::string name() const override
	{
		return m_name;
	}
private:
	std::string m_name = "";
	std::string m_type = "Cow";
};