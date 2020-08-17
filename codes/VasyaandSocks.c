#include<stdio.h>

int main()
{

    int n,m;
    scanf("%d %d",&n,&m);

    int nw=0,rnw;
    int x=n;

    while((x/m)!=0 && (m<=n))
    {
        rnw=x%m;
        nw=nw+(x/m);
        x=(x/m)+rnw;
    }

    n=n+nw;

    printf("%d\n",n);
    return 0;



}
