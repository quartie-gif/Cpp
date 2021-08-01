#pragma once

#include <iostream>
#include "Visitor.h"

class PrintingVisitor: public Visitor{

public:
	void visit(Data *data) override;

private:

};

void PrintingVisitor::visit (Data *data)
{
	if(dynamic_cast<IntData*>(data))
	{
		std::cout << " " <<  dynamic_cast<IntData*>(data) -> get();
	}
	else if(dynamic_cast<FloatData*>(data))
	{
		std::cout << " " <<  dynamic_cast<FloatData*>(data) -> getFloat();
	}
}