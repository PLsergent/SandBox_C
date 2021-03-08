#include "./headers/process.h"
#include <time.h>

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int VAR = 1;

int main() {
    if (fork() == 0) {
        char* type = "child";
        fork_wait();
    }
}