#ifndef __PUBLIC_OR_PRIVATE_H__
#define __PUBLIC_OR_PRIVATE_H__
#include <iostream>
using namespace std;

class Base {

    int default_attribute = 1;

    private: 
        int private_int = 2;
    protected: 
        int protected_int = 3;
    public:
        int public_int = 4;

        int get_default_attribute() { return default_attribute; }
        int get_private_int()       { return private_int; }
        int get_protected_int()     { return protected_int; }
        int get_public_int()        { return public_int; }
};

class Derived : Base {
    public:
        int _default() { 
            cout << "Inacessible ";
            return -1;
        } // default_attribute is inacessible so the default_attribute is private

        int _private() { 
            cout << "Inacessible " ;
            return -1;
        } // private_int is inacessible

        int _protected()    { return protected_int; }       // OK  
        int _public()       { return public_int; }          // OK
};

class Unrelated  {
    private:
        Base B;
    public:
        int _default() { 
            cout << "Inacessible ";
            return -1;
        }   // B.default_attribute is inacessible

        int _private() { 
            cout << "Inacessible ";
            return -1;
        }   // B.private_int is inacessible

        int _protected() { 
            cout << "Inacessible ";
            return -1;
        }   // B.protected_int is inacessible

        int _public() { return B.public_int; } // OK
};

#endif