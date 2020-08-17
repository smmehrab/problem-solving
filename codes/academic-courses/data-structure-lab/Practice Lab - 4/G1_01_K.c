#include<stdio.h>

int main()
{
    int a,b,n,x[100100]={0},i,y,z[100100]={0};
    scanf("%d %d",&a,&b);
    n=a+b+1;
    y=n;
    x[n]=1;
    y--;
    if(a<=b)
    {
        for(i=0;i<a;i++)
        {
            x[y]=1;
            y--;
        }
        for(i=0;i<b;i++)
        {
            z[y]=1;
            y--;
        }
    }
    else
    {
        for(i=0;i<b;i++)
        {
            z[y]=1;
            y--;
        }
        for(i=0;i<a;i++)
        {
            x[y]=1;
            y--;
        }
    }
    int c=0;
    for(i=0;i<=n;i++)
    {
        if(x[i]==1) {printf("%d ",i);c++;}
    }
    for(i=0;i<=n;i++)
    {

        if(z[n-i]==1)
        {

                printf("%d ",n-i);c++;
        }
    }
    printf("\n");
    return 0;
}
