#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<pthread.h>	
void* func(void *arg)
{	double *arr;
	sleep(1);
	arr=(double*)malloc(100*sizeof(double));
	for(int i=0;i<=99;i++)
	{	arr[i]=(double)sqrt((double)i);
	}
	return (void*)arr;
}
int main()
{	pthread_t t;
	double* arr;
	
	pthread_create(&t,NULL,func,NULL);
	printf("Hello\n");
	pthread_join(t,&arr);
	for(int i=0;i<100;i++)
		printf("%lf\n",arr[i]);
	printf("\n");
	return 0;
}
		
