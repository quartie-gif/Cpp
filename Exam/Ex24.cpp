#include <iostream>
#include <typeinfo>

struct A { ~A() {std::cout << "~A()\n"; } };

template<typename T> struct B: A {
    T v = T();
    B() = default;
    B(const B& b): v(b.v) {std::cout << "Copy " << typeid(B<T>).name() << "()\n"; }
};
 
int main()
{
    typedef B<A> B_A;
    using TypeName = B<B_A>;
    TypeName a = TypeName(TypeName);
    TypeName b(a);
}