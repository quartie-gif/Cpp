#pragma once

#include <iostream>
#include <cstring>

class StringWrapper: public Wrapper
{
    public:
        //Constructor for StringWrapper class
        StringWrapper(const char * val)  
        {
            _size = strlen(val) + 1;
            _val = new char[_size];
            strcpy(_val, val);
        }

        //Destructor
        ~StringWrapper()
        {
            delete[] _val;
        }

        //Method that copies an object of this class
        Wrapper * copyObject() const override
        {
            return new StringWrapper(_val);
        }

        //Method that helps to print object of this class
        void print(std::ostream &out) const override
        {
            out << _val;
            out << " ";
        }

    private:
        char * _val = nullptr;
        unsigned _size = 0;
};