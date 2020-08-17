#include<stdio.h>

int main()
{
    long long int n,m,a;
    long long int i,j,r;

    scanf("%lld %lld %lld",&n,&m,&a);
    i=n%a; j=m%a;
    if(i!=0){
    i=((n/a)+1);
    }
    else
    {
        i= (n/a);

    }
    if(j!=0){
    j=((m/a)+1);
    }
    else
    {

        j= (m/a);
    }
    r=i*j;

    printf("%lld\n",r);
    return 0;


}
