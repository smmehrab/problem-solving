#include<stdio.h>



int main()
{
    unsigned long long int s,n,i,t=1,r;

    scanf("%llu %llu",&s,&n);

    for(i=1;i<=n;i++)
    {
        t=t*10;
    }
    r=s%t;
    t=t/10;
    r=r/t;
    printf("%llu\n",r);

    return 0;
}
