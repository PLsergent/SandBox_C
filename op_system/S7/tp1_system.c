#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>		//pour utiliser le rand() => "man 3 rand" pour accéder aux pages du manuel sinon c'est la commande rand
#include <time.h>		//pour utiliser le time()
#include <unistd.h>		//usleep
#include <semaphore.h>  //uniquement pour version avec semaphore
#include <pthread.h>    //pour la gestion des threads et pour les mutex

#define ATTENTE_MIN 10000
#define ATTENTE_MAX 1000000
#define NB_THREADS 3

int mon_rand(int a, int b);

/* VERSION AVEC MUTEX */
void* thread_1(void* arg);
void* thread_2(void* arg);


/* VERSION AVEC MUTEX */
pthread_mutex_t m1;
pthread_mutex_t m2;

void main_version_avec_mutex(void);
void* thread_1_mutex(void* arg);
void* thread_2_mutex(void* arg);


/* VERSION AVEC SEMAPHORE */
#define P(x) sem_wait(x)
#define V(x) sem_post(x)

sem_t sem1, sem2;
void main_version_avec_sem(void);
void* thread_1_sem(void* arg);
void* thread_2_sem(void* arg);

/* VERSION AVEC BARRIER */
sem_t sem_barrier;
void main_version_barrier_thread(void);
void *sleeping_thread();
void *barrier_thread();


/* ****************** */
/*        MAIN        */
/* ****************** */

int main(void)
{
	pthread_t mes_threads[2];

	srand(time(NULL));

	//EXECUTION SANS PROTECTION
	printf("\n** Lancement des threads sans protection **\n");
	pthread_create(&mes_threads[0], NULL, thread_1, NULL);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX)); //vérifier que tout fonctionne bien
	pthread_create(&mes_threads[1], NULL, thread_2, NULL);

	pthread_join(mes_threads[0], NULL);
	pthread_join(mes_threads[1], NULL);

	//EXECUTION AVEC MUTEX
	printf("\n\n** Lancement des threads avec mutex **\n");
	main_version_avec_mutex();

	//EXECUTION AVEC SEMAPHORE
	printf("\n\n** Lancement des threads avec semaphore **\n");
	main_version_avec_sem();

	//EXECUTION AVEC BARRIER THREAD
	printf("\n\n** Lancement des threads avec barrier thread **\n");
	main_version_barrier_thread();

	printf("\n\n");
	return 0;
}

int mon_rand(int a, int b)
{
	//on suppose que b > a !
	return ( rand() % (b - a) ) + a;
}

/* ******************* */
/*   SANS PROTECTION   */
/* ******************* */
void* thread_1(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("je");

	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf(" mes");

	return NULL;
}

void* thread_2(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf(" synchronise");

	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf(" threads");

	return NULL;
}

/* ****************** */
/* VERSION AVEC MUTEX */
/* ****************** */
void main_version_avec_mutex(void)
{
	pthread_t mes_threads[2];

	//il faut bloquer le premier thread dès le départ
	pthread_mutex_lock(&m1);
	pthread_mutex_lock(&m2);

	pthread_create(&mes_threads[0], NULL, thread_1_mutex, NULL);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	pthread_create(&mes_threads[1], NULL, thread_2_mutex, NULL);

	pthread_join(mes_threads[0], NULL);
	pthread_join(mes_threads[1], NULL);

	return;
}
void* thread_1_mutex(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("je ");
	pthread_mutex_unlock(&m2);
	pthread_mutex_lock(&m1);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("mes ");
	pthread_mutex_unlock(&m2);

	return NULL;
}

void* thread_2_mutex(void* arg)
{
	pthread_mutex_lock(&m2);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("synchronise ");
	pthread_mutex_unlock(&m1);
	pthread_mutex_lock(&m2);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("threads ");

	return NULL;
}

/* ********************** */
/* VERSION AVEC SEMAPHORE */
/* ********************** */
void main_version_avec_sem(void)
{
	pthread_t mes_threads[2];

	sem_init(&sem1, 0, 0);
	sem_init(&sem2, 0, 0);

	pthread_create(&mes_threads[0], NULL, thread_1_sem, NULL);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	pthread_create(&mes_threads[1], NULL, thread_2_sem, NULL);

	pthread_join(mes_threads[0], NULL);
	pthread_join(mes_threads[1], NULL);

	return;
}

void* thread_1_sem(void* arg)
{
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("je ");
	V(&sem2); // V libérer
	P(&sem1); // P prendre
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("mes ");
	V(&sem2);

	return NULL;
}

void* thread_2_sem(void* arg)
{
	P(&sem2);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("synchronise ");
	V(&sem1);
	P(&sem2);
	usleep(mon_rand(ATTENTE_MIN, ATTENTE_MAX));
	printf("threads ");

	return NULL;
}

/* *************************** */
/* VERSION AVEC BARRIER THREAD */
/* *************************** */
void main_version_barrier_thread()
{
	pthread_t mes_threads[NB_THREADS];
	pthread_t barrier_thread_t;

	pthread_create(&barrier_thread_t, NULL, barrier_thread, NULL);

	for (int i=0; i < NB_THREADS; i++) {
		pthread_create(&mes_threads[i], NULL, sleeping_thread, (void*) i);
	}

	pthread_join(barrier_thread_t, NULL);
	for (int i=0; i < NB_THREADS; i++) {
		pthread_join(mes_threads[0], NULL);
	}

	return;
}

void *sleeping_thread(void* id) {
	int i = (int) id;
	srand(time(NULL));
    int random = rand() % 3;
    sleep(random);
	
    printf("[ thread %d ] Point atteint\n", i++);

	V(&sem_barrier);
    return 0;
}


void *barrier_thread() {
	printf("[ b_thread ] Point atteint, en attente...\n");
	for(int i=0; i < NB_THREADS; i++) {
		P(&sem_barrier);
	}
    printf("[ b_thread ] Je peux continuer !\n");
	return 0;
}