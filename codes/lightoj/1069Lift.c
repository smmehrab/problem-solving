#include<stdio.h>

int main()
{
    int n,m,t,cs=0,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        if(m>=n) r=(m*4)+19;
        else r=((n-m)+n)*4+19;
        printf("Case %d: %d\n",++cs,r);
    }
    return 0;
}
