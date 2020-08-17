#include<stdio.h>

int main()
{

    unsigned long long int n,k,i,j,a,b,r;

    scanf("%llu %llu",&n,&k);

    r=0;

    if(k>n && k<=(n+(n/2)))
    {
        r=n-(k-n)+1;
        r/=2;
    }

    else if(k>(n+(n/2)) && k<(2*n))
    {
        r=(2*n)-k+1;
        r/=2;
    }
    else if(k<=n)
    {
        if(k%2==0) r=(k/2)-1;
        else r=(k/2);
    }
    else r=0;

    printf("%llu\n",r);
    return 0;
}
