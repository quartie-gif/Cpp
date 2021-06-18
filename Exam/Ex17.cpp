#include <iostream>
#include <memory>

namespace OOP{
template<typename T>
	class Array
	{

		unsigned _size, _max_size; T *_t;
	public:

		using value_type = T;

		Array(unsigned max_size): _max_size(max_size), _size(0) {_t = new T[max_size]; }

		Array<T> & insert(T znak)
		{
			// if(_size == _max_size)
			_size ++;
			_t[_size - 1] = znak;
			return *this;
		}

		Array<T> & insert(const char* znak)
		{
			// if(_size == _max_size)
			_size ++;
			_t[_size - 1] = znak[0];

			return *this;
		}

		Array<T> & operator % (T znak)
		{
			// if(_size == _max_size)

			this -> insert(znak);
			return *this;
		}

		Array<T> & operator % (const char* znak)
		{
			// if(_size == _max_size)

			this -> insert(znak);
			return *this;
		}

		value_type & operator [] (unsigned index)
		{
			// if(index >= _size)
			return _t[index];
		}

		value_type & operator [] (unsigned index) const
		{
			// if(index >= _size)
			return _t[index];
		}

		unsigned operator ~ () const
		{
			return _size;
		}



	};

};

int main()
{
	typedef OOP::Array<int> type;

	type a(10);

	a.insert('#'-1).insert('P') % type::value_type('O')%('-')%('E')%('G')%('Z')%('1');
	++a[0];
	for(unsigned i=0;i != ~a; i++)
		{
			std::cout <<static_cast<char>(a[i]) << (i+1!=~a?"_":"\n");
		}
}