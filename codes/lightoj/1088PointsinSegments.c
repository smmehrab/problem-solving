#include<stdio.h>
typedef long long int ll;
int main()
{
    ll n,q,N[300000],cs=0,t,i,j,k,a,b,l,r,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++) scanf("%lld",&N[i]);
        printf("Case %lld:\n",++cs);
        while(q--)
        {
            scanf("%lld %lld",&a,&b);
            l=0;
            r=(n-1);
            while(l<=r)
            {
                m=(l+r)/2;
                if(N[m]==a){l=m; break;}
                else if(N[m]<a) l=m+1;
                else r=m-1;
            }
            j=l;
            l=0;
            r=n-1;
            while(l<=r)
            {
                m=(l+r)/2;
                if(N[m]<=b) l=m+1;
                else r=m-1;
            }
            k=l;
            printf("%lld\n",k-j);
        }
    }
    return 0;
}
