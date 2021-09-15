#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

#ifndef PROCESS
#define PROCESS

    void fork_process(char *type, int *var);
    void fork_wait();

#endif