#include<stdio.h>
int main(int argc,char *argv[])
{	FILE *f1;
	char* str=argv[1];		//name of the file
	f1=fopen(str,"r");
	if(f1==NULL)
	{	perror("Error");
		return -1;
	}
	fclose(f1);
	return 0;
}
		
