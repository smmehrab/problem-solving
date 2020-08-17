
#include<stdio.h>

void swapArray(double *ar, double *br, int len)
{
    int i; double t;
    for(i=0;i<len;i++)
    {
        t=*(ar+i);
        *(ar+i)=*(br+i);
        *(br+i)=t;
    }
}

int main()
{
    double a[100000],b[100000];
    int i,n;
    double *p,*q;
    scanf("%d",&n);
    p=a;q=b;
    for(i=0;i<n;i++) scanf("%lf",&*(p+i));
    for(i=0;i<n;i++) scanf("%lf",&*(q+i));
    swapArray(a,b,n);
    for(i=0;i<n;i++) printf("%lf\n",*(p+i));
    for(i=0;i<n;i++) printf("%lf\n",*(q+i));

    return 0;
}

