#include<stdio.h>

void reverseArray(float *ar, int len)
{
    int i; float t;
    for(i=0;i<len/2;i++)
    {
        t=*(ar+i);
        *(ar+i)=*(ar+(len-1-i));
        *(ar+(len-1-i))=t;
    }
}

int main()
{
    float a[100000],b;
    int i,n;
    float* p;
    scanf("%d",&n);
    p=a;
    for(i=0;i<n;i++) scanf("%f",&*(p+i));
    reverseArray(a,n);
    for(i=0;i<n;i++) printf("%f\n",*(p+i));

    return 0;
}

