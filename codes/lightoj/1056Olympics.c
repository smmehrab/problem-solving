#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,t,cs=0;
    double r,s,th;

    scanf("%d",&t);
    while(t--){
        scanf("%d : %d",&a,&b);
        r=sqrt((a*a)+(b*b))/2.00;
        th=acos(((2*r*r)-(b*b))/(2*r*r));
        s=r*th;
        r=200.00/(a+s);
        printf("Case %d: %lf %lf\n",++cs,(a*r),(b*r));
    }
    return 0;
}
