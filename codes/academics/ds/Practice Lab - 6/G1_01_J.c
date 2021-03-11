#include<stdio.h>

int main()
{
    int n,a[100][100],mid,i,j,k,l,ans=0,t;
    scanf("%d",&n);
    mid=n/2;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&t);
            if(i==mid || j==mid) ans+=t;
            else if(i==0 && j<mid) ans+=t;
            else if(j==0 && i>mid) ans+=t;
            else if(j==n-1 && i<mid) ans+=t;
            else if(i==n-1 && j>mid) ans+=t;
        }
    }
    printf("%d\n",ans);
    return 0;
}
