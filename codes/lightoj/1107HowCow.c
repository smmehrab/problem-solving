#include<stdio.h>

int main()
{
    int x1,y1,x2,y2,m,t,x,y,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&m);
        printf("Case %d:\n",++cs);
        while(m--)
        {
            scanf("%d %d",&x,&y);
            if(x>x1 && x<x2 && y>y1 && y<y2) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
