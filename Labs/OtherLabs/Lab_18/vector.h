#pragma once

#include <iostream>


namespace MyStuff
{

    struct vector
    {
        vector(unsigned size): _size(size)
        {
            _arr = new int[size];
            for(unsigned i=0; i<size; ++i) _arr[i] = 0;
        }

        ~vector()
        {
            if(_arr != nullptr)
            {
                delete [] _arr;
            }
        }

        vector(const vector& vec)
        {
            this -> ~vector();
            _arr = new int[vec._size];

            for(unsigned i=0; i<vec._size; ++i) _arr[i] = vec._arr[i]; 

            _size = vec._size;

        }

        vector & operator = (const vector& vec)
        {
            if(this != &vec)
            {
                for(unsigned i=0; i<vec._size; ++i) _arr[i] = vec._arr[i];
                _size = vec._size;
            }
            return *this;
        }


        int & operator [] (unsigned index)
        {
            return _arr[index];   
        }

        int & operator [] (unsigned index) const 
        {
            return _arr[index];   
        }

        unsigned size() const { return _size; }


        void print(std::ostream &out) const
        {
            for(unsigned i=0; i<_size ;++i)
            {
                out << _arr[i] << " ";
            }
        }

        void push_back(int val)
        {
            int * helper = new int[_size + 1];

            for(unsigned i=0; i<_size; ++i) helper[i] = _arr[i];

            helper[_size] = val;

            ++_size;
            this -> ~vector();
            _arr = new int[_size];

            for(unsigned i=0; i<_size; ++i) _arr[i] = helper[i];

            helper = nullptr;
        }

        void pop_back()
        {
            int * helper = new int[_size - 1];

            for(unsigned i=0; i<_size - 1; ++i) helper[i] = _arr[i];

            this -> ~vector();
            --_size;
            _arr = new int[_size];
            for(unsigned i=0; i<_size; ++i) _arr[i] = helper[i];

            helper = nullptr;
        } 

        //Fields
        unsigned _size=0;
        int *_arr=nullptr;

    };

    std::ostream & operator << (std::ostream& o, const vector& vec)
    {
        vec.print(o);
        return o;
    }
};