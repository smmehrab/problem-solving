#include<stdio.h>

int main()
{
    int t,m,n,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);

        k=0;
        j=m;
        while(j%5==0 && m!=0)
        {j/=5;k++;}
        m=k;

        k=0;
        j=n;
        while(j%5==0 && n!=0)
        {j/=5;k++;}
        n=k;

        printf("%d\n",n-m);
    }
    return 0;
}
