#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<pthread.h>	
void* func(void *arg)
{	double *arr;
	sleep(1);
	int i;
	arr=(double*)malloc(100*sizeof(double));
	for(i=0;i<=99;i++)
	{	arr[i]=sqrt((double)i);
	}
	return (void*)arr;
}
int main()
{	pthread_t t;
	void* ar;
	double* arr;
	int i;
	pthread_create(&t,NULL,func,NULL);
	printf("Hello\n");
	pthread_join(t,&ar);
	arr=(double*)ar;
	for(i=0;i<100;i++)
		printf("%d %lf\n",i,arr[i]);
	printf("\n");
	return 0;
}
		
