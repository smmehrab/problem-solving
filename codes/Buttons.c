#include<stdio.h>

int main()
{
    int n,i=0,r=0;
    scanf("%d",&n);
    while(i<n)
    {
        if(i==0){r+=n-i;i++;continue;}
        r+=n-i+(i*(n-i-1));i++;
    }
    printf("%d\n",r);return 0;
}


