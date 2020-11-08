#ifndef __2D_array_CLASS_H__
#define __2D_array_CLASS_H__
#include <iostream>
using namespace std;


class O {
    int number;

    public:
        O(int nbr = 0) { number = nbr; cout << "Create O..." << number << endl; }
        ~O() { cout << "Delete O..." << number << endl; }
};

class T {
    int size_col;
    int size_row;
    O** dyn2_array;

    public:
        T(int, int);
        T(const T&);
        ~T();

        void print();
        void set_value_at(int, int, O);
};

#endif