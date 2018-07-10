#include <stdio.h>
#include <pthread.h>

int i;

void *inc()
{
	while(i<5)
	{
		printf("INC:[%d]\n",i);
		i++;
	}
}

void *dec()
{
	while(i> -5)
	{
        	printf("DEC:[%d]\n",i);
		i--;
	}
}


int main()
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, inc, NULL);
	pthread_create(&tid2, NULL, dec, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
