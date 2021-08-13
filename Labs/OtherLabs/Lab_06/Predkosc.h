#pragma once

#include <iostream>

class PredkoscMaksymalna
{
public:
	PredkoscMaksymalna(int velocity = 0 ): _vel(velocity) {}

	void print(std::ostream &o) const
	{
		o << _vel;
	}
	int _vel;
};

std::ostream & operator << (std::ostream &o, const PredkoscMaksymalna &obj)
{
	obj.print(o);
	return o;
}