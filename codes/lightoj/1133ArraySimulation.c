#include<stdio.h>

int main()
{
    long long int a[10000],k,l,s;
    int t,i,n,m,j,q;
    char b;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);


        for(j=0;j<n;j++)
			scanf("%lld", &a[j]);
        for(q=0;q<m;q++)
        {
            scanf(" %c",&b);
            if(b=='S')
            {
                scanf("%lld",&k);
                for(j=0;j<n;j++)
                {a[j]+=k;}
            }

            else if(b=='M')
            {
                scanf("%lld",&k);
                for(j=0;j<n;j++)
                {a[j]*=k;}
            }

            else if(b=='D')
            {
                scanf("%lld",&k);
                for(j=0;j<n;j++)
                {a[j]/=k;}
            }

            else if(b=='R')
            {
                for(j=0;j<(n/2);j++)
                {
                    k=a[n-1-j];
                    a[n-1-j]=a[j];
                    a[j]=k;
                }
            }

            else if(b=='P')
            {
                scanf("%lld %lld",&k,&l);
                s=a[k];
                a[k]=a[l];
                a[l]=s;
            }

        }

        printf("Case %d:\n",(i+1));
        for(j=0;j<n;j++)
        {
            if(j!=(n-1)) printf("%lld ",a[j]);
            else printf("%lld\n",a[j]);
        }
    }
    return 0;
}
