#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX 1000
int r,c;
int p,q;
int mat1[MAX][MAX],mat2[MAX][MAX],ans[MAX][MAX];
void* mul(void* arg)
{	sleep(1);	
	if(c==p)
	{	int sum=0;
		int i,j,k;
		for(i=0;i<r;i++)
		{	for(j=0;j<q;j++)
			{	sum=0;
				for(k=0;k<p;k++)
				{	sum+=mat1[i][k]*mat2[k][j];	
				}
				ans[i][j]=sum;	
			}	
		}
		return (void*)1;
	
	}
	else
	{	return (void*)0;
	}	
}
int main()
{	int i,j;	
	printf("Enter the no. of rows and cols of matrix 1\n");
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&mat1[i][j]);
			
	printf("Enter the no. of rows and cols of matrix 1\n");
	scanf("%d%d",&p,&q);	
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&mat2[i][j]);
	
	pthread_t tid;
	void* yes;
	pthread_create(&tid,NULL,mul,NULL);
	pthread_join(tid,&yes);
	int ok=(int)*yes;
	if(ok)
	{	printf("The resultant matrix is\n");
		for(i=0;i<r;i++)
		{	for(j=0;j<q;j++)
				printf("%d ",ans[i][j]);
			printf("\n");	
		}
	}
	else
		printf("Not Possible\n");
	return 0;		
}
