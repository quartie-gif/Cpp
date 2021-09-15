

#include <iostream> 
#include "Templates.h"
#include "tempTemp.h"

int main()
{

	std::cout << Sum(1.,2.) << "\n";
	std::cout << Max(1.,2.) << "\n";

	Parr<double> Ob1(1.3, 2.3);
	Ob1.print();
	std::cout << Ob1.getFirst() << std::endl;

	std::cout << "----------------------------- tempTemp ------------------------\n";

	using Type = std::pair<Float, Float>;

	A<std::pair<Float, Float>> obj(std::pair<Float, Float> (3.3, 4.3)) ;

	std::cout << "First: " << obj->_val1.first << "\tSecond: " << obj->_val1.second << std::endl;

	A<Type>* ptrA = new A<Type>(Type(1.3, 3.3));

	std::cout << *ptrA << std::endl;

	obj = obj + *ptrA;

	obj.print(std::cout);

	X<float, std::pair> other(obj._val1);




	delete ptrA;

	return 0;
}