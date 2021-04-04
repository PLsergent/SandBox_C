#include "../headers/threads.h"
#include <pthread.h>
#include <unistd.h>


// Question 1

void *fct_thread(void *args) {
    fct_threads_args_t * arguments = args;
    int *global = arguments->global;
    int local = arguments->local;

    *global += 11;
    local += 1;
    printf("Local variable thread %d : %d\n", local/10, local);
    pthread_exit(NULL);
}


// Question 2

void *synchro_thread(void *args) {
    synchro_thread_args_t *arguments = args;
    char **sentence = arguments->sentence;
    pthread_mutex_t *lock1 = arguments->lock1;
    pthread_mutex_t *lock2 = arguments->lock2;
    int i = arguments->i;

    if (i == 0) {
        for (int j=0; j < 4; j++) {
            if (j % 2 == 0) {
                pthread_mutex_lock(lock1);
                printf("%s ", sentence[j]);
                pthread_mutex_unlock(lock2);
            }
        }
        pthread_exit(NULL);
    } else {
        for (int j=0; j < 4; j++) {
            if (j % 2 == 1 && j != 3) {
                pthread_mutex_lock(lock2);
                printf("%s ", sentence[j]);
                pthread_mutex_unlock(lock1);
            } else if (j == 3) {
                pthread_mutex_lock(lock2);
                printf("%s \n", sentence[j]);
            }
        }
        pthread_exit(NULL);
    }
}


// Question 3

void *spleeping_thread(void *args) {
    spleeping_thread_args_t *arguments = args;
    pthread_barrier_t *barrier = arguments->barrier;
    int i = arguments->i;

    srand(time(NULL));
    int random = rand() % 3;
    sleep(random);

    printf("[ thread %d ] Point atteint\n", i);
    pthread_barrier_wait(barrier);
    pthread_exit(NULL);
    return 0;
}

void *barrier_thread(void *args) {
    barrier_thread_args_t *arguments = args;
    pthread_barrier_t *barrier = arguments->barrier;
    int num_threads = arguments->n;

    pthread_barrier_init(barrier, NULL, num_threads);

    srand(time(NULL));
    int random = rand() % 3;
    sleep(random);
    
    printf("[ b_thread ] Point atteint, en attente...\n");

    pthread_barrier_wait(barrier);
    pthread_barrier_destroy(barrier);
    printf("[ b_thread ] Je peux continuer !\n");
    pthread_exit(NULL);
    return 0;
}