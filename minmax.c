#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>
int n;
void* max(void* arg)
{	int* arr=(int*)arg;
	int mx=INT_MIN;
	sleep(1);
	int i;
	for(i=0;i<n;i++)
	{	if(arr[i]>mx)
			mx=arr[i];
	}	
	
	return (void*)mx;
}
void* min(void* arg)
{	int* arr=(int*)arg;
	int mi=INT_MAX;
	sleep(1);
	int i;
	for(i=0;i<n;i++)
	{	if(arr[i]<mi)
			mi=arr[i];
	}	
	
	return (void*)mi;
}
int main()
{	
	scanf("%d",&n);
	int* arr;
	arr=(int*)malloc(n*sizeof(int));
	int i;	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	void* ar;
	int mx,mi;	
	pthread_t t[2];
	pthread_create(&t[0],NULL,max,arr);
	pthread_create(&t[1],NULL,min,arr);
	pthread_join(t[0],&ar);
	mx=(int*)ar;
	pthread_join(t[1],&ar);
	mi=(int*)ar;	
	printf("Max is %d\nMin is %d\n",mx,mi);
	return 0;
}
		
