#include<stdio.h>

int main()
	{

	int i,j,k,flag[10],cmpltd=0,c;
	int p,r,al[10][5],max[10][5],need[10][5],ssqns[10],av[5];
	
	
	
	printf("Enter the no of processes and Resources:  ");
	scanf("%d%d",&p,&r);

	for(i=0;i<p;i++)
		flag[i]=0;
	
	printf("Enter the Aloocation matrix( proc X res ) :\n");
	for(i=0;i<p;i++)
		for(j=0;j<r;j++)
			scanf("%d",&al[i][j]);


	printf("Enter the Max allocation matrix( proc X res ) :\n");
        for(i=0;i<p;i++)
                for(j=0;j<r;j++)
                        scanf("%d",&max[i][j]);

	printf("Enter the Availabe instances for \n");
        
       	for(j=0;j<r;j++)
		{
		printf("Resource %c :",'A'+j);
        	scanf("%d",&av[j]);
		}



                



        for(i=0;i<p;i++)
		{
                for(j=0;j<r;j++)
			{
                        need[i][j]=max[i][j]-al[i][j];
			
			}
		
		}

	 

	for(k=0;k<p;k++)
		{
		for(i=0;i<p;i++)
			{
			if(flag[i]==0)
				{
				c=0;
				for(j=0;j<r;j++)
					if(need[i][j]<=av[j])
						c++;
					
					
				if(c==r)
					{
					ssqns[cmpltd]=i;
					cmpltd++;
					flag[i]=1;
					for(j=0;j<r;j++)
						av[j]=av[j]+al[i][j];
					
					}

				}
		

			}


		}	
	if(cmpltd<p)
		printf("Unsafe state\n");
	else
		{
		printf("Safe state\nThe safe sequence is: \n< ");
		for(i=0;i<p;i++)
			printf("P%d ",ssqns[i]);
		printf(">");
		}


	return 0;
	}
