#include "../headers/Y.hpp"


Y::Y() {
    srand(time(0));
    for(int i=0; i < size; i++)
        dyn_array[i] = (rand() % 10) + 1;
    cout << "(Y) Create dyn array..." << endl;
}

Y::Y(const Y& y) {
    for(int i = 0; i < size; ++i)
        dyn_array[i] = y.dyn_array[i];
    cout << "(Y) Create dyn array by copy..." << endl;
}

Y::~Y() {
    delete [] dyn_array;
    cout << "(Y) Delete dyn array..." << endl;
}

void Y::print() {
    vector<int> vec(dyn_array, dyn_array + size);
    for (int e : vec)
        cout << e << ' ';
    cout << '\n';
}

void Y::set_value_at(int index, int value) {
    if (index >= 0 && index < this->size) {
        cout << "Add value : " << value << " at index : " << index << endl;
        dyn_array[index] = value;
    } else {
        cout << "Index out of bounds" << endl;
    }
}