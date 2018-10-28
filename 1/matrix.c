#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define N 100
#define M 100
int a[N][M];
int n,m;
int tot=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void* thread(void* i)
{	int j;
	pthread_mutex_lock(&lock);
	sleep(1);
	int sum=0;
	for(j=0;j<m;j++)
	{	sum+=a[(*(int*)i)][j];
	}
	printf("row %d sum is %d\n",(*(int*)i)+1,sum);
	tot+=sum;
	pthread_mutex_unlock(&lock);
}
int main()
{	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++)
	{	for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	}
	pthread_t t[n];
	for(i=0;i<n;i++)
	{	int r=pthread_create(&t[i],NULL,thread,(void*)&i);
		//printf("%d\n",r);
		pthread_join(t[i],NULL);
	}
	printf("Total sum is %d\n",tot);
	return 0;
}
