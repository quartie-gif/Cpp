#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
	explicit Animal () {}
	virtual ~Animal() {}
	virtual void print() const = 0;
	virtual std::string name() const = 0;
protected:

};