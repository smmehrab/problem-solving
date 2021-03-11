#include<stdio.h>

int findLarge(int a[], int l, int r, int m)
{
    if (l < r)
    {
        if(a[l]>m) m=a[l];
        if(a[r]>m) m=a[r];
        findLarge(a,l+1,r-1,m);
    }
    else return m;
}

int main()
{
    int a[100000],i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    n=findLarge(a,0,n-1,a[0]);
    printf("%d\n",n);
    return 0;
}
