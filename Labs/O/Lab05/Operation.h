#pragma once 
 

#include <iostream>
#include <memory>
#include <utility>

class Operation
{
public:
	Operation() = default;

	Operation(std::unique_ptr<Operation> && operation): m_operation(std::move(operation)) {} 

	virtual ~Operation() {};

	virtual void print() const {m_operation -> print();}

	virtual float eval() const {return m_operation -> eval();}

protected:
	std::unique_ptr<Operation> m_operation;
};

inline void operator >>= (const std::string & text, const Operation & other)
{
	std::cout << text << " " ;
	other.print();
	std::cout << " "  << text << std::endl;
}