#pragma once 

//INCLUDES
#include <iostream>
#include <utility>

class Wrapper
{
    public:
        Wrapper() = default;
        virtual Wrapper * copyObject() const = 0;
        virtual void print(std::ostream &out) const = 0;
        virtual ~Wrapper() = default;
};

class PArr
{
    public:
        //Default constructor that initilize an array of specific size
        PArr(unsigned size): _size(size) 
        {
            _arr = new Wrapper *[size];
        }

        //Destructor
        ~PArr()
        {
            for(int i=0; i<_size; ++i)
            {
                delete _arr[i];
            }
            delete [] _arr;
        }

        //Copy constructor
        PArr(const PArr& arr): _size(arr._size)
        {
            for (int i = 0; i < _size; i++)
            {
                _arr[i] = arr._arr[i]->copyObject();
            }
        }

        //Move constructor
        PArr(PArr && arr):
        _size(std::exchange(arr._size, 0)),
        _arr(std::exchange(arr._arr, nullptr))
        {

        }

        //Overloaded operator [] that accesses the element at specific index to modify it
        Wrapper *& operator [] (unsigned index)
        {
            return _arr[index];
        }

        //Overloaded operator [] that accesses the element at specific index to read it
        const Wrapper * operator [] (unsigned index) const
        {
            return _arr[index];
        }

        //Overloading of operator =
        void operator = (const PArr & arr) 
        {
            for(int i=0; i<_size; ++i)
            {
                delete _arr[i];
            }
            delete [] _arr; 

            _arr = new Wrapper* [arr._size];
            
            for (int i = 0; i < _size; i++)
            {
                _arr[i] = arr._arr[i]->copyObject();
            }

	    }

        //Method that helps to print out the PArr
        void print(std::ostream &out) const
        {
            for(int i=0; i<_size; ++i)
            {
                _arr[i]->print(out);
            }
        }

    private:
        unsigned _size = 0;         //Size of an array
        Wrapper ** _arr = nullptr;   //An array of pointers to pointers to Wrappers
};

//Overloaded operator << for striming out the content of PArr's objects
std::ostream & operator << (std::ostream &out, const PArr& arr)
{
    arr.print(out);
    return out;
}