#include<stdio.h>

int main()
{

    int t,n,i,a[11],j;
    scanf("%d",&t);

    for(i=0;i<t;i++)
    {
        scanf("%d ",&n);
        for(j=0;j<n;j++)
        {
            if(j!=n-1) scanf("%d ",&a[j]);
            else scanf("%d",&a[j]);
        }
        j=(n/2);
        printf("Case %d: %d\n",i+1,a[j]);
    }
    return 0;
}
