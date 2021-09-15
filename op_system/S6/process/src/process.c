#include "../headers/process.h"


void fork_process(char *type, int *var) {
    *var = *var + 10;
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("[%s] PID=%d, PPID=%d, v_globale=%d\n", type, pid, ppid, *var);
}

void fork_wait() {
    
}