#pragma once 

#include <iostream>
#include <array>

/***
*   @brief Class that represents an array of elements of type parameterized by T
*/
template<int size, typename T>
class Array
{
    public:
        //Constructor
        Array()
        {
            
        }

        //Method that prints out content of an array
        void print(std::ostream &out) const 
        {
            for(const auto &it: _arr)
            {
                out << it << " ";
            }
        }

        //Overloaded operator [] for changing a content of an array
        T& operator [] (unsigned index)
        {
            return _arr[index];
        }

        //Overloaded operator [] for reading a content of an array
        T& operator [] (unsigned index) const
        {
           return _arr[index]; 
        }

    private:
        std::array<T, size> _arr = {};
};

//Overloaded operator for striming
template<int size, typename T>
std::ostream & operator << (std::ostream &out, const Array<size , T> arr)
{
    arr.print(out);
    return out;
}

template <int size, typename T>
class Array<size, T*> 
{
    public:
            //Constructor
            Array()
            {

            }
            //Destructor
            ~Array()
            {
                for (auto it: _arr) 
                {
                    delete it;
                }
            }

            //Method that prints out content of an array
            void print(std::ostream &out) const 
            {
                for(const auto *it: _arr)
                {
                    if(it)
                    {
                        out << *it << " ";
                    }
                }
            }

            //Overloaded operator [] for changing a content of an array
            T*& operator [] (unsigned index)
            {
                return _arr[index];
            }

            //Overloaded operator [] for reading a content of an array
            T*& operator [] (unsigned index) const
            {
                return _arr[index];
            }

        private:
            std::array<T*, size> _arr = {};
};

//Overloaded operator for striming
template<int size, typename T>
std::ostream & operator << (std::ostream &out, const Array<size , T*> arr)
{
    arr.print(out);
    return out;
}