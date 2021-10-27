#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define CONSTANT_PROC 22180000 // A determiner pour votre machine ! ==>
                              // peut être fait de manière automatique mais ce n'est pas le sujet du TP

void do_work(unsigned int nb_secondes);
void periodic_task1(unsigned int duration);
void periodic_task2(unsigned int duration);

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

void periodic_task1(unsigned int duration) {
    while(1) {
        do_work(duration);
        sleep(1);
    }
}

void periodic_task2(unsigned int duration) {
    while(1) {
        do_work(duration);
        alarm(1);
    }
}

void alarm_handler(int sig) {
    signal(SIGALRM, SIG_IGN);
    signal(SIGALRM, alarm_handler);
}


/* MAIN */
int main()
{       
    clock_t begin = clock();

    signal(SIGALRM, alarm_handler);

    periodic_task2(500);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);

	return 0;
}

// Le problème de la méthode en utilisant alarm, c'est que si l'alarme arrive à 0 on sort du programme en envoyant un signal
// Pour palier au problème on peut intercepter le signal et utiliser SIG_IGN pour l'annuler ainsi on peut définir une fonction périodique