//
// Created by apple on 28/02/2021.
//

#include "Complex.h"

Complex::Complex(double re, double im): _re(re), _im(im)
{

}

double& Complex:: re()
{
    return _re;
}


double& Complex:: im()
{
    return _im;
}

double Complex:: im() const
{
    return _im;
}

double Complex:: re() const
{
    return _re;
}

Complex& Complex::operator++ ()
{
    ++_re;
    ++_im;
    return *this;
}
Complex  Complex::operator++ (int i )
{
    Complex copy(*this);
    ++(*this);
    return copy;
}
Complex Complex::operator +(const Complex &cmp)
{
    return {_re + cmp._re, cmp._im+ _im};
}
Complex& Complex::operator =(int i)
{
    _re += i;
    return *this;
}


