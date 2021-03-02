#include "../headers/array2D.h"

int** init_array(int nb_col, int nb_line) {
    int** array2d;
    array2d = (int**)malloc(sizeof(int*)*nb_line);
    for(int i=0; i < nb_line; i++) {
        array2d[i] = (int*)malloc(sizeof(int)*nb_col);
    }
    return array2d;
}

void init_array_void(int** * array2d, int nb_col, int nb_line) {
    *array2d = (int**)malloc(sizeof(int*)*nb_line);
    for(int i=0; i < nb_line; i++) {
        (*array2d)[i] = (int*)malloc(sizeof(int)*nb_col);
    }
    return;
}

void fill_array(int** array2d, int nb_col, int nb_line) {
    for(int i=0; i < nb_col; i++) {
        for(int j=0; j < nb_line; j++) {
	        array2d[i][j] = i*j;
        }
    }
    return;
}

void print_array(int** array2d, int nb_col, int nb_line) {
    printf("[\n");
    for(int i=0; i < nb_col; i++) {
        printf("\t[");
        for(int j=0; j < nb_line; j++) {
	        printf(" %d ", array2d[i][j]);
        }
        printf("],\n");
    }
    printf("]\n");
    return;
}

void destroy_array(int** * array2d, int nb_col, int nb_line) {
    for(int i=0; i < nb_col; i++) {
        free((*array2d)[i]);
    }
    free(*array2d);
    *array2d = NULL;
    return;
}