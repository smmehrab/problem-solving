#include<stdio.h>

int main()
{
    int n,a[1100],h[1100]={0},i,j,k;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }


    for(i=1;i<=n;i++)
    {
        j=i;
        for(k=1;k<=n;k++) h[k]=0;

        while(h[j]==0)
        {
            h[j]++;
            j=a[j];
        }
        if(i==n) printf("%d",j);
        else printf("%d ",j);
    }

    printf("\n");
    return 0;
}
