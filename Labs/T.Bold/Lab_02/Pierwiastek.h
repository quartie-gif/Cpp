#pragma once
#include "Argumenty.h"
#include <cmath>

class Pierwiastek: public Algo
{
public:
	Argumenty wykonaj(const Argumenty & arg) const override 
	{
		Argumenty temp(arg.getSize());

		for(int i = 0; i<arg.getSize(); ++i)
		{
			temp[i] = sqrt(arg[i]);
		}
		return temp;

	}

	Pierwiastek*  sklonuj() const override
	{
		return new Pierwiastek();
	}
};