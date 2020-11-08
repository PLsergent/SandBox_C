#ifndef __D_CLASS_H__
#define __D_CLASS_H__
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class D {
    char* s;
    int size;
 
    public:
        D(char*);
        ~D();
};

#endif