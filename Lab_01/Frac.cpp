//
// Created by apple on 24/02/2021.
//

#include "Frac.h"

int Frac :: Prec = 0;

Frac::Frac(int n, int d): _n(n), _d(d)
{
    if(d == 0)
    {
        return;
    }
}

Frac::Frac(double d)
{
    
    int counter = 0;
    double prec = d;
    while(fmod(prec,10) != 0 and prec != Frac::Prec)
    {
        prec *= 10;
        counter ++;
    }
    if (pow(10,counter) == 0) return ;
    _d = pow(10,counter);
    _n = d * pow(10,counter);

    Frac::Prec = 0;
}

void Frac::setCnvPrecision(int prec)
{
    Frac::Prec = prec;
}

void Frac::print(const std::string& text) const
{
    std::cout <<_n <<"/" << _d << text;
}

Frac Frac::operator + (const Frac &f) const
{
return {_n * f._d + f._n * _d, _d * f._d};
}

Frac::operator double() const
{
    return static_cast<double>(_n)/static_cast<double>(_d);
}

Frac operator + (int i, const Frac &f)
{
    return {i* f._d + f._n, f._d};
}
Frac operator - (const Frac &f, int i)
{
    return {f._n - i* f._d, f._d};
}
Frac operator * (const Frac &f, int i)
{
    return {f._n * i, f._d};
}
Frac operator * (int i, const Frac &f)
{
    return {f._n * i, f._d};

}
