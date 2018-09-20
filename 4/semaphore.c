//Program to create semaphore b/w two threads

#include<stdio.h>
#include<pthread.h>		//for threads
#include<semaphore.h>	//for semaphores
#include<unistd.h>

sem_t semaphore;
void *thread(void* arg)
{	int no=(int*)arg;
	printf("\nEntered by thread %d\n",no);
	//wait 
	sem_wait(&semaphore);
	printf("\nPut on wait and executing critical section stmts by thread %d\n",no);
	
	sleep(4);
	
	printf("\nTime to exit by thread %d\n",no);
	sem_post(&semaphore);
	return NULL;
}

int main()
{
	sem_init(&semaphore,0,1);		//0 means for threads and 1 is the value assigned to variable
	pthread_t t1,t2;		//two threads
	int i=1,j=2;
	pthread_create(&t1,NULL,thread,(void*)i);
	sleep(1);
	pthread_create(&t2,NULL,thread,(void*)j);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&semaphore);
	return 0;
}

/*	compile using gcc semaphore.c -lpthread -lrt
*/
