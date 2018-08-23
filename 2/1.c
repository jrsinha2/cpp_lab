#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
void* fact(void* arg)
{	int p=(int)arg;
	int prod=1;
	sleep(1);
	int i;	
	prod=p*(p+1)/2;
	return (void*)prod;
}
int main()
{	int n;
	scanf("%d",&n);
	void* ar;
	int p;	
	pthread_t t;
	pthread_create(&t,NULL,fact,n);
	pthread_join(t,&ar);
	p=(int*)ar;	
	printf("%d\n",p);
	return 0;
}
		
