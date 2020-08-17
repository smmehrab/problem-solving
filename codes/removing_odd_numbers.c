#include<stdio.h>

void polynomial_series(int n)
{
    if(n>=0)
    {

        printf(" + x^%d ",n);return polynomial_series(n-1);

    }
}

int main()
{

    int n;
    scanf("%d",&n);

    polynomial_series(n);
    printf("\n");
    return 0;
}
