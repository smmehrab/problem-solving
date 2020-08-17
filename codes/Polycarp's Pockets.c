#include<stdio.h>

int main()
{
    int n,a[110],i,j,k,c,l;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    c=1;l=-1;
    for(i=0;i<n;i++)
    {
        k=1;
        for(j=0;j<n;j++)
        {
            if(a[i]==a[j] && i!=j)
            {
                a[j]=l;
                l--;
                k++;
            }
        }
        a[i]=l;
        l--;
        if(k>c) c=k;
    }
    printf("%d\n",c);
    return 0;
}
