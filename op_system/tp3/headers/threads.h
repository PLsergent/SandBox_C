#include <stdio.h>
#include <stdlib.h>

#ifndef THREADS
#define THREADS


    // Question 1

    void *fct_thread(void *args);

    typedef struct fct_threads_args {
        int *global;
        int local;
    } fct_threads_args_t;


    // Question 2

    void *synchro_thread(void *args);

    typedef struct synchro_thread_args {
        char **sentence;
        pthread_mutex_t *lock1;
        pthread_mutex_t *lock2;
        int i;
    } synchro_thread_args_t;


    // Question 3

    void *spleeping_thread(void *args);

    typedef struct spleeping_thread_args {
        pthread_barrier_t *barrier;
        int i;
    } spleeping_thread_args_t;

    void *barrier_thread(void *args);

    typedef struct barrier_thread_args {
        pthread_barrier_t *barrier;
        int n;
    } barrier_thread_args_t;

#endif