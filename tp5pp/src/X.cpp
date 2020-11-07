#include "../headers/X.hpp"


X::X() {
    size = sizeof(array)/sizeof(array[0]);
    srand(time(0));
    for(int i=0; i < size; i++)
        array[i] = (rand() % 10) + 1;
}

X::X(const X& x) {
    size = sizeof(array)/sizeof(array[0]);
    for(int i = 0; i < size; ++i)
        array[i] = x.array[i];
}

void X::print() {
    for(int e : array)
        cout << e << ' ';
    cout << '\n';
}

void X::set_value_at(int index, int value) {
    if (index >= 0 && index < this->size) {
        array[index] = value;
    } else {
        cout << "Index out of bounds" << endl;
    }
}