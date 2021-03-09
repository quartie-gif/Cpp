#pragma once

#include "Visitor.h"

class PrintingVisitor: public Visitor{
public:
    virtual void visit(FloatData* data) {std::cout << " "<< data->get_value();}
    virtual void visit(IntData* data) {std::cout << " "<< data->get_value();}
private:

};

