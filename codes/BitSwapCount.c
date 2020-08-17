#include<stdio.h>
int getBitSwapCount(int x, int y)
{
    int c=0,z;

    for(z=x^y;z!=0;z&=z-1)
    {
        printf("%d ",z);
        c++;
    }


    return c;
}

int main()
{
    int x,y,r;
    scanf("%d %d",&x,&y);
    r=getBitSwapCount(x,y);
    printf("%d\n",r);
    return 0;
}
