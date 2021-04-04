#include "../headers/threads.h"
#include <pthread.h>


// Question 1

void *fct_threads(void *args) {
    fct_threads_args_t * arguments = args;
    int *global = arguments->global;
    int local = arguments->local;

    *global += 11;
    local += 1;
    printf("Local variable thread %d : %d\n", local/10, local);
}


// Question 2

void *synchro_threads(void *args) {
    synchro_threads_args_t * arguments = args;
    char **sentence = arguments->sentence;
    pthread_mutex_t *lock1 = arguments->lock1;
    pthread_mutex_t *lock2 = arguments->lock2;
    int i = arguments->i;

    if (i == 0) {
        for (int j=0; j<4; j++) {
            if (j % 2 == 0) {
                pthread_mutex_lock(lock1);
                printf("%s ", sentence[j]);
                pthread_mutex_unlock(lock2);
            }
        }
        pthread_exit(NULL);
    } else {
        for (int j=0; j<4; j++) {
            if (j % 2 == 1 && j != 3) {
                pthread_mutex_lock(lock2);
                printf("%s ", sentence[j]);
                pthread_mutex_unlock(lock1);
            } else if (j == 3) {
                pthread_mutex_lock(lock2);
                printf("%s ", sentence[j]);
            }
        }
        pthread_exit(NULL);
    }
}