#include<stdio.h>
unsigned long long int gcd(unsigned long long int x,unsigned long long int y)
{
    if(y==0) return x;
    else return gcd(y,x%y);
}
int main()
{
    unsigned long long int a,b,x,y,gc;
    scanf("%llu %llu %llu %llu",&a,&b,&x,&y);
    gc=gcd(x,y);
    x/=gc;
    y/=gc;
    x=(a/x);
    y=(b/y);
    if(x>y) x=y;
    printf("%llu\n",x);
    return 0;
}
