#include <iostream>
#include <typeinfo>
#include "classes.h"


int main(int argc, char const *argv[])
{
	
	X x;
	Y y;
	const Z z;
	X *Xptr = &x;

	static_cast<X&>(y).print();

	try{
		x = dynamic_cast<X&>(y);
		x.print();

		Z z_2 = const_cast<Z&>(z);
		z_2.print();

		Y y_2 = static_cast<Y&>(x);
		y_2.print(); 
	} catch(const std::bad_cast &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}