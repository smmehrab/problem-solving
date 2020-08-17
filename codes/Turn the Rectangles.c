#include<stdio.h>
int main()
{
    unsigned long long int n;
    scanf("%llu",&n);
    unsigned long long int i,j,w[100000],h[100000],c=1;
    for(i=0;i<n;i++)
    {
        scanf("%llu %llu",&w[i],&h[i]);
        if(w[i]>h[i])
        {
            j=h[i];
            h[i]=w[i];
            w[i]=j;
        }

        if(i!=0)
        {
            if(h[i-1]<h[i])
            {
                if(h[i-1]<w[i]) c=0;
                else h[i]=w[i];
            }
        }

    }
    if(c==0) printf("NO\n");
    else printf("YES\n");

    return 0;
}
