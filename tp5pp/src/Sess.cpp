#include "../headers/Sess.hpp"


int Sess::counter = 0;

Sess::Sess() {
    index = counter;
    cout << "Sess counter : " << counter << endl;
    counter++;
}

Sess::~Sess() {
    counter--;
    cout << "Sess counter : " << counter << endl;
}