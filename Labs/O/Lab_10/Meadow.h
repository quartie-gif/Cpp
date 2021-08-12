#pragma once

#include <iostream>
#include <array>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include "Animal.h"
#include "Animals.h"

class Meadow
{
public:

	void add(std::unique_ptr<Animal> && animal)
	{
		m_vec.push_back(std::move(animal));
	}

	void print(const std::string &text) const 
	{
		std::cout << "=== " << text << "=== " << std::endl;
		for(auto &animal: m_vec)
		{
			animal->print();
		}
	}

	void countNames() const
	{
		
	}


	std::vector<Sheep *> getSheepHerd()
	{
		std::vector<Sheep *> v;

		return v;
	}

private:
	std::vector<std::unique_ptr<Animal>> m_vec;
};