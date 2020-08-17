#include<stdio.h>

int findNum(int a[], int l, int r, int m)
{
    if (l < r)
    {
        if(a[l]==m) return l;
        if(a[r]==m) return r;
        findNum(a,l+1,r-1,m);
    }
    else return -1;
}

int main()
{
    int a[100000],i,n,m;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    n=findNum(a,0,n-1,m);
    if(n!=-1) printf("%d\n",n);
    else printf("Not found\n");
    return 0;
}
