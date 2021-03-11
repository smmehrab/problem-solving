#include<stdio.h>

int prime(int n,int i)
{
    if(n==1) return 0;
    else if(n==2 || n==3) return 1;
    else if(n%i==0) return 0;
    else if(i>(n/2)) return 1;
    else return prime(n,++i);
}

int main()
{
    int a;
    scanf("%d",&a);
    if(prime(a,2)==0) printf("Not Prime\n");
    else printf("Prime\n");
    return 0;
}

