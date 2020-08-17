#include<stdio.h>

int main()
{

    int n,i;
    scanf("%d",&n);

    double a,o=0;
    for(i=0;i<n;i++)
    {
        scanf("%lf",&a);
        o=o+a;


    }

    o=(100.00*o)/(100.00*n);
    printf("%.13lf\n",o);
    return 0;

}
