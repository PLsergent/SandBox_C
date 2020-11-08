#include "../headers/AB.hpp"


B::B() {
    A a;
    cout << "Create AB... constructor 1" << endl;
}

B::B(int nbr) {
    A a(nbr);
    cout << "Create AB... constructor 2" << endl;
}

B::B(A new_a) {
    a = new_a;
    cout << "Create AB... constructor 3" << endl;
}