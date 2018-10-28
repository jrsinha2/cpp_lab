#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *thread(void *arg)
{	sleep(1);
	printf("Hello World\n");
	return NULL;
}
int main()
{	pthread_t t;
	pthread_create(&t,NULL,thread,NULL);
	pthread_join(t,NULL);
	return 0;
}
		
