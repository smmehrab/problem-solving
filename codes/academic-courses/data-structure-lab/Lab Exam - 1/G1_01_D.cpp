#include<stdio.h>
#include<math.h>
int main()
{
    int i=0;
    double a,b,c,x1,x2,b_square,four_ac,d,two_a,a1,a2;
    scanf("%lf %lf %lf",&a,&b,&c);
    b_square=b*b;
    four_ac=4*a*c;
    two_a=2*a;
    d=b_square-four_ac;
    if(d<0)
    {
        i=1;
        d*=(-1);
    }

    d=sqrt(d);
    a1=(-b/two_a);
    a2=(d/two_a);


    if(i)
    {
        if(a1==0)
        {
            if(a2<0) printf("%.2lfi +%.2lfi\n",a2,-a2);
            else printf("%.2lfi +%.2lfi\n",-a2,a2);
        }
        else if(a2<0) printf("%.2lf%.2lfi %.2lf+%.2lfi\n",a1,a2,a1,-a2);
        else printf("%.2lf%.2lfi %.2lf+%.2lfi\n",a1,-a2,a1,a2);
    }

    else
    {
        x1=a1-a2;
        x2=a1+a2;
        if(x1==x2) printf("%.2lf\n",x1);
        else if(x1<x2) printf("%.2lf %.2lf\n",x1,x2);
        else printf("%.2lf %.2lf\n",x2,x1);
    }

    return 0;
}
