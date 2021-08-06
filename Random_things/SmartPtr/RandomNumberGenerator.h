#pragma once

#include <iostream>
#include <random>
#include <memory>
#include "SmartPointer.h"

using IntDeleter = Deleter<int>;

void RandomGenerator()
{
	std::random_device seed;
	//Generator
	std::mt19937 engine(seed());
	//Distribution
	std::uniform_int_distribution<int> thousand(1, 1000);
	int randomNumber = thousand(engine);
	for(unsigned i=0; i <= randomNumber; ++i) std::shared_ptr<int>(new int(i), IntDeleter());
};