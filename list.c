#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char *argv[])
	{
	DIR *fd;
	struct dirent *fls;
	if(argc==1)
		fd=opendir(".");
	else
		fd=opendir(argv[1]);
	while(fls=readdir(fd))
		printf(">>>  %s\n",fls->d_name);
		

	return 0; 
	}
