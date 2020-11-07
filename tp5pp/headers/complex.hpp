#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
using namespace std;


class Complex {
    double real;
    double imag;

    public:
        Complex();
        Complex(const Complex&);
        Complex(double, double);

        double _real() { return real; }
        double _imag() { return imag; }

        void print();

        friend Complex operator + (Complex&, Complex&);
        friend Complex operator - (Complex&, Complex&);
        friend Complex operator * (Complex&, Complex&);
        friend Complex operator / (Complex&, Complex&);
};

#endif