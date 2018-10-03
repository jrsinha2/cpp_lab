//Producer Consumer Problem with infinite buffer

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>        //for threads
#include<semaphore.h>    //for semaphores
#include<unistd.h>

#define MAX 10		//size of buffer
sem_t notempty;
sem_t notfull;
sem_t now;

int buffer[MAX];
int pos=-1;

void* Consumer()
{	while(1)
	{	//wait(notempty)
		sem_wait(&notempty);
		sem_wait(&now);		
		
		//d<-take(buffer)
		
		if(pos==-1)
		{	printf("Buffer is Empty\n");
		}
		else
		{	int item=buffer[pos--];	
			//consume(d)
			printf("Item no. consumed is %d\n",item);
		}
		sem_post(&now);
		sem_post(&notfull);
		sleep(3); 			
	}		
}
void* Producer()
{	
	while(1)
	{	srand(time(0));
		sem_wait(&notfull);
		sem_wait(&now);
		//d<-produce item	
		int d=rand()%5+1;			
		
		//append(d,buffer)
		if(pos==MAX-1)			
		{	printf("Buffer is full\n");
		}
		else
		{	buffer[++pos]=d;
			printf("Item no. produced is %d\n",d);
		}
				
		//signal(notempty)
		sem_post(&now);
		sem_post(&notempty);
		sleep(1);
	}
}
int main()
{	sem_init(&notempty,0,0);
	sem_init(&notfull,0,2);		//0-(MAX-1) if <0 enters block state  
	sem_init(&now,0,1);
	pthread_t p,c;
	pthread_create(&p,NULL,Producer,NULL);
	sleep(2);
	pthread_create(&c,NULL,Consumer,NULL);
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	return 0;
}			

