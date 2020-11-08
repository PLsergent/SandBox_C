#include "../headers/D.hpp"


D::D(char* c) {
    size = strlen(c);
    s = new char[size + 1];
    strcpy(s, c);
    cout << "Create object..." << s << endl;
}

D::~D() {
    cout << "Delete object..." << s << endl;
    delete[] s;
/* 
- A local (automatic) object with block scope goes out of scope.
- An object allocated using the new operator is explicitly deallocated using delete.
- The lifetime of a temporary object ends.
- A program ends and global or static objects exist.
- The destructor is explicitly called using the destructor function's fully qualified name.
- Destructors can freely call class member functions and access class member data.
- There are two restrictions on the use of destructors:
- You cannot take its address.
- Derived classes do not inherit the destructor of their base class.
*/
}