#ifndef __Y_CLASS_H__
#define __Y_CLASS_H__
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class Y {
    int size = 5;
    int * dyn_array = new int [size];

    public:
        Y();
        Y(const Y&);

        void print();
        void set_value_at(int, int);
};

#endif
