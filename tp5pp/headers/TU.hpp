#ifndef __TU_CLASS_H__
#define __TU_CLASS_H__
#include <iostream>
using namespace std;


class U2 {
    int number;

    public:
        U2(int nbr = 0) { number = nbr; };
        ~U2();
};

class TUTU {
    U2* u;

    public:
        TUTU();
        ~TUTU();
        TUTU(int);
        TUTU(U2*);
};

#endif