#include <typeinfo>
#include <iostream>
#include <array>
#include <vector>
#include <string>


template<typename T>
void memcopy(T &a, T &b, size_t size)
{
    if(std::is_pod<T>::value)
    {
        std::cout << "Copying POD type." << std::endl;
        memcpy(a, b, size);
    }
    else
    {
        std::cout << "Copying non-POD type." << std::endl;
        
    }
}

struct A{int a;}; struct B{virtual void f() {} int a; }; 

template<typename T> void test() { T src[10] = {}, dst[10];
std::cout << typeid(T).name() << " is_pod = " << std::is_pod<T>::value << ", ";
memcopy(src, dst, sizeof(src)/sizeof(T)); }


int main()
{
    test<A>() ; test<B>();
    test<std::array<A, 10>>();
    test<std::vector<A>>();

}

/*
1A is_pod = 1, Copying POD type.
1B is_pod = 0, Copying non-POD type.
NSt3__15arrayI1ALm10EEE is_pod = 1, Copying POD type.
NSt3__16vectorI1ANS_9allocatorIS1_EEEE is_pod = 0, Copying non-POD type.
apple@MBP-apple Exam % 
*/