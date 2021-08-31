#include <iostream>
#include <string>

struct is_printable
{
    virtual void print(std::ostream & o) const = 0 ;
};

struct A: public is_printable
{
    A(std::string val): _val(val) {}

    void print(std::ostream & o) const 
    {
        o << _val;
    }

    std::string _val;
};
struct B: public is_printable
{
    B(int val): _val(val) {}

    void print(std::ostream & o) const 
    {
        o << _val;
    }

    int _val;
};

std::ostream & operator<<(std::ostream & s,const is_printable & o)
{
    o.print(s);
    return s;
}

std::ostream & operator<<(std::ostream & s,const is_printable & o);
//nie ma żadnej więcej funckji o sygnaturze operator<<..



int main()
{
  A a ("Tekst"); B b {123};
  std::cout<< "a:\t"<<a<<"; b:\t"<<b<<"\n";
  const is_printable & a_r = a; const is_printable & b_r = b;
   std::cout<< "a_r:\t"<<a_r<<"; b_r:\t"<<b_r<<"\n";
}

/*
a     tekst     b 123
a_r   tekst     b_r 123
*/