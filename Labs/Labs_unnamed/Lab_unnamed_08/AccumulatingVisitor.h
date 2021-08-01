#pragma once

#include <iostream>
#include "Visitor.h"

class AccumulatingVisitor: public Visitor{

public:
	void visit(Data *data) override;

	inline float getTotalSum() const { return _sum; }
private:
	float _sum;
};

void AccumulatingVisitor::visit(Data *data)
{
	if(dynamic_cast<IntData*>(data))
	{
		_sum += dynamic_cast<IntData*>(data) -> get();
	}
	else if(dynamic_cast<FloatData*>(data))
	{
		_sum += dynamic_cast<FloatData*>(data) -> getFloat();
	}
}