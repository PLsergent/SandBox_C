#include <stdio.h>
#include <stdlib.h>

#ifndef THREADS
#define THREADS


    // Question 1

    void *fct_threads(void *args);

    typedef struct fct_threads_args {
        int *global;
        int local;
    } fct_threads_args_t;


    // Question 2

    void *synchro_threads(void *args);

    typedef struct synchro_threads_args {
        char **sentence;
        pthread_mutex_t *lock1;
        pthread_mutex_t *lock2;
        int i;
    } synchro_threads_args_t;

#endif