#include<stdio.h>

int searchNumber(int *ar, int len, int num)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(*ar+i==num) return 1;
    }
    return 0;
}

int main()
{
    int a[100000],b,i,n,num;
    int* p;
    p=a;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&*(p+i));
    scanf("%d",&num);
    b=searchNumber(a,n,num);
    if(b==1) printf("Found\n");
    else printf("Not found\n");

    return 0;
}
