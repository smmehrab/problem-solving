#include<stdio.h>

void printOdd(int *a,int *n)
{
    int *p,*q;
    p=a;
    q=&n;
    if(*q==0) return 0;
    else if((*p)%2==1) printf("%d\n",(*p));
    *q--;

    printOdd(++p,q);
}


int main()
{
    int a[100000]={0},n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    printOdd(a,&n);
}
