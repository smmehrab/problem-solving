#include<stdio.h>

int main()
{
    int n,k,a[100],i;

    scanf("%d %d\n",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    i=0; int c=0;
    while(i<n)
    {
        if(a[i]>=a[k-1]&&a[i]>0)
        {
            c++;
        }
        i++;
    }
    printf("%d\n",c);
    return 0;

}
