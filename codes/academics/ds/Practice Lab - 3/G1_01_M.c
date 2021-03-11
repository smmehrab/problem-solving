#include<stdio.h>

int main()
{
    int t,n,k,p,i,j,x;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        scanf("%d %d %d",&n,&k,&p);
        x=k;
        for(i=0;i<p;i++)
        {
            x++;
            if(x>n) x-=n;
        }
        printf("Case %d: %d\n",j+1,x);
    }
    return 0;
}
