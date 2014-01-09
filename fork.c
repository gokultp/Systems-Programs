#include<stdio.h>
#include<unistd.h>

int main()
	{
	int i,j;
	pid_t pid;
	
	pid=fork();
	
	if(pid<0)
		{
		printf("Error");
		
		}
	else if(pid==0)
		{
		for(i=0;i<10;i++)
			{
			printf("Child says %c\n",'A'+i);
			sleep(1);
			}
	
		}
	else
		{
		for(j=0;j<10;j++)
			{
			printf("Parent says %c\n",'A'+j);
			sleep(1);
			}
	
		}
	return 0;
	}
