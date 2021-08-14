#pragma once

#include <iostream>

class FloatWrapper: public Wrapper
{
    public:
        //Constructor for FloatWrapper class
        FloatWrapper(float val): _val(val) {}

        //Method that copies an object of this class
        Wrapper * copyObject() const override
        {
            return new FloatWrapper(_val);
        }

        //Method that helps to print object of this class
        void print(std::ostream &out) const override
        {
            out << _val;
            out << " ";
        }

    private:
        float _val;
};