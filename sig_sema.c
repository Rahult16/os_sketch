#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int i;
sem_t sem1, sem2;

void *inc()
{
	while(i<5)
	{
		sem_wait(&sem1);

		printf("INC:[%d]\n",i);
		i++;

		sem_post(&sem2);
	}
}

void *dec()
{
	while(i>=0)
	{
		sem_wait(&sem2);

        	printf("DEC:[%d]\n",i);
		i--;

		sem_post(&sem1);
		}
}


int main()
{
	pthread_t tid1, tid2;
	sem_init(&sem1, 0 ,1);
	sem_init(&sem2, 0, 0);
	pthread_create(&tid1, NULL, inc, NULL);
	pthread_create(&tid2, NULL, dec, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	sem_destroy(&sem1);
	sem_destroy(&sem2);
}
