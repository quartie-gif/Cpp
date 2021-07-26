#pragma once

#include <string>

class Operation
{
public:
	virtual ~Operation() {}
	virtual void print() const = 0;
	virtual std::string eval() const = 0;

};

void operator >>= (std::string text, Operation & operation)
{
	std::cout << text;
	operation.print();
	std::cout << text << std::endl;
}

void operator >>= (std::string text, const Operation & operation)
{
	std::cout << text;
	operation.print();
	std::cout << text << std::endl;
}