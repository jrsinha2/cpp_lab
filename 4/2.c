//Program to create semaphore b/w n threads

#include<stdio.h>
#include<pthread.h>        //for threads
#include<semaphore.h>    //for semaphores
#include<unistd.h>

sem_t semaphore;
void *thread(void* arg)
{    int* no=(int*)arg;
    printf("\nEntered by thread %d\n",*no);
    //wait 
    sem_wait(&semaphore);
    printf("\nPut on wait and executing critical section stmts by thread %d\n",*no);
    
    sleep(4);
    
    printf("\nTime to exit by thread %d\n",*no);
    sem_post(&semaphore);
    return NULL;
}

int main()
{    int n;
    scanf("%d",&n);
    sem_init(&semaphore,0,1);        //0 means for threads and 1 is the value assigned to variable
    pthread_t t[n];        //n threads
    int num[n];
    int i;
    for(i=0;i<n;i++)
    	num[i]=i+1;
    for(i=0;i<n;i++)
    {   void* j=&num[i];    
        pthread_create(&t[i],NULL,thread,j);
        sleep(1);
    }
    for(i=0;i<n;i++)
    	pthread_join(t[i],NULL); 
    sem_destroy(&semaphore);
    return 0;
}

/*    compile using gcc semaphore.c -lpthread -lrt
*/
