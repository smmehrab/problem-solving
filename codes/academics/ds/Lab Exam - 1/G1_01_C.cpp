#include<stdio.h>

int main()
{
    unsigned long long int n,c=0;
    scanf("%llu",&n);
    
    while(n!=0)
    {
		n/=2;
		c++;
    }
	printf("%llu\n",c-1);
	return 0;

}
