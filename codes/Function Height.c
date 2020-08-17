#include<stdio.h>
int main()
{
    unsigned long long int n,k,r;
    scanf("%llu %llu",&n,&k);
    r=(k/n);
    if(k%n!=0) r++;
    printf("%llu\n",r);
    return 0;
}
