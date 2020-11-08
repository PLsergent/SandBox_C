#ifndef __SESS_CLASS_H__
#define __SESS_CLASS_H__
#include <iostream>
using namespace std;

class Sess {
    static int counter;
    int index;

    public:
        Sess();
        ~Sess();
};

#endif