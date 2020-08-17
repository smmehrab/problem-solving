#include<stdio.h>

int main()
{
    int i,n=2,a=2,b=1;
    for(i=0;i<10;i++)
    {
        n^=(a^b);
        printf("%d\n",n);
    }
    return 0;
}
