#ifndef __D_CLASS_H__
#define __D_CLASS_H__
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class D {
    private:
    char* s;
    int size;
 
    public:
        D(char*); // constructor
        ~D(); // destructor
};

#endif