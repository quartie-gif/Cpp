#pragma once

#include "Visitor.h"

class AccumulatingVisitor: public Visitor{
public:
    virtual void visit(FloatData* data) {_sum += data->get_value();}
    virtual void visit(IntData* data) {_sum += static_cast<float>(data->get_value());}
    float getTotalSum(){return _sum;}
private:
    float _sum;

};