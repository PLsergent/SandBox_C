#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#define CONSTANT_PROC 22180000 // A determiner pour votre machine ! ==>
                              // peut être fait de manière automatique mais ce n'est pas le sujet du TP

void do_work(unsigned int nb_secondes);

/*fonction simulant un travail à effectuer (attente active)*/
void do_work(unsigned int nb_secondes)
{
	unsigned int i = CONSTANT_PROC * nb_secondes; //attention à ne pas utiliser un int pour éviter un overflow

	while(i > 0)
	{
		asm volatile("nop");
		i--;
	}
	return;
}

void my_handler(int signum)
{
    do_work(3000);
    if (signum == SIGUSR1)
    {
        printf("Received SIGUSR1!\n");
    }
}

/* MAIN */
int main()
{       
    clock_t begin = clock();

    signal(SIGUSR1, my_handler);
    pause();
    
    // int pid = getpid();
    // kill(pid, SIGUSR1);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);

	return 0;
}

// Lorsqu'on envoie des kill en rafale depuis un terminal on remarque que le programme est capable de gérer seulement deux signaux
// Il faudrait donc créer un thread a chaque envoie du signal pour éviter cela