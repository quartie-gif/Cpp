#include "LicznikPoziomow.h"

int LicznikPoziomow::_counter{0};

LicznikPoziomow::LicznikPoziomow() 
{
	++_counter;
	std::cout << "Rozpoczynamy poziom numer " << _counter << std::endl;
}

LicznikPoziomow::~LicznikPoziomow() 
{
	std::cout << "Konczymy poziom numer " << _counter << std::endl;
	_counter--;
	
}