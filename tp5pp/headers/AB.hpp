#ifndef __AB_CLASS_H__
#define __AB_CLASS_H__
#include <iostream>
using namespace std;

class A {
    int number;

    public:
        A(int nbr = 0) { number = nbr; };
};


class B {
    A a;

    public:
        B();
        B(int);
        B(A);
};

#endif