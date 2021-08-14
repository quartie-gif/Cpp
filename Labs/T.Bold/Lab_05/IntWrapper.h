#pragma once

#include <iostream>

class IntWrapper: public Wrapper
{
    public:
        //Constructor for IntWrapper class
        IntWrapper(int val): _val(val) {}

        //Method that copies an object of this class
        Wrapper * copyObject() const override
        {
            return new IntWrapper(_val);
        }

        //Method that helps to print object of this class
        void print(std::ostream &out) const override
        {
            out << _val;
            out << " ";
        }

    private:
        int _val;
};