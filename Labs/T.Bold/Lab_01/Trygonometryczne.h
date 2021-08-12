#pragma once 
#include <cmath>


class Sinus: public Fun
{
public:
	double wartosc(double x) override {return sin(x);}
protected:

};