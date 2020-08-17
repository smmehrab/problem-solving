#include<stdio.h>

int main()
{
    unsigned long long int r=1,n,i;
    scanf("%llu",&n);

    if(n==0)
    {
        printf("%llu\n",r);
        return 0;
    }

    for(i=2;i<=n;i++)
    {
        r=r*i;
        if(r/10007!=0)
        {
            r=r%10007;
        }

    }



    printf("%llu\n",r);
    return 0;

}
