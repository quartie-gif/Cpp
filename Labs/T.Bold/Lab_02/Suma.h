#pragma once
#include "Argumenty.h"

class Suma: public Algo
{
public:
	Argumenty wykonaj(const Argumenty & arg) const override 
	{
		Argumenty ret(1);

		for(int i = 0; i<arg.getSize(); ++i)
		{
			ret(0, arg[i]+ ret[0]);
		}
		
		return ret;

	}

	Suma*  sklonuj() const override
	{
		return new Suma();
	}
};