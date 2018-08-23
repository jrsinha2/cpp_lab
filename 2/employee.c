#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>

struct employee
{	char name[100];
	int ID;
	char desig[50];
	int sal[5];
};

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void* per(void *arg)
{	struct employee s=*((struct employee*)arg);
	sleep(1);
	pthread_mutex_lock(&lock);	
	double p=0;
	printf("\nEmployee\n");
	printf("Name is %s\n",s.name);
	printf("ID is %d\n",s.ID);
	printf("Designation is  %s\n",s.desig);
	int i;
	for(i=1;i<5;i++)
	{	p=s.sal[i]-s.sal[i-1];
		p/=s.sal[i-1];
		p*=100;
		printf("Percentage in rise is %.2lf%%\n",p);
	}
	p=(s.sal[4]-s.sal[0])/s.sal[0];
	p*=100;
	printf("Hike in salary from last 5 yrs %.2lf%\n",p); 	
	pthread_mutex_unlock(&lock);	
	return NULL;
}	

int main()
{	int n;
	printf("Enter no. of employee\n");
	scanf("%d",&n);
	struct employee* arr;
	arr=(struct employee*)malloc(n*sizeof(struct employee));
	int i;	
	for(i=0;i<n;i++)
	{	printf("Name: ");	
		scanf("%s",arr[i].name);
		printf("ID: ");
		scanf("%d",&arr[i].ID);
		printf("Designation: ");
		scanf("%s",arr[i].desig);
		int j;
		printf("Enter Salary of last 5 years: ");
		for(j=0;j<5;j++)
			scanf("%d",&arr[i].sal[j]);
	}
	
	void* ar;
	int mx,mi;	
	pthread_t t[n];
	for(i=0;i<n;i++)
	{	pthread_create(&t[i],NULL,per,&arr[i]);
	}
	for(i=0;i<n;i++)
	{	pthread_join(t[i],NULL);
	}
	return 0;
}
		
