#include <stdio.h>
#include <pthread.h>

#define MAX_THREAD 3

int g;

void *thread_start(void *k)
{
	int i=0;
	static int s;
	const int c;
	while(i<5)
	{
		printf("Running Thread_%d\n",(int)k);
		i++;
	}
	g++;
	s++;
	printf("Global: [%d], Static: [%d], Constant: [%d]\n",g,s,c);
}


int main()
{
	pthread_t tid[MAX_THREAD];
	int i=0;
	for(i=0;i<MAX_THREAD;i++)
	{
		pthread_create(&tid[i], NULL, thread_start, (void *) (i+1)); // 3 threads are created which are accessing same routine
		printf("TID:%lu\n",tid[i]);
	}
	for(i=0;i<MAX_THREAD;i++)
	{
		pthread_join(tid[i], NULL);
	}
}
