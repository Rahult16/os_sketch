#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char c[6]={'a','b','c','d','e','f'};
int i[6]={1,2,3,4,5,6};

sem_t sem1, sem2;

void *inc()
{
	int j=0;
	while(j<6)
	{
		sem_wait(&sem1);
		printf("%c",c[j]);
		j++;
		sem_post(&sem2);
	}
}

void *dec()
{
        int j=0;
	while(j<6)
        {
                sem_wait(&sem2);
                printf("%d",i[j]);
		j++;
                sem_post(&sem1);
        }
	printf("\n");
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
