#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int r=gcd(a,b);
    r=(a*b)/r;
    printf("%d\n",r);
    return 0;
}
