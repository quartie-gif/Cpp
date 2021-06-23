#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <list>
#include <array>


class Car
{
public:
	Car(const std::string &name): m_brand(name) {};
	const std::string &getBrand() const {return m_brand;}
private:
	std::string m_type;
	std::string m_brand;
};

template <typename T>
class Cars
{
public:
	Cars() = default;
	void print() const
	{
		std::cout << "List of Cars :\n";
		int i = 1;
		for(auto iter: m_listCars)
		{
			std::cout << i++ << ". " <<iter->getBrand() << "\n";
		}
	}
	Cars &add(std::shared_ptr<T> el)
	{
		m_listCars.push_back(el);
		return *this;
	}

private:
	std::list <std::shared_ptr<T> > m_listCars;
};

