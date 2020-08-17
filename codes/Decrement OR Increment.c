#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    if(n%4) n--;
    else n++;
    printf("%d\n",n);
    return 0;
}
