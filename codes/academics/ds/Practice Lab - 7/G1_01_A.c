#include<stdio.h>

float maxArray(float *ar, int len)
{
    int i; float max=-99999.0;
    for(i=0;i<len;i++)
    {
        if(*ar>max) max=*ar;
        ar+=4;
    }
    return max;
}

int main()
{
    float a[100000],b;
    int i,n;
    float* p;
    scanf("%d",&n);
    p=a;
    for(i=0;i<n;i++)
    {
        scanf("%f",&(*p));
        p+=4;
    }
    b=maxArray(a,n);
    printf("%f",b);

    return 0;
}
