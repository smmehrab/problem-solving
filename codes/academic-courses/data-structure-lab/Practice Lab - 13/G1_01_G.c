#include<stdio.h>

int sumOfDigits(int n,int s)
{
    if(n) sumOfDigits(n/=10,s+=(n%10));
    else return s;
}

int main()
{
    int n;
    scanf("%d",&n);
    n=sumOfDigits(n,0);
    printf("%d\n",n);
    return 0;
}
