#pragma once

#include <iostream>


namespace MyStuff
{
    class vector
    {
        public:
            //Constructor
            vector(unsigned size): _size(size) 
            {
                _args = new int[size];
            }
            //Destructor
            ~vector() 
            { 
                if(_args)
                {
                    delete[] _args;
                    _size = 0;
                }
                _args = nullptr;
            }

            //Assignment operator overloading
            vector(const MyStuff::vector& vec)
            {
                _size = vec._size;
                _args = new int[vec._size];
                for(int i=0; i<vec._size; ++i)
                {
                    _args[i] = vec[i];
                }
            }

            //Overloaded operator [] that access that in _args at specific index to modify it
            int & operator [] (unsigned index)
            {
                return _args[index];
            }

            //Overloaded operator [] that access that in _args at specific index to read it
            int & operator [] (unsigned index) const
            {
                return _args[index];
            } 

            //Method that prints out the vector to stream o
            void print(std::ostream &o) const 
            {
                for(int i=0; i<_size; ++i)
                {
                    o << _args[i] << " ";
                }

            }

            //Method that returns a size of vector;
            unsigned size() const 
            { 
                return _size;
            }

            //Method that pushes the argument at the end
            void push_back(int arg)
            {
                int *temp_arr = new int[_size + 1];
                for (size_t i = 0; i < _size; i++)
                {
                    temp_arr[i] = _args[i];
                }

                delete[] _args;
                _args = temp_arr;
                _args[_size] = arg;
                _size ++;
            }

           //Method that pops the argument at the end
            void pop_back() 
            {
                int *temp_arr = new int[_size - 1];
                for (size_t i = 0; i < _size - 1; i++)
                {
                    temp_arr[i] = _args[i];
                }

                delete[] _args;
                _args = temp_arr;
                --_size;
            }

        private:
            int * _args = nullptr;        //Dynamic array of ints
            unsigned _size = 0;     //Size of an array
    };

    std::ostream & operator << (std::ostream &o, const MyStuff::vector& vec)
    {
        vec.print(o);
        return o;
    }

};



