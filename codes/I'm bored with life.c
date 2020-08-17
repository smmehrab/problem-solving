#include<stdio.h>
int main()
{
    long long int a,b,i;
    scanf("%lld %lld",&a,&b);
    if(a>b) a^=b^=a^=b;
    for(i=a-1;i>0;i--) a*=i;
    printf("%lld\n",a);
    return 0;
}
