#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>			//posix threads
void *thread(void *arg)
{	sleep(1);
	int* i=(int*)arg;
	printf("Thread %d\n",*i);
	return NULL;
}
int main()
{	int n=5;
	for(int i=0;i<5;i++)
	{	pthread_t t;
		pthread_create(&t,NULL,thread,(void*)&i);
		pthread_join(t,NULL);
	}
	return 0;
}
