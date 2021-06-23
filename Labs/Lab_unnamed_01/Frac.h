

#ifndef LABS_BOLD_FRAC_H
#define LABS_BOLD_FRAC_H

#include <iostream>
#include <string>
#include <math.h>

class Frac{
static int Prec;
    friend Frac operator + (int i, const Frac &f);
    friend Frac operator - (const Frac &f, int i);
    friend Frac operator * (const Frac &f, int i);
    friend Frac operator * (int i, const Frac &f);
private:
    int _n;
    int _d;

public:
   Frac(int n, int d);
   Frac(double d);

   static void setCnvPrecision(int prec);


   void print(const std::string& text) const;

    Frac operator + (const Frac &f) const;

    operator double() const;

};
Frac operator + (int i, const Frac &f);
Frac operator - (const Frac &f, int i);
Frac operator * (const Frac &f, int i);
Frac operator * (int i, const Frac &f);

#endif //LABS_BOLD_FRAC_H
