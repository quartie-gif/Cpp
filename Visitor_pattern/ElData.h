#pragma once

#include "Visitor.h"

class ElData{
public:

    virtual void acceptVisitor(Visitor& v) = 0;
};

class FloatData: public ElData{
public:
    explicit FloatData(float f): _f(f) {};
    void acceptVisitor(Visitor& v) override {v.visit(this);}
    float get_value() const {return _f;}
    void operator <<(float f)
    {
        _f = f;
    }
private:
    float _f;
};

class IntData: public ElData{
public:
    explicit IntData(int i): _i(i) {};
    void acceptVisitor(Visitor& v) override {v.visit(this);}
    int get_value() const {return _i;}
    void operator <<(int i)
    {
        _i = i;
    }
private:
    int _i;
};