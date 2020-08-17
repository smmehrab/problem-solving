#include<stdio.h>
#include<math.h>

int main()
{
    unsigned long long int t,s,cs=0,nsq,r,c;
    scanf("%llu",&t);
    while(t--)
    {
        scanf("%llu",&s);
        nsq=floor(sqrt(s-1));
        s-=nsq*nsq;
        r=c=nsq+1;

        if(nsq%2==0)
        {
            if(s>=r) c-=s-r;
            else r=s;
        }

        else
        {
            if(s>=c) r-=s-c;
            else c=s;
        }
        printf("Case %llu: %llu %llu\n",++cs,c,r);
        nsq=r=c=s=0;
    }
    return 0;
}
