#include<stdio.h>
int main()
{
    int t,n,m,i,answer,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        answer=0;
        scanf("%d",&n);
        while(n--)
        {scanf("%d",&m); if(m>=0) answer+=m;}
        printf("Case %d: %d\n",++cs,answer);
    }
    return 0;
}
