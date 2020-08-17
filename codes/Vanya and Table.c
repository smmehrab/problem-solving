#include<stdio.h>

int main()
{
    int n,x1,y1,x2,y2,s=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        s+=(x2-x1+1)*(y2-y1+1);
    }
    printf("%d\n",s);
    return 0;
}
