#pragma once 

#include<iostream>
#include<utility>
#include<string>

class MyArray
{
    public:
        //Constructor
        MyArray(unsigned size): _size(size), _next(nullptr)
        {
            _arr = new int[size];
        }

        //Destructor
        ~MyArray()
        {
            delete [] _arr;  
        }


        //Copy constructor
        MyArray(const MyArray & arr): _size(arr._size), _next(arr._next)
        {
            if(_arr) delete [] _arr;

            _arr = new int[arr._size];
            for(unsigned i=0; i< arr._size; ++i)
            {
                _arr[i] = arr._arr[i];
            }
        }

        //Copy assignment operator 
        MyArray& operator = (const MyArray & arr)
        {
            if(this != &arr)
            {
                _size = arr._size;
                _next = arr._next;

                if(_arr) delete [] _arr;
                _arr = new int[arr._size];

                for(unsigned i=0; i< arr._size; ++i)
                {
                    _arr[i] = arr._arr[i];
                }
            }
            return *this;
        }

        //Move constructor
        MyArray(MyArray && arr): _size(arr._size), _next(arr._next)
        {
            if(_arr) delete [] _arr;

            _arr = new int[arr._size];
            for(unsigned i=0; i< arr._size; ++i)
            {
                _arr[i] = arr._arr[i];
            }
            // delete [] arr._arr;
            arr._size = 0;
            arr._next = nullptr;
        }

        //Move assignment operator 
        MyArray& operator = (MyArray && arr)
        {
            if(this != &arr)
            {
                _size = arr._size;
                _next = arr._next;
                
                if(_arr) delete [] _arr;
                _arr = new int[arr._size];

                for(unsigned i=0; i< arr._size; ++i)
                {
                    _arr[i] = arr._arr[i];
                }

                arr._size = 0;
                arr._next = nullptr;
                // delete [] arr._arr;
            }
            return *this;
        }

        //Method that returns size of an array
        unsigned size() const { return _size; }

        //Method that helps print single array
        std::ostream & print(std::ostream &out) const
        {
            out << "";
            if(_arr != nullptr and _size > 0)
            {
                out << "[";
                for(unsigned i=0; i< _size - 1; ++i)
                {
                    out << _arr[i] << " ,";
                }
                out << _arr[_size -1] << "]";
            }
            return out;
        }
        

        //Method that helps print linked list of arraies
        void print(const std::string &text) const
        {
            std::cout << text;
            if(_arr != nullptr and _size > 0)
            {
                print(std::cout);

                if(_next != nullptr)
                {
                    _next->print("");
                }
            }

        }
        
        

        //Overloaded [] operator
        int & operator [] ( unsigned index) const
        {
            return _arr[index];
        }

        // Define postfix increment operator
        MyArray & operator ++ (int x)
        {
            
            for(unsigned i =0; i< _size; ++i)
            {
                _arr[i]++;
            }
            return *this;
        }

        // Define prefix decrement operator.
        MyArray & operator -- ()
        {
            
            for(unsigned i =0; i< _size; ++i)
            {
                --_arr[i];
            }
            return *this;
        }
        
        //Array concatenation
        void operator += (MyArray& arr)
        {
            this -> _next = &arr;
        }

        //Array concatenation
        void operator += (MyArray&& arr)
        {
            int * temp = new int[this->_size + arr._size];

            for(unsigned i=0; i<_size + arr._size; ++i)
            {
                
                if(i >= _size)
                {
                    temp[i] = arr._arr[i - _size];
                }
                else
                {
                    temp[i] = _arr[i];
                }
            }

            _size = _size + arr._size;
            _arr = new int[_size];
            _arr = temp;
            
        }

        MyArray & getNext() const
        {
            return *_next;
        }

    private:
        unsigned _size = 0;
        int * _arr = nullptr;
        MyArray *   _next = nullptr;
};

std::ostream & operator << (std::ostream & out, const MyArray &arr)
{
    return arr.print(out);
}