

#include <iostream> 
#include "Templates.h"

int main()
{

	std::cout << Sum(1.,2.) << "\n";
	std::cout << Max(1.,2.) << "\n";

	Parr<double> Ob1(1.3, 2.3);
	Ob1.print();
	std::cout << Ob1.getFirst() << std::endl;


	return 0;
}