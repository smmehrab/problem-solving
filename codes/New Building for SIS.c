#include<stdio.h>
typedef long long int ll;
ll abs(ll n)
{
    if(n<0) n*=(-1);
    return n;
}
int main()
{
    ll n,h,a,b,k,i,j,x,y,u,v,r;

    scanf("%lld %lld %lld %lld %lld",&n,&h,&a,&b,&k);

    while(k--)
    {
        scanf("%lld %lld %lld %lld",&x,&y,&u,&v);
        r=0;
        if(x==u) r+=abs(v-y);
        else
        {
            r+=abs(u-x);
            if(y>=a && y<=b)
            {
                r+=abs(v-y);
            }
            else if(y<a)
            {
                r+=(a-y)+abs(a-v);
            }
            else if(y>b)
            {
                r+=(y-b)+abs(v-b);
            }
        }
        printf("%lld\n",r);
    }
    return 0;
}
