#include <iostream>
#include <stdexcept>

class Fraction 
{
public:
    Fraction(int l=0,  int m=1) noexcept: _l(l), _m(m)
    {
        if(_m==0)
            throw std::runtime_error("Invalid denominator");
    }

private:
    int _l = 0;
    int _m = 1;
};


int main()
{
    try
    {
        Fraction f(1,0);
    }
    catch(std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
}


/*
output:

/Users/apple/Desktop/STUDIA/IV.SEM/PO/Playground/Exam/Ex2.cpp:10:13: warning: 'Fraction' has a non-throwing exception specification but can still throw [-Wexceptions]
            throw std::runtime_error("Invalid denominator");
            ^
/Users/apple/Desktop/STUDIA/IV.SEM/PO/Playground/Exam/Ex2.cpp:7:5: note: function declared non-throwing here
    Fraction(int l=0,  int m=1) noexcept: _l(l), _m(m)

*/