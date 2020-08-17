#include<stdio.h>

int main()
{
    int a[100],n,k,i,c;
    scanf("%d %d",&n,&k);

    for(i=0;i<n;i++)
    {
        if(i==n-1)
        {
            scanf("%d",&a[i]);
            break;
        }
        scanf("%d ",&a[i]);
    }

    c=0;

    for(i=0;i<n;i++)
    {
        if(a[i]>=a[k-1] && a[i]>0) {c++;}
    }
    printf("%d\n",c);
    return 0;
}
