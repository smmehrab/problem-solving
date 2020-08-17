#include<stdio.h>
int min(int a, int b, int c)
{
    if(a<=b)
    {
        if(a<=c)
        {
            return a;
        }
        else return c;
    }
    else
    {
        if(b<=c)
        {
            return b;
        }
        else return c;
    }

}


int main()
{
    while(1){
    int a,b,c,d,x,r;
    scanf("%d %d %d %d",&a,&b,&c,&d);

    x=min(a,c,d);

    r=(x*256);
    x=(a-x);
    if(x>b)
    {
        r+=(b*32);
    }
    else
    {
        r+=(x*32);
    }

    printf("%d\n",r);
    }
    return 0;


}
