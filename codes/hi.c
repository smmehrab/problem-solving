#include<stdio.h>

int main()
{
    int n,t;
    //scanf("%d",&t);
    int j;
    for(n=1;n<=100;n++)
    {
    //scanf("%d",&n);

    int i,onoff=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            onoff=!onoff;
        }
    }

        if(onoff==1) {printf("%d yes\n",n);}
        if(onoff==0) {printf("%d no\n",n);}
    }
        return 0;
}
