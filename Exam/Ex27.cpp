#include <iostream>

struct A{A(){std::cout<<"A,";}};
struct B{B(){std::cout<<"B,";}};
struct X : virtual public A, private B {X(){std::cout<<"X,";}};
struct Y : virtual public A, private B {Y(){std::cout<<"Y,";}};
struct Z : public Y, public X {Z(){std::cout<<"Z,";}};

int main()
{
    Z test;
}

//Output : A, B, 