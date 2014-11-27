#include<stdio.h>
int main() 
{
	int i,j,k,h,r,n;
	while(scanf("%d",&h)!=0)
	{
	r=(h-1)/2;
	for(i=1;i<=r+1;i++)
	{
		for(j=1;j<=r+1-i;j++)
		{
		printf(" ");
		}
		for(k=1;k<=2*i-1;k++)
		{
		printf("*");
		}
		printf("\n");
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=i;j++)
		{
		printf(" ");
		}
		for(k=1;k<=2*(r-i)+1;k++)
		{
		printf("*");
		}
		printf("\n");
	}
	}
	
	
}
