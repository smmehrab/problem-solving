#include<stdio.h>
int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,area,t,cs=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
        dx =ax+cx-bx;
        dy =ay+cy-by;
        area=0.5*(((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax)));
        if(area<0) area*=-1;
        printf("Case %d: %d %d %d\n",++cs,dx,dy,area);
    }
    return 0;
}


