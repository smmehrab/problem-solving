#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int x=gcd(a,b);
    printf("%d\n",x);
    return 0;
}
