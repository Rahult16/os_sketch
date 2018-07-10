#include <stdio.h>
#include <pthread.h>


void *thread_1()
{
	int i=0;
	while(i<5)
	{
		printf("Thread_1\n");
		i++;
	}
}

void *thread_2()
{
	int i=0;
	while(i<5)
	{
		printf("Thread_2\n");
		i++;
	}
}

int main()
{
	pthread_t tid1,tid2;
	printf("creating thread\n");
	pthread_create(&tid1, NULL, thread_1, NULL);
	pthread_create(&tid2, NULL, thread_2, NULL);
	//sleep(5);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("thread destroyed\n");
}
