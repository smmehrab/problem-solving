#include<stdio.h>

int main()
{
    int n,p,k,i,j;
    scanf("%d %d %d",&n,&p,&k);

    for(i=k;i>0;i--)
    {
        if(i==k)
        {
            if(p-i==1) printf("%d ",p-i);
            else if((p-i)>1) printf("<< %d ",p-i);
        }
        else if(p-i>=1) printf("%d ",p-i);
    }

    printf("(%d) ",p);

    for(i=1;i<=k;i++)
    {
        if(i==k)
        {
            if(p+i==n) printf("%d ",p+i);
            else if((p+i)<n) printf("%d >>",p+i);
        }
        else if(p+i<=n) printf("%d ",p+i);
    }

    printf("\n");
    return 0;
}

