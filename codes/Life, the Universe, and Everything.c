#include<stdio.h>
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        if(t==42) break;
        else printf("%d\n",t);
    }
    return 0;
}
