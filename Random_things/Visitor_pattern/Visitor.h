# pragma once

#include "ElData.h"

class IntData;
class FloatData;


class Visitor{
public:
    virtual void visit(FloatData* data) = 0;
    virtual void visit(IntData* data) = 0;
};