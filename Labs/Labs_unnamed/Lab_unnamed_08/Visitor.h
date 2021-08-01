#pragma once

#include "Data.h"

class Visitor{
public:
	Visitor() = default;
	~Visitor() = default;

	virtual void visit(Data *data) = 0;

};
