#include<stdio.h>

void reversePrint(int n)
{
    if(n>=0) printf("%d",n);

    if(n==0) printf("\n");
    else if(n>0) printf(" ");

    reversePrint(--n);
}

int main()
{
    int n;
    scanf("%d",&n);
    reversePrint(n);
    return 0;
}
