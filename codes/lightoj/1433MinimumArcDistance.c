#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int t,cs=0;
    double ox,oy,ax,ay,bx,by,th,r,a,b,c,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&ox,&oy,&ax,&ay,&bx,&by);
        a=sqrt(((ax-ox)*(ax-ox))+((ay-oy)*(ay-oy)));
        b=sqrt(((bx-ox)*(bx-ox))+((by-oy)*(by-oy)));
        c=sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
        th=acos(((a*a)+(b*b)-(c*c))/(2*a*b));
        r=a;
        s=r*th;
        printf("Case %d: %lf\n",++cs,s);
    }
    return 0;
}
