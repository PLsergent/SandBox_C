#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define CONSTANT_PROC 22180000 // A determiner pour votre machine ! ==>
                              // peut être fait de manière automatique mais ce n'est pas le sujet du TP

void do_work(unsigned int nb_secondes);

int stack1;
int stack2;

/*fonction simulant un travail à effectuer (attente active)*/
void do_work(unsigned int nb_secondes)
{
	unsigned int i = CONSTANT_PROC * nb_secondes; //attention à ne pas utiliser un int pour éviter un overflow
    printf("Doing work...");
	while(i > 0)
	{
		asm volatile("nop");
		i--;
	}
    printf("Workd done!\n");
	return;
}

void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
        do_work(1000);
        stack1 ++;
    }
}

/* MAIN */
int main()
{       
    clock_t begin = clock();

    struct sigaction sig1;
    sig1.sa_flags = SA_SIGINFO;
    sigemptyset(&sig1.sa_mask);
    sig1.sa_sigaction = my_handler;

    if (sigaction(SIGUSR1, &sig1, NULL) < 0){
        perror("Sigaction error");
    }

    signal(SIGUSR1, my_handler);

    for(int i=0; i < 5; i++) {
		
		kill(getpid(), SIGUSR1);

        if (stack1 > stack2) {
            stack2++;
            do_work(5);
        }
	}

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);

    printf("Singals received : %d \n", stack1);
    printf("Signals handled : %d \n", stack2);

	return 0;
}

// Après avoir testé avec des threads la solution ne marche pas
// car le programme s'arrête quand même après 2 signaux reçus