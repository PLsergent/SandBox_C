#include "./headers/array2D.h"

int main() {
    int size_col = 5;
    int size_line = 5;

    int** array = init_array(size_col, size_line);
    fill_array(array, 5, 5);
    print_array(array, size_col, size_line);
    destroy_array(&array, size_col, size_line);

    int** array_void;
    init_array_void(&array_void, size_col, size_line);
    fill_array(array_void, 5, 5);
    print_array(array_void, size_col, size_line);
    destroy_array(&array_void, size_col, size_line);

    return 0;
}