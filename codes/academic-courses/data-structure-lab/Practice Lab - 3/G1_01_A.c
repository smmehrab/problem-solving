#include<stdio.h>
int main()
{
    int i,t,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        n*=567;
        n/=9;
        n+=7492;
        n*=235;
        n/=47;
        n-=498;
        n=n%100;
        n=n/10;
        if(n<0)
        {
            n*=(-1);
        }
        printf("%d\n",n);
    }
    return 0;




}
