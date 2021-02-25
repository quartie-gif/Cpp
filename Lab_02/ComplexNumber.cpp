#include "ComplexNumber.h"

int ComplexNumber::i = 0;
int ComplexNumber::IMAGINARY =0;
int ComplexNumber::REAL = 0;


ComplexNumber::ComplexNumber(int re, int im): _re(re), _im(im)
{
    ComplexNumber::i++;
}
ComplexNumber::ComplexNumber(int im)
{
    ComplexNumber::i++;

}



ComplexNumber ComplexNumber::operator + (const ComplexNumber &cn) const
{
    return {_re + cn._re, _im +cn._im};
}
ComplexNumber ComplexNumber::operator * (const ComplexNumber &cn) const
{
    return { _re * cn._re - _im* cn._im, _im + cn._re*_im + cn._im*_re};
}
ComplexNumber ComplexNumber::operator - (const ComplexNumber &cn) const
{
    return {_re - cn._re, _im - cn._im};
}

ComplexNumber ComplexNumber::operator *= (int x) const
{
    return {_re*x, _im*x};
}
ComplexNumber ComplexNumber::operator += (int x) const
{
    return {_re+x, _im};
}
ComplexNumber ComplexNumber::operator ++ (int i)
{
    return {_re++, _im++};
}
ComplexNumber ComplexNumber::operator++ ()
{
    return {++_re, ++_im};
}

bool ComplexNumber::operator > (const ComplexNumber &cn) const
{
    double r_1 = sqrt(pow(_re,2) + pow(_im,2));
    double r_2 = sqrt(pow(cn._re,2) + pow(cn._im,2));
    return r_1 > r_2;
}

int& ComplexNumber::operator [](int &x)
{
    return x;
}


ComplexNumber operator + (int i,const ComplexNumber &cn)
{
    return {i+cn._re, cn._im};
}

std::ostream& operator<<(std::ostream& strm, const ComplexNumber &cn)
{
   return strm << cn._re << " + "<<cn._im <<"i";
}
