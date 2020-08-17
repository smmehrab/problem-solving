#include<stdio.h>

int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);

    if(a<0 && b<0)
    {
        double product = a*b;
        printf("%lf\n",product);

    }
    else if(a>=0 && b>=0)
    {
        double sum = a+b;
        printf("%lf\n",sum);
    }
    else if(a<0 && b>=0)
    {
        a=a*(-1.00);
        double sum = a+b;
        printf("%lf\n",sum);
    }
    else if(a>=0 && b<0)
    {
        b=b*(-1.00);
        double sum= a+b;
        printf("%lf\n",sum);

    }

}
