#ifndef __X_CLASS_H__
#define __X_CLASS_H__
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class X {
    int size;
    int array[5];

    public:
        X();
        X(const X&);

        void print();
        void set_value_at(int, int);
};

#endif