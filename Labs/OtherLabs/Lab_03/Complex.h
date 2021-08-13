#ifndef UNTITLED2_COMPLEX_H
#define UNTITLED2_COMPLEX_H

#include <iostream>

class Complex{

friend std::ostream& operator << (std::ostream& strm, const Complex &cmp);

private:
    double _re;
    double _im;
public:

    Complex(double re, double im);

    double& re();
    double re() const;
    double& im();
    double im() const;


    Complex& operator++ ();
    Complex  operator++ (int i );
    Complex operator +(const Complex &cmp);
    Complex& operator =(int i);


};


inline std::ostream& operator << (std::ostream& strm, const Complex &cmp)
{
    return strm<<"("<<cmp._re<<" + "<<cmp._im<<"*i)";
}

#endif //UNTITLED2_COMPLEX_H
