#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int t,r,ed;
    double ar,pi=acos(-1.0),a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d", &r);
        ed=((r*r)+(r*r))/4;
        ar=((1/4)*pi*ed)-((1/2)*sqrt(ed)*sqrt(ed));

        a=((1/2)*pi*r*r) - ar;
        printf("%lf\n", a);

    }
    return 0;
}