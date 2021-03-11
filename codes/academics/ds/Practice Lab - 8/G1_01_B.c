#include<stdio.h>

int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main()
{
	int g,n,i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		g=0;
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++) g+=gcd(i,j);
		}
		printf("%d\n",g);
	}
	return 0;
}
