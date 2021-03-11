#include<stdio.h>

int ifPrime(int n,int i)
{
    if(n==1) return 0;
    else if(n==2 || n==3) return 1;
    else if(n%i==0) return 0;
    else if(i>(n/2)) return 1;
    else return ifPrime(n,++i);
}
void printPrime(int a,int b)
{
    if(a>b) return 0;
    else if(ifPrime(a,2)==1) printf("%d\n",a);
    printPrime(++a,b);
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printPrime(a,b);
}

