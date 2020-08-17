#include<stdio.h>

int main()
{
    int r,c,i,j,k,l,a[1000][1000];
    double ans;

    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++) scanf("%d",&a[i][j]);
    }
    for(i=0;i<c;i++)
    {
        ans=0;
        for(j=0;j<r;j++) ans+=a[j][i];
        ans/=r;
        printf("%.2lf",ans);
        if(i!=c-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
