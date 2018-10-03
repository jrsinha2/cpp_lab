//Producer Consumer Problem with infinite buffer

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>        //for threads
#include<semaphore.h>    //for semaphores
#include<unistd.h>

sem_t notempty;

struct queue
{	int data;
	struct queue *next;
};
struct queue *front,*rear;

void* Consumer()
{	while(1)
	{	//wait(notempty)
		sem_wait(&notempty);
		
		
		//d<-take(buffer)
		if(front==NULL)
		{	printf("Buffer is Empty\n");
		}
		else
		{	struct queue *temp=front;
			front=front->next;
			if(front==NULL)
				rear=NULL;
			
			//consume(d)
			printf("Item no. consumed is %d\n",temp->data);
			free(temp);
		}
		
		sleep(3); 			
	}		
}
void* Producer()
{	
	while(1)
	{	srand(time(0));
		
		//d<-produce item	
		int d=rand()%5+1;			
		struct queue *temp=(struct queue*)malloc(sizeof(struct queue));
		temp->next=NULL;
		temp->data=d;		
		
		
		//append(d,buffer)
		if(front==NULL)			
		{	front=temp;
			rear=temp;
		}
		else
		{	rear->next=temp;
			rear=temp;
		}
		printf("Item no. produced is %d\n",d);
		
		//signal(notempty)
		sem_post(&notempty);
		sleep(1);
	}
}
int main()
{	front=rear=NULL;
	sem_init(&notempty,0,1);
	pthread_t p,c;
	pthread_create(&p,NULL,Producer,NULL);
	sleep(2);
	pthread_create(&c,NULL,Consumer,NULL);
	pthread_join(p,NULL);
	pthread_join(c,NULL);
	return 0;
}			

