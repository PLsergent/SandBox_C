#include "./headers/threads.h"
#include <pthread.h>

/* TP3 - Thread & Synchronisation */ 
/* Sergent Pierre-Louis LSI-1 */

int main() {
    printf("================= TP3 ================\n");
    printf("======== Sergent Pierre-Louis ========\n");

    // Question 1
    {
        printf("\nQuestion 1:\n");

        pthread_t thread1, thread2, thread3;
        fct_threads_args_t func_args1, func_args2, func_args3;

        int global_var = 100;
        int iret1, iret2, iret3;

        func_args1.global = &global_var;
        func_args1.local = 10;

        func_args2.global = &global_var;
        func_args2.local = 20;

        func_args3.global = &global_var;
        func_args3.local = 30;

        iret1 = pthread_create(&thread1, NULL, fct_thread, (void*) &func_args1);
        iret2 = pthread_create(&thread2, NULL, fct_thread, (void*) &func_args2);
        iret3 = pthread_create(&thread3, NULL, fct_thread, (void*) &func_args3);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);
        printf("Global variable : %d\n", global_var);
    }
    
    // Question 2
    {
        printf("\nQuestion 2:\n");

        pthread_t thread1, thread2;
        pthread_mutex_t lock1, lock2;
        synchro_thread_args_t func_args1, func_args2;

        char *sentence[100] = {"je", "synchronise", "mes", "threads"};

        func_args1.sentence = sentence;
        func_args1.lock1 = &lock1;
        func_args1.lock2 = &lock2;
        func_args1.i = 0; // even

        func_args2.sentence = sentence;
        func_args2.lock2 = &lock2;
        func_args2.lock1 = &lock1;
        func_args2.i = 1; // odd

        pthread_mutex_init(&lock1, NULL);
        pthread_mutex_init(&lock2, NULL);
        pthread_mutex_lock(&lock2);

        pthread_create(&thread2, NULL, synchro_thread, (void*) &func_args2);
        pthread_create(&thread1, NULL, synchro_thread, (void*) &func_args1);
        
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        pthread_mutex_destroy(&lock1);
        pthread_mutex_destroy(&lock2);
    }

    // Question 3
    {
        printf("\nQuestion 3:\n");
        int n = 4;

        pthread_t threads[n], b_thread;
        pthread_barrier_t barrier;
        barrier_thread_args_t barrier_args;
        spleeping_thread_args_t thread_args[n];

        barrier_args.barrier = &barrier;
        barrier_args.n = n;

        pthread_create(&b_thread, NULL, barrier_thread, (void*) &barrier_args);

        for (int i=1; i < n; i++) {
            thread_args[i].barrier = &barrier;
            thread_args[i].i = i;
            pthread_create(&threads[i], NULL, spleeping_thread, (void*) &thread_args[i]);
        }

        for (int j=1; j < n; j++) {
            pthread_join(threads[j], NULL);
        }
        pthread_join(b_thread, NULL);
    }

    // Question 4
    {
        printf("\nQuestion 4:\n");

        pthread_t t_reader, t_writer;
        pthread_mutex_t lock_r, lock_w;
        reader_thread_args_t reader_args;
        writer_thread_args_t writer_args;

        int *buffer = (int*)malloc(10*sizeof(int));
        for (int i=0; i < 10; i++) {
            buffer[i] = i;
        }

        reader_args.lock_r = &lock_r;
        reader_args.lock_w = &lock_w;
        reader_args.buffer = &buffer;
        reader_args.index = 4;

        writer_args.lock_r = &lock_r;
        writer_args.lock_w = &lock_w;
        writer_args.buffer = &buffer;
        writer_args.index = 4;
        writer_args.data = 100;

        pthread_mutex_init(&lock_r, NULL);
        pthread_mutex_init(&lock_w, NULL);
        pthread_mutex_lock(&lock_w);

        pthread_create(&t_reader, NULL, reader_thread, (void*) &reader_args);
        pthread_create(&t_writer, NULL, writer_thread, (void*) &writer_args);
        
        pthread_join(t_reader, NULL);
        pthread_join(t_writer, NULL);

        pthread_mutex_destroy(&lock_r);
        pthread_mutex_destroy(&lock_w);
    }

    return 0;
}