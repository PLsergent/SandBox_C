#include "./headers/process.h"
#include <time.h>

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int VAR = 1;

int main() {
    pid_t pid = getpid();
    srand(time(NULL));
    for (int i=0; i < 3; i++) {
        if (fork() == 0) {
            char* type = "child";
            fork_process(type, &VAR);
            printf(ANSI_COLOR_BLUE "[child] <%d> : i=%d, v_globale=%d" ANSI_COLOR_RESET "\n", pid, i, VAR);
            int r = rand() % 4 + 1;
            printf("Wait %d seconds\n\n", r);
            sleep(r);
        } else {
            char* type = "parent";
            fork_process(type, &VAR);
            printf(ANSI_COLOR_YELLOW "[parent] <%d> : i=%d, v_globale=%d" ANSI_COLOR_RESET "\n", pid, i, VAR);
            int r = rand() % 4 + 1;
            printf("Wait %d seconds\n\n", r);
            sleep(r);
        }
    }

    printf(ANSI_COLOR_MAGENTA "** Fin du processus <%d>, v_globale=%d **" ANSI_COLOR_RESET "\n\n", pid, VAR);
}

/* 
1.2
    Les affichages ne sont font pas forcément dans l'ordre étant donné que les processus s'exécutent en parallèle
    Une des solutions seraient d'attendre que l'un des processus se finisse, sleep(), wait()

1.3
    return 0 : child process
    return -1 : parent process
    Le PPID du père correspond

1.4
    Le résultat de la variable globale ne change pas

1.5
    Les affichages sont dans un ordre différent à chaque exécution

*/