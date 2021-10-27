#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>


#define CONSTANT_PROC 22180000 // A determiner pour votre machine ! ==>
                              // peut être fait de manière automatique mais ce n'est pas le sujet du TP

void do_work(unsigned int nb_secondes);

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

void alarm_handler(int sig) {
    signal(SIGALRM, SIG_IGN);
    signal(SIGALRM, alarm_handler);
    printf("Timer reset");
}

int main(void)
{
    clock_t begin = clock();
	timer_t timer;
	struct itimerspec timer_spec;
	
	signal(SIGALRM, alarm_handler);

	timer_create(CLOCK_REALTIME, NULL, &timer);
	
	timer_spec.it_value.tv_sec = 1;
	timer_spec.it_value.tv_nsec = 0;

	timer_spec.it_interval.tv_sec = 1;
	timer_spec.it_interval.tv_nsec = 0;
	
	timer_settime(timer, 0, &timer_spec, NULL);

	while(1) {
        do_work(1000);
    }
	
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", time_spent);

	return 0;
}