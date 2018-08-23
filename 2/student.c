#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>

struct student
{	char name[100];
	int ID;
	int subs;
	double marks[100];
};

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void* per(void *arg)
{	struct student s=*((struct student*)arg);
	sleep(1);
	pthread_mutex_lock(&lock);	
	double p=0;
	printf("\nStudent\n");
	printf("Name is %s\n",s.name);
	printf("ID is %d\n",s.ID);
	printf("No of subjects(max marks 100) is  %d\n",s.subs);
	int i;
	for(i=0;i<s.subs;i++)
		p+=s.marks[i];
	p/=s.subs;
	pthread_mutex_unlock(&lock);	
	printf("Percentage is %.2lf%%\n",p);
	return NULL;
}	

int main()
{	int n;
	printf("Enter no. of students\n");
	scanf("%d",&n);
	struct student* arr;
	arr=(struct student*)malloc(n*sizeof(struct student));
	int i;	
	for(i=0;i<n;i++)
	{	printf("Name: ");	
		scanf("%s",arr[i].name);
		printf("ID: ");
		scanf("%d",&arr[i].ID);
		printf("No. of subjects: ");
		scanf("%d",&arr[i].subs);
		int j;
		printf("Enter Marks of each subject(Max marks 100): ");
		for(j=0;j<arr[i].subs;j++)
			scanf("%lf",&arr[i].marks[j]);
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
		
