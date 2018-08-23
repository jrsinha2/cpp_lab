#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#define MAX 100000

int fib[MAX];
void fibo()
{	fib[0]=0;
	fib[1]=1;
	int i;
	for(i=2;i<MAX;i++)
	{	fib[i]=fib[i-1]+fib[i-2];
	}
}

int prime[MAX];
void sieve()
{	
	//prime[0]=prime[1]=false;
	int i,j;
	for(i=0;i<MAX;i++)
		prime[i]=1;
	for( i=2;i<=sqrt(MAX);i++)
	{	if(prime[i]==1)
		{	for( j=i*2;j<=MAX;j+=i)
			{	prime[j]=0;
			}
		}
	}
	prime[0]=prime[1]=0;
}

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void* print(int n)
{	int i=0;
	pthread_mutex_lock(&lock);
	printf("\nFibonacci Series till %d\n",n);
	for(i=0;fib[i]<=n;i++)
	{	printf("%d ",fib[i]);
	}
	pthread_mutex_unlock(&lock);
	pthread_mutex_lock(&lock);
	i=0;
	printf("\nPrime Number Series till %d\n",n);
	for(i=0;i<n;i++)
	{	if(prime[i])
			printf("%d ",i);
	}
	pthread_mutex_unlock(&lock);
}
int main()
{	fibo();
	sieve();
	int n;
	scanf("%d",&n);
	pthread_t t[2];
	int i;
	for(i=0;i<1;i++)
	{	pthread_create(&t[i],NULL,print,n);
	}
	for(i=0;i<1;i++)
	{	pthread_join(t[i],NULL);
	}	
	return 0;
} 
