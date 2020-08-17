#include<stdio.h>

int main()
{
    int n,k,x,y,c;
    scanf("%d",&n);
    scanf("%d",&k);
    scanf("%d",&x);
    scanf("%d",&y);

    if(n<=k)
    {
        c=x*n;

        printf("%d\n",c);
    }
    else
    {
        n=n-k;
        c=x*k;
        c+=y*n;

        printf("%d\n",c);

    }
    return 0;
}
