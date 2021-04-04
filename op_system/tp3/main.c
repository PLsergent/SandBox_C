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

        iret1 = pthread_create(&thread1, NULL, fct_threads, (void*) &func_args1);
        iret2 = pthread_create(&thread2, NULL, fct_threads, (void*) &func_args2);
        iret3 = pthread_create(&thread3, NULL, fct_threads, (void*) &func_args3);

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
        synchro_threads_args_t func_args1, func_args2;

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

        pthread_create(&thread2, NULL, synchro_threads, (void*) &func_args2);
        pthread_create(&thread1, NULL, synchro_threads, (void*) &func_args1);
        
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        pthread_mutex_destroy(&lock1);
        pthread_mutex_destroy(&lock2);
    }

    return 0;
}