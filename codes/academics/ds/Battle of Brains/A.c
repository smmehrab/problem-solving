#include<stdio.h>

int main()
{
    int t,n,a,b,c,d,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
        p=a+b+c+d;
        if(p>(n/2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
