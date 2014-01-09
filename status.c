#include<stdio.h>
#include<sys/statvfs.h>


int main(int argc,char *argv[])
	{
	struct statvfs fs;
	if(statvfs(argv[1],&fs)<0)
		printf("Error");
	else
		printf("Filesysytem Block Size: %ld\nFragment Size:%ld\nFreeblocks: %ld\n\n",fs.f_bsize,fs.f_frsize,fs.f_bfree);



	return 0;
	}

