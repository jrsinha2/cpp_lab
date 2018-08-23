#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
pthread_mutex_t m;

struct node
{
	int val;
	struct node *next;
};

struct node *root=NULL;

struct node *create(int val)
{	sleep(1);
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->next=NULL;
	return temp;	
}

void insert(int val)
{	sleep(1);
	struct node *temp=create(val);
	temp->next=root;
	root=temp;
	printf("\tElement %d inserted.\n",val);
}

int search(int val)
{	sleep(1);
	struct node *temp=NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp=root;
	while(temp!=NULL)
	{
		if(temp->val == val)
		{
			printf("\tElement %d found!\n",val);
			return 1;
		}
		temp=temp->next;
	}
	printf("\tElement %d not found!\n",val);
	return 0;
}

void delete(int val)
{	sleep(1);
	if(search(val)==0)
	{
		printf("\tElement %d can not be deleted.\n",val);
	}
	else
	{
		struct node *temp=NULL;
		temp=(struct node*)malloc(sizeof(struct node));
		struct node *prev=NULL;
		temp=(struct node*)malloc(sizeof(struct node));
		if(root->val==val)
		{
			root=root->next;
		}
		else
		{
			prev=root;
			temp=prev->next;
			while(temp->val!=val)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next=temp->next;
		}
		printf("\tElement %d deleted.\n",val);
	}
}

void func(int ch, int val)
{
	switch(ch)
	{
		case 0:
			insert(val);
			break;
		case 1:
			delete(val);
			break;
		case 2:
			search(val);
			break;
		default:
			printf("\tInvalid selection\n");
	}
}

int main()
{	int ops;
	scanf("%d",&ops);
	int i=0;
	srand(time(0));
	for(i=0; i<ops;i++)
	{	int ch,val;
		printf("%d:\n",i+1);
		pthread_mutex_lock(&m);
		scanf("%d%d",&ch,&val);
		func(ch,val);
		pthread_mutex_unlock(&m);
	}
	return 0;
}
