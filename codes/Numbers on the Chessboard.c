#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,q,x,y,i,j,k,a,b,c,r,answer;
    scanf("%lld %lld",&n,&q);
    while(q--)
    {
        r=0;
        scanf("%lld %lld",&x,&y);
        if((x+y)%2==0) r+=ceil(((x-1)*n)/2.00)+ceil(y/2.00);
        else r+=ceil((n*n)/2.00)+(((x-1)*n)/2)+ceil(y/2.00);
        printf("%lld\n",r);
    }
    return 0;
}













