#ifndef UNTITLED_COMPLEXNUMBER_H
#define UNTITLED_COMPLEXNUMBER_H

#include <iostream>
#include <string>
#include <math.h>


class ComplexNumber{
    friend ComplexNumber operator + (int i,const ComplexNumber &cn);
    friend std::ostream& operator<<(std::ostream& strm, const ComplexNumber &cn);
private:
    int _re;
    int _im;
public:
    static int i;
    static int IMAGINARY;
    static int REAL;

    ComplexNumber(int re, int im);
    ComplexNumber(int im);

    ComplexNumber operator + (const ComplexNumber &cn) const;
    ComplexNumber operator * (const ComplexNumber &cn) const;
    ComplexNumber operator - (const ComplexNumber &cn) const;

    ComplexNumber operator *= (int x) const;
    ComplexNumber operator += (int x) const;
    ComplexNumber operator ++ (int i);
    ComplexNumber operator++ ();

    int& operator [](int &x);
    bool operator > (const ComplexNumber &cn) const;
    
};

ComplexNumber operator + (int i,const ComplexNumber &cn);
std::ostream& operator<<(std::ostream& strm, const ComplexNumber &cn);

#endif //UNTITLED_COMPLEXNUMBER_H
