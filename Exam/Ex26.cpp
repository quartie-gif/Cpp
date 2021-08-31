//
#include <iostream>

namespace oop
{
    template<typename T>
    struct Array
    {
        using value_type = T;
        explicit Array(unsigned maxsize): _maxsize(maxsize)
        {
            _arr = new T[maxsize + 1];
            _arr[maxsize] = '\0';
        }

        ~Array()
        {
            delete [] _arr;
        }

        Array<T>& insert(char element)
        {
            _arr[_current] = element;
            ++_current;

            return *this;
        }

        T& operator [] (int index) const
        {
            return _arr[index];
        }

        Array<T>& operator + (char element)
        {
            
            return this -> insert(element);;
        }

        int operator ~ ()
        {
            return _maxsize;
        }

        int _maxsize = 0, _current = 0;
        T * _arr = nullptr;
    };

}

namespace std{class vector{};class list{};class deque{}; class set{};class map{};}
#include <cstdlib>

int main()
{
  typedef oop::Array<char> type;
  type a(rand() % 10 + 6);//maks rozmiar tablicy
  a.insert('#').insert('C')+type::value_type('+')+'+'+'0'+('0'+3);



  for(unsigned i = 0;i != ~a ;i++)
  std::cout<< a[i] << (i+1 != ~a ? "" : "\n");
  
}
//#C++003