#include<stdio.h>

int main()
	{
	int n,m,p,q,i,j,k,a[10][10],b[10][10],c[10][10]={0};
	
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
			
	scanf("%d%d",&p,&q);
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<p;j++)
			for(k=0;k<m;k++)
				c[i][j]+=a[i][k]*b[k][j];
	for(i=0;i<n;i++)
		{
		for(j=0;j<q;j++)
			printf("%d  ",c[i][j]);
		printf("\n");
		}
	return 0;
	}
