// Cwiczenie dziedziczenia

#include <iostream>



class A{ public : A(){std::cout << "A, ";}; ~A(){std::cout << "~A, ";}};
class B{ public : B(){std::cout << "B, ";}; ~B(){std::cout << "~B, ";}};
class C{ public : C(){std::cout << "C, ";}; ~C(){std::cout << "~C, ";}};


class X: private A, virtual public C {public : X(){std::cout << "X, ";}; ~X(){std::cout << "~X, ";}}; 
class Y: public B, virtual public C {public : Y(){std::cout << "Y, ";}; ~Y(){std::cout << "~Y, ";}};
class Z: public X, public Y{};




int main()
{
	X ob_1;
	Y ob_2;

	std::cout << std::endl;
	return 0;
}

/*Output : 
C, A, X, C, B, Y, 
~Y, ~B, ~C, ~X, ~A, ~C,
*/