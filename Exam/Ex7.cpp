// czy poniższy kod jest poprawny? jeśli tak, to co się wyświetli + uzasadnienie
// Kod:
#include <iostream>

using namespace std;

struct A { ~A() { cout << "~A\n"; } };
struct B { ~B() { cout << "~B\n"; } };
struct X : virtual public A, private B { ~X() { cout << "~X\n"; } };
struct Y : virtual public A, private B { ~Y() { cout << "~Y\n"; } };
struct Z : public X, public Y { ~Z() { cout << "~Z\n"; } };


int main() {
	Z test;
	return 0;
}

// kod jest poprawny,


/*
output:
~Z
~Y
~B
~X
~B
~A
*/