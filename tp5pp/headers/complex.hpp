#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
using namespace std;


class Complex {
    double real;
    double imag;

    public :
        Complex(double real_ = 0, double imag_ = 0) {
            real = real_;
            imag = imag_;
        }

        double _real() { return real; }
        double _imag() { return imag; }

        void print();

        friend Complex operator + (Complex&, Complex&);
        friend Complex operator - (Complex&, Complex&);
        friend Complex operator * (Complex&, Complex&);
        friend Complex operator / (Complex&, Complex&);
//----------------------------------------------
};

#endif