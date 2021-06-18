#include <iostream>



template<typename T = double>
struct box
{
	box(T val): a(val) {}

	operator unsigned () const { return static_cast<unsigned>(a); }

    operator double () const { return static_cast<double>(a); }
    T a;
};



int main()
{
	box<> b1 = 3.14;
	box<unsigned> b2 = 13;
	double d = b1;
	unsigned u = b2;
}