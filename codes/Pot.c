#include<stdio.h>

int pow(int a, int b)
{
    int i,j=1;
    for(i=0;i<b;i++)
    {
        j= j*a;
    }

    return j;

}


int main()
{
    int n,i,t,r,j,k;

    scanf("%d",&n);
    r=0;
    for(i=0;i<n;i++)
    {

        scanf("%d",&t);
        j=(t/10);
        k=(t%10);
        r+=pow(j,k);

    }
    printf("%d\n",r);
    return 0;

}
