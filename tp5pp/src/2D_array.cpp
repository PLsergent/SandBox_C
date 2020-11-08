#include "../headers/2D_array.hpp"


T::T(int size_row_, int size_col_) {
    size_row = size_row_;
    size_col = size_col_;

    dyn2_array = new O*[size_row];

    for(int i = 0; i < size_row; ++i)
        dyn2_array[i] = new O[size_col];
    
    cout << "(T) Create 2D array..." << endl;
}

T::~T() {
    for(int i = 0; i < size_row; ++i)
        delete [] dyn2_array[i];

    delete [] dyn2_array;

    cout << "(T) Delete 2D array..." << endl;
}