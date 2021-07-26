#include<iostream>

class A
{
public:
    A(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
    ~A(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class B
{
public:
    B(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
    ~B(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class X: virtual public A, public B
{
public:
    X(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
    ~X(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class Y: virtual public A, public B
{
public:
    Y(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
    ~Y(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

class Z: public X, public Y
{
public:
    Z(){std::cout<<__PRETTY_FUNCTION__<<"\n";}
    ~Z(){std::cout<<__PRETTY_FUNCTION__<<"; ";}
};

int main() {Z z;}
//