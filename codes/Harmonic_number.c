#include<stdio.h>
int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        double h=0.00;
        scanf("%d",&n);
        for(i=1;i<=n;i++) h+=(1.00/i);
        printf("Case %d: %.10lf\n",++cs,h);
    }
    return 0;
}
