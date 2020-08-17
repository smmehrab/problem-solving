#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i,j,k,a[50],b[50],n,l,s;

    for(i=0;i<t;i++)
    {
        k=1;
        s=0;
        scanf("%d %d",&n,&l);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            s+=a[j];
        }
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[j]);
            if(b[j]<a[j]) k=-1;
        }
        if(s>l) k=-1;

        if(k==-1) printf("Case %d: No\n",i+1);
        else printf("Case %d: Yes\n",i+1);
    }
    return 0;
}
