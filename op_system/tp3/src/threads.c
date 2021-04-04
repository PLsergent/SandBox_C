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
                printf("%s ", sentence[j]);
            }
        }
        printf("\n");
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


// Question 4

void read_buffer(int index, int **buffer) {
    printf("buffer[%d] = %d\n", index, (*buffer)[index]);
}

void write_buffer(int index, int value, int **buffer) {
    (*buffer)[index] = value;
    printf("modified value at index %d : buffer[%d] = %d\n", index, index, (*buffer)[index]);
}

void *reader_thread(void *args) {
    reader_thread_args_t *arguments = args;
    int **buffer = arguments->buffer;
    pthread_mutex_t *lock_r = arguments->lock_r;
    pthread_mutex_t *lock_w = arguments->lock_w;
    int i = arguments->index;

    printf("Reading...\n");

    pthread_mutex_lock(lock_r);
    read_buffer(i, buffer);
    pthread_mutex_unlock(lock_w);

    // See result after write
    pthread_mutex_lock(lock_r);
    read_buffer(i, buffer);
    pthread_mutex_unlock(lock_w);
    pthread_exit(NULL);
}

void *writer_thread(void *args) {
    writer_thread_args_t *arguments = args;
    int **buffer = arguments->buffer;
    pthread_mutex_t *lock_r = arguments->lock_r;
    pthread_mutex_t *lock_w = arguments->lock_w;
    int i = arguments->index;
    int value = arguments->data;

    printf("Writing...\n");

    pthread_mutex_lock(lock_w);
    write_buffer(i, value, buffer);
    pthread_mutex_unlock(lock_r);
    pthread_exit(NULL);
}