#include<stdio.h>

int main()
{
    int n,a[1000],i,s,r,j=0;

    while(1){

    r=0; s=0;

    scanf("%d",&n);
    j++;

    if(n==0)
    {
        return 0;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }

    s=s/n;

    for(i=0;i<n;i++)
    {
        if(a[i]>s) {r+=a[i]-s;}
    }
    printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,r);
    }
}
