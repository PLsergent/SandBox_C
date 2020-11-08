#include "../headers/TU.hpp"


TUTU::TUTU() {
    u = new U2();
    cout << "Create TU... constructor 1" << endl;
}

TUTU::TUTU(int nbr) {
    u = new U2(nbr);
    cout << "Create TU... constructor 2" << endl;
}

TUTU::TUTU(U2* u_) {
    u = u_;
    cout << "Create TU... constructor 3" << endl;
}

U2::~U2() {}

TUTU::~TUTU() {
    delete u;
}