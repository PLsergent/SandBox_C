#include <stdio.h>
#include <stdlib.h>

#ifndef ARRAY_2D
#define ARRAY_2D

    int** init_array(int nb_col, int nb_line);
    void init_array_void(int** * array2D, int nb_col, int nb_line);

    void fill_array(int** array2d, int nb_col, int nb_line);

    void print_array(int** array2d, int nb_col, int nb_line);

    void destroy_array(int** * array2d, int nb_col, int nb_line);

#endif
