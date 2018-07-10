#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int i;
pthread_mutex_t mut;

void *inc()
{
	while(i<5)
	{
		pthread_mutex_lock(&mut);

		printf("INC:[%d]\n",i);
		i++;

		pthread_mutex_unlock(&mut);
	}
}

void *dec()
{
	while(i>=0)
	{
		pthread_mutex_lock(&mut);

        	printf("DEC:[%d]\n",i);
		i--;

		pthread_mutex_unlock(&mut);
		}
}


int main()
{
	pthread_t tid1, tid2;
	pthread_mutex_init(&mut, NULL);
	pthread_create(&tid1, NULL, inc, NULL);
	pthread_create(&tid2, NULL, dec, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&mut);
}
