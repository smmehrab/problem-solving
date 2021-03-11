#include<stdio.h>

void reverseArray(int a[], int l, int r)
{
    if (l < r)
    {
        a[l]^=a[r]^=a[l]^=a[r];
        reverseArray(a,l+1,r-1);
    }
}

int main()
{
    int a[100000],i,n;

    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    reverseArray(a,0,n-1);
    for(i=0;i<n;i++) printf("%d\n",a[i]);
    return 0;
}
