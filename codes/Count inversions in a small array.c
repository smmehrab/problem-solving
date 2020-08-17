#include<stdio.h>

int main()
{
    int n,i,j,k,l,c;
    long long int a[2000];
    while(1)
    {
        scanf("%d",&n);
        if(n)
        {
            for(i=0;i<n;i++) scanf("%lld",&a[i]);
        }
        else break;
        c=0;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(a[i]>a[j]) c++;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
