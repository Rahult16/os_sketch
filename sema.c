#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int i;
sem_t sem;

void *inc()
{
	while(i<5)
	{
		sem_wait(&sem);
		printf("INC:[%d]\n",i);
		i++;
		sem_post(&sem);
	}
}

void *dec()
{
	while(i>=0)
	{
		sem_wait(&sem);
        	printf("DEC:[%d]\n",i);
		i--;
		sem_post(&sem);
	}
}


int main()
{
	pthread_t tid1, tid2;
	sem_init(&sem, 0 ,1);
	pthread_create(&tid1, NULL, inc, NULL);
	pthread_create(&tid2, NULL, dec, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	sem_destroy(&sem);
}
