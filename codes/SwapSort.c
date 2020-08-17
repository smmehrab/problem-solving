#include<stdio.h>

int main()
{
    long long int n,a[10000],x[10000],i,j,k=0,c=0,min,ind;
    scanf("%lld",&n);

    for(i=0;i<n;i++) scanf("%lld",&a[i]);

    for(i=0;i<n-1;i++)
    {
        min=a[i+1];
        ind=i+1;
        for(j=i+2;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                ind=j;
            }
        }
        if(min<a[i])
        {
            x[k]=i;
            x[k+1]=ind;
            k+=2;
            a[ind]=a[i];
            a[i]=min;
            c++;
        }
    }
    printf("%lld\n",c);
    for(i=0;i<k;i+=2)
    {
        printf("%lld %lld\n",x[i],x[i+1]);
    }
    return 0;
}
