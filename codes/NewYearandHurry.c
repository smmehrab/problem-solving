#include<stdio.h>

int main()
{

    int n,k;
    scanf("%d %d",&n,&k);

    k=240-k;
    int i=1,c=0,t=0;
    for(i=1;i<=n;i++)
    {
        t=t+(5*i);
        if(t<=k)
        {
            c++;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",c);
    return 0;
}
